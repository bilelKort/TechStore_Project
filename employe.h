#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <QString>
#include <QVariant>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

class employe
{
public:
    employe();
    employe(QString ,QString ,QString ,int ,QString ,int ,QString ,int );
    bool ajouter_employe(employe e);
    QSqlQueryModel * read();
    QSqlQueryModel * read2();
    QSqlQueryModel * read3();
    QSqlQueryModel * read4(QString cin) ;


    bool update(employe e);
   bool supprimer_employe(QString cin);
   QSqlQueryModel *rechercher(QString);
   QSqlQueryModel *rechercher2(QString);



private:
    QString cin;
        QString datenaissance;

        QVariant salaire ;
        QVariant experience ;
        QVariant nb_absence ;
        QString email;
        QString password ;
        QString nom ;

};

#endif // EMPLOYE_H
