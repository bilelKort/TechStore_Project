#include "connection.h"
#include<QDebug>

connection::connection(){

}

bool connection::createconnection(){
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("test");
    db.setUserName("kort");
    db.setPassword("esprit18");

    if(db.open())
        test=true;

    qDebug() << "ERROR = " << db.lastError();

    return test;
}
