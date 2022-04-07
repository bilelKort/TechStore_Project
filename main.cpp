#include "mainwindow.h"

#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QApplication>
#include <QTranslator>
#include <QInputDialog>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator t ;
    QStringList languages ;
    languages <<"anglais"<<"french" ;
    QString lang= QInputDialog::getItem(NULL,"Select Languages","Language",languages) ;
    if(lang=="anglais")
    {
        t.load(":/engg.qm") ;
    }
    else
    {
        t.load(":/french.qm") ;
    }

    /*else
    {
    t.load(":/eng.qm") ;
    }*/
   if(lang!="english")
   {
       a.installTranslator(&t) ;
   }



    MainWindow w;
    w.show();
    return a.exec();
}





