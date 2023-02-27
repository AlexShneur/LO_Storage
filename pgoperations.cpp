#include "pgoperations.h"
#include "libpq/libpq-fs.h"

#define BUFSIZE         1024

PGOperations::PGOperations()
{
    lastError.clear();
}

Oid PGOperations::ImportFile(const std::shared_ptr<PGconn> conn, QFile& file)
{
    auto lobjId = lo_creat(conn.get(), INV_READ | INV_WRITE);
    if (lobjId == 0)
        lastError = "Cannot create large object";

    PQexec(conn.get(), "BEGIN");
    auto lobj_fd = lo_open(conn.get(), lobjId, INV_WRITE);

    auto bytesWritten = 0;
    auto bytesRead = 0;
    char buf[BUFSIZE];
    auto fsize = file.size();
    do
    {
        bytesRead = file.read(buf,BUFSIZE);
        bytesWritten += lo_write(conn.get(), lobj_fd, buf, bytesRead);
    }
    while (bytesRead>0);

    if (bytesWritten!=fsize)
        lastError = "Error while importing file";

    PQexec(conn.get(), "END");

    lo_close(conn.get(), lobj_fd);

    return lobjId;
}

void PGOperations::ExportFile(const std::shared_ptr<PGconn> conn, Oid lobjId, const QString& fileName)
{
    PQexec(conn.get(), "BEGIN");
    auto lobj_fd = lo_open(conn.get(), lobjId, INV_READ);
    if (lobj_fd < 0)
        lastError = "Cannot open large object";

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly))
    {
        lastError = "Cannot open file for writing";
    }
    else
    {
        auto bytesWritten = 0;
        auto bytesRead = 0;
        char buf[BUFSIZE];
        do
        {
            bytesRead = lo_read(conn.get(), lobj_fd, buf, BUFSIZE);
            bytesWritten += file.write(buf,bytesRead);
        }
        while (bytesRead>0);
    }

    PQexec(conn.get(), "END");

    lo_close(conn.get(), lobj_fd);

    return;
}

int PGOperations::ExecuteQuery(const std::shared_ptr<PGconn> conn, std::string query)
{
    auto result = 0;
    auto res = PQexec(conn.get(), query.c_str());
    if (PQresultStatus(res) != PGRES_COMMAND_OK)
    {
        lastError = getLastError(res);
        result = 1;
    }
    else
    {
        lastError = mPG_Errors.begin()->second; //код успешного выполнения - 00000
    }
    PQclear(res);
    res = NULL;

    return result;
}

int PGOperations::ExecuteQueryReturnValues(const std::shared_ptr<PGconn> conn, std::string query,
                                           std::vector<std::string> &values)
{
    auto result = 0;
    auto res = PQexec(conn.get(), query.c_str());

    if (PQresultStatus(res) != PGRES_TUPLES_OK)
    {
        lastError = getLastError(res);
        result = 1;
    }
    else
    {
        auto nrows = PQntuples(res);
        auto ncols = PQnfields(res);
        for(auto i = 0; i < nrows; i++)
        {
            for(auto j = 0; j < ncols; j++)
            {
                values.push_back(std::string(PQgetvalue(res, i, j)));
            }
        }
        lastError = mPG_Errors.begin()->second; //код успешного выполнения - 00000
    }
    PQclear(res);
    res = NULL;

    return result;
}

int PGOperations::ExecuteQueryWithParams(const std::shared_ptr<PGconn> conn, std::string query,
                           void* params)
{
     auto result = 0;
     auto res = PQexecParams(conn.get(), query.c_str(), PARAMS_COUNT-1, NULL, (const char**)params,
                                   NULL, NULL, 0);
     if (PQresultStatus(res) != PGRES_COMMAND_OK)
     {
         lastError = getLastError(res);
         result = 1;
     }
     else
     {
         lastError = mPG_Errors.begin()->second; //код успешного выполнения - 00000
     }
     PQclear(res);
     res = NULL;

     return result;
}

std::string PGOperations::GetLastError()
{
    auto err = lastError;
    if (lastError==mPG_Errors.begin()->second) //код успешного выполнения - 00000)
    {
        err.clear();
    }
    lastError.clear();
    return err;
};

std::string PGOperations::getLastError(PGresult* res)
{
    auto err = std::string(PQresultErrorField(res, PG_DIAG_SQLSTATE));
    auto foundErrorIT = mPG_Errors.find(err);
    if (foundErrorIT!=mPG_Errors.end())
    {
        err = foundErrorIT->second;
    }
    else
    {
        err = "Unknown";
    }
    return err;
}
