#include "pgconnection.h"

PGConnection::PGConnection(std::string _dbhost,
                           int         _dbport,
                           std::string _dbname,
                           std::string _dbuser,
                           std::string _dbpass)
{
    m_dbhost = _dbhost;
    m_dbport = _dbport;
    m_dbname = _dbname;
    m_dbuser = _dbuser;
    m_dbpass = _dbpass;

    m_connection.reset( PQsetdbLogin(m_dbhost.c_str(),
                                     std::to_string(m_dbport).c_str(),
                                     nullptr,
                                     nullptr,
                                     m_dbname.c_str(),
                                     m_dbuser.c_str(),
                                     m_dbpass.c_str()),
                        &PQfinish );

    if (PQstatus( m_connection.get() ) != CONNECTION_OK &&
            PQsetnonblocking(m_connection.get(), 1) != 0 )
    {
       throw std::runtime_error( PQerrorMessage( m_connection.get() ) );
    }

}


std::shared_ptr<PGconn> PGConnection::connection() const
{
    return m_connection;
}
