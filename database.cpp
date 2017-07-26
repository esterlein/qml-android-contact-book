#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include "database.h"

DataBase::DataBase(QObject* parent)
    : QObject(parent)
    , b_connected(false)
    , port(3306)
    , host("192.168.1.33")
    , database("base.db")
    , username("root")
    , password("123")
{}

void DataBase::connectToDatabase()
{
    QSqlDatabase sqlDatabase = QSqlDatabase::addDatabase("database");

    sqlDatabase.setHostName(host);
    sqlDatabase.setPort(port);
    sqlDatabase.setDatabaseName(database);
    sqlDatabase.setUserName(username);
    sqlDatabase.setPassword(password);

    if(sqlDatabase.open()){
        b_connected = true;
    }
}

const bool& DataBase::connected() const
{
    return b_connected;
}

void DataBase::sendQuery(int query)
{
    if(b_connected){
        QString query_str;
        switch(query){
        case ZERO:
            query_str = "one";
            break;
        case ONE:
            query_str = "two";
            break;
        default:
            qDebug() << "unknown query";
            break;
        }
        QSqlQuery query(query_str);

    }
    else{
        qDebug() << "no connection to send query";
    }
}
