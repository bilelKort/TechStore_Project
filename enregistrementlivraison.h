#ifndef ENREGISTREMENTLIVRAISON_H
#define ENREGISTREMENTLIVRAISON_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>


class enregistrementLivraison
{
public:
    enregistrementLivraison();//constructeur par defaut
     enregistrementLivraison(QString);//constructeur parametre
     QString get_total();


          bool ajouter();
          QSqlQueryModel * afficher();

private:

QString total;
};



#endif // ENREGISTREMENTLIVRAISON_H
