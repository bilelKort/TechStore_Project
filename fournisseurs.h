#ifndef FOURNISSEURS_H
#define FOURNISSEURS_H
#include<QString>

class Fournisseurs
{
public:
    Fournisseurs();
    Fournisseurs(int,int,QString,QString,QString );
    int getid();
    int getquantite();
         QString getadresse();
         QString getnom_entreprise();
         QString gettype_marchandise();
         void setid(int);
         void setquantite(int);
         void setadresse(QString);
         void setnom_entreprise(QString);
         void settype_marchandise(QString);


private:
    int id,quantite;
    QString adresse,nom_entreprise,type_marchandise;


};

#endif // FOURNISSEURS_H
