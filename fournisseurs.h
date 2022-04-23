#ifndef FOURNISSEURS_H
#define FOURNISSEURS_H
#include<QString>
#include<QSqlQueryModel>
#include<QTableView>
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
         bool ajouter();
         QSqlQueryModel* afficher();
         bool supprimer(int);
         bool modifier(int);
         QSqlQueryModel* read();
         QSqlQueryModel *chercher(int);
         QSqlQueryModel *tri();
         void chercher_id(QTableView *table, int x);
         void cleartable(QTableView *table);
private:
    int id,quantite;
    QString adresse,nom_entreprise,type_marchandise;


};

#endif // FOURNISSEURS_H
