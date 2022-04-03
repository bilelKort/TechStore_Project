#include "produit.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QPrinter>
#include <QPrintDialog>
#include <QTextStream>
#include <QPainter>
#include <QTextStream>
#include "qcustomplot.h"

produit::produit()
{
    this->identifiant=0;
    this->nom="";
    this->categorie="";
    this->quantite=0;
    this->prix=0;
}

produit::produit(int identifiant,QString nom,QString categorie,int quantite,int prix)
{
    this->identifiant=identifiant;
    this->nom=nom;
    this->categorie=categorie;
    this->quantite=quantite;
    this->prix=prix;
}

int produit:: getIdentifiant()
{
   return this->identifiant;
}
QString produit:: getNom()
{
   return this->nom;
}
QString produit:: getCategorie()
{
return this->categorie;
}
int produit:: getQuantite()
{
  return this->quantite;
}

int produit:: getPrix()
{
    return this->prix;
}
bool produit:: ajouter()
{
    QSqlQuery query;
    QString res=QString ::number(identifiant);//res=sid//
    QString resQ=QString ::number(quantite);
    QString resP=QString ::number(prix);
    query.prepare("INSERT INTO  PRODUIT(IDENTIFIANT,NOM,CATEGORIE,QUANTITE,PRIX)"
                  "VALUES(:identifiant,:nom ,:categorie,:quantite, :prix)");

 query.bindValue(":identifiant",res);
 query.bindValue(":nom",nom);
 query.bindValue(":categorie",categorie);
 query.bindValue(":quantite",resQ);
 query.bindValue(":prix",resP);


    return query.exec();

}

QSqlQueryModel * produit:: afficher()
{

QSqlQueryModel * model =new QSqlQueryModel();
model->setQuery ("select * from produit");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("IDENTIFIANT"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("CATEGORIE"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("QUANTITE"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("PRIX"));

return model;

}


bool  produit::supprimer(int ide)
{
  QSqlQuery query;
  QString res=QString::number(ide);
  query.prepare("Delete from produit where IDENTIFIANT= :identifiant");
  query.bindValue(":identifiant",res);

    return query.exec();

}

bool produit::modifier(int idd)
{
QSqlQuery query,rech;
QString res= QString::number(idd);
query.prepare("Update produit set  NOM = :nom , CATEGORIE = :categorie , QUANTITE = :quantite ,PRIX= :prix where IDENTIFIANT = :idd ");
query.bindValue(":idd",res);
query.bindValue(":nom",nom);
query.bindValue(":categorie",categorie);
query.bindValue(":quantite",quantite);
query.bindValue(":prix",prix);
return    query.exec();
}

