#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <QString>
#include <QVariant>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
class sponsor
{
public:
    sponsor();
    sponsor(QString ,QString ,QString ,QString ,int,int ,QString);
    bool ajouter_sponsor(sponsor e);
    QSqlQueryModel * read();
    bool update(sponsor e);
   bool supprimer_sponsor(QString id);
private:
    QString id;
    QString cin;
    QString nom;
    QString email;
    QVariant nbretoile ;
    QVariant tel ;
        QString date;



};

#endif // EMPLOYE_H
