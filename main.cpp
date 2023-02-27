#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

#include <iostream>
#include <QTextCodec>
#include <QTextStream>

QTextStream cout(stdout);

//void testConnection(std::shared_ptr<PGBackend> pgbackend)
//{
//    //получаем свободное соединение
//    auto conn = pgbackend->connection();

//    //std::string demo = "SELECT max(id) FROM demo; " ;
//    std::string demo = "CREATE DATABASE demo" ;
//    PQsendQuery( conn->connection().get(), demo.c_str() );

//    while ( auto res_ = PQgetResult( conn->connection().get()) ) {
//        if (PQresultStatus(res_) == PGRES_TUPLES_OK && PQntuples(res_)) {
//            //auto ID = PQgetvalue (res_ ,0, 0);
//            cout<< QString("DB created.")<<Qt::flush;
//        }

//        if (PQresultStatus(res_) == PGRES_FATAL_ERROR){
//            cout<< QString(PQresultErrorMessage(res_))<<Qt::flush;
//        }

//        PQclear( res_ );
//    }
//}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    cout.setCodec(QTextCodec::codecForName("windows-1251"));

    //auto pgbackend = std::make_shared<PGBackend>();
    //testConnection(pgbackend);



//    std::vector<std::shared_ptr<std::thread>> vec;

//    for ( size_t i = 0; i< 50 ; ++i ){

//        vec.push_back(std::make_shared<std::thread>(std::thread(testConnection, pgbackend)));
//    }

//    for(auto &i : vec) {
//        i.get()->join();
//    }





    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "LO_Storage_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    MainWindow w;
    w.show();
    return a.exec();
}
