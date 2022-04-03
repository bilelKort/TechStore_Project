#ifndef PRODUIT_H
#define PRODUIT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class produit
{
private:
     int identifiant,quantite,prix;
     QString nom,categorie;

public:
    produit();
    produit(int,QString,QString ,int,int);
    int getIdentifiant();
    QString getNom();
    QString getCategorie();
    int getQuantite();
    int getPrix();
    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(int  );
    bool modifier(int);//**//

};

#endif // PRODUIT_H
