#include "fournisseurs.h"

Fournisseurs::Fournisseurs()
{
id=0;quantite=0;adresse=" ";nom_entreprise=" ";type_marchandise=" ";
}


Fournisseurs::Fournisseurs(int id,int quantite,QString adresse,QString nom_entreprise,QString type_marchandise )
{this->id=id; this->quantite=quantite; this->adresse=adresse; this->nom_entreprise=nom_entreprise; this->type_marchandise=type_marchandise;}
    int Fournisseurs::getid(){return id;}
    int Fournisseurs::getquantite(){return quantite;}
    QString Fournisseurs:: getadresse(){return adresse;}
    QString Fournisseurs::getnom_entreprise(){return nom_entreprise;}
    QString Fournisseurs::gettype_marchandise(){return type_marchandise;}
     void Fournisseurs::setid(int id){this->id=id;}
     void Fournisseurs:: setquantite(int quantite){this->quantite=quantite;}
     void Fournisseurs:: setadresse(QString adresse){this->adresse=adresse;}
     void Fournisseurs::setnom_entreprise(QString nom_entreprise){this->nom_entreprise=nom_entreprise;}
     void Fournisseurs::settype_marchandise(QString type_marchandise){this->type_marchandise=type_marchandise;}

