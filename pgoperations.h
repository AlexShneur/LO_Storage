#ifndef PGOPERATIONS_H
#define PGOPERATIONS_H

#include <memory>
#include <string>
#include <libpq-fe.h>
#include <map>
#include <QFile>
#include <QObject>

#define PARAMS_COUNT            5
#define BUFSIZE                 1048576     //1 Мб
#define BUFSIZE_SMALL           65536       //64 Кб

class PGOperations: public QObject
{
Q_OBJECT
public:
    PGOperations(QObject *parent=0);
    int ExecuteQuery(const std::shared_ptr<PGconn> conn, std::string query);
    int ExecuteQueryReturnValues(const std::shared_ptr<PGconn> conn, std::string query,
                                 std::vector<std::string>& values);
    int ExecuteQueryWithParams(const std::shared_ptr<PGconn> conn, std::string query,
                               void* params);

    Oid ImportFile(const std::shared_ptr<PGconn> conn, QFile& file);
    void ExportFile(const std::shared_ptr<PGconn> conn, Oid lobjId, const QString& fileName);

    std::string GetLastError();

Q_SIGNAL void inProgress(int progr);

private:
    std::string getLastError(PGresult *res);
    std::string lastError = "";

    //здесь перечислены не все коды ошибок PostgeSQL, а лишь часто встречающиеся
    const std::map<std::string,std::string> mPG_Errors =
    {
        {"00000", "successful_completion"},
        {"42P04", "duplicate_database"},
        {"42P07", "duplicate_table"},
        {"42601", "syntax_error"},
    };

};
#endif // PGOPERATIONS_H
