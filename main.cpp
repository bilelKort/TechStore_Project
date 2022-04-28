#include "widget.h"
#include "connection.h"
#include <QApplication>
#include <QMessageBox>
#include <QtSql>
#include "windowemploye.h"
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QApplication>
#include <QTranslator>
#include <QInputDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    connection c;


    bool test=c.createconnection();
    if(test)
    {
        w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

   QTranslator t ;
    QStringList languages ;
    languages <<"anglais"<<"french" ;
    QString lang= QInputDialog::getItem(NULL,"Select Languages","Language",languages) ;
    if(lang=="anglais")
    {
        t.load(":/enggg.qm") ;
    }
    /*else
    {
        t.load(":/french.qm") ;
    }*/


   if(lang!="english")
   {
       a.installTranslator(&t) ;
   }

   /*else
   {
   t.load(":/eng.qm") ;
   }*/

    w.show();

    return a.exec();
}



