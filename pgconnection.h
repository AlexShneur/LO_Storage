#ifndef PGCONNECTION_H
#define PGCONNECTION_H

#include <memory>
#include <libpq-fe.h>

class PGConnection
{
public:
    PGConnection(std::string _dbhost,
                 int         _dbport,
                 std::string _dbname,
                 std::string _dbuser,
                 std::string _dbpass);
    std::shared_ptr<PGconn> connection() const;

private:
    std::string m_dbhost = "localhost";
    int         m_dbport = 5433;
    std::string m_dbname = "postgres";
    std::string m_dbuser = "postgres";
    std::string m_dbpass = "root";

    std::shared_ptr<PGconn>  m_connection;

};

#endif // PGCONNECTION_H
