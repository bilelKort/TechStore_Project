#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include<QtSql>



class connection
{
 public:
    connection();
    bool createconnection();
};
#endif // CONNECTION_H
