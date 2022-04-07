#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <QString>
#include <QVariant>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
class sponsor
{
    //les fonctions
public:
    sponsor();
    sponsor(QString ,QString ,QString ,QString ,int,int ,QString);
    bool ajouter_sponsor(sponsor e);
    QSqlQueryModel * read();
    bool update(sponsor e);
    bool supprimer_sponsor(QString id);
    QSqlQueryModel* affichertri ();
    QSqlQueryModel* affichertrii ();
    QSqlQueryModel *rechercher(QString);
    QSqlQueryModel *rechercherc(QString);
    QSqlQueryModel *rechercher1(QString);
    QSqlQueryModel *rechercher2(QString);
    QSqlQueryModel *rechercher3(QString);
    QSqlQueryModel *rechercher4(QString);
    void on_pdf_clicked();


//les attributs
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
