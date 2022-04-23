#include "fournisseurs.h"
#include <QSqlQuery>
#include<QtDebug>
#include<QObject>
#include<QTableView>
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
bool Fournisseurs::ajouter()

{
    QSqlQuery query;
    QString id_string= QString::number(id);
    QString quantite_string= QString::number(quantite);
         query.prepare("INSERT INTO Fournisseur(id, quantite, adresse, nom_entreprise, type_marchandise) "
                       "VALUES (:id, :quantite, :adresse, :nom_entreprise, :type_marchandise)");
         query.bindValue(":id", id_string );
         query.bindValue(":quantite", quantite_string );
         query.bindValue(":adresse", adresse);
         query.bindValue(":nom_entreprise", nom_entreprise);
         query.bindValue(":type_marchandise", type_marchandise );
         return  query.exec();

}
bool Fournisseurs::supprimer(int idrech)
{

   QSqlQuery query;
   QString resc = QString ::number(idrech);
    query.prepare("DELETE FROM Fournisseur where ID=:idrech" );
    query.bindValue(":idrech",resc);


    return  query.exec();

}
QSqlQueryModel* Fournisseurs::afficher()
{
        QSqlQueryModel* model=new QSqlQueryModel();
        model->setQuery("SELECT* FROM Fournisseur");
        model->setHeaderData(0, Qt::Horizontal,QObject:: tr("Identifiant"));
        model->setHeaderData(1, Qt::Horizontal,QObject:: tr("Quantite"));
        model->setHeaderData(2, Qt::Horizontal,QObject:: tr("Adresse"));
        model->setHeaderData(3, Qt::Horizontal,QObject:: tr("Nom_entreprise"));
        model->setHeaderData(4, Qt::Horizontal,QObject:: tr("Type_marchandise"));


  return model;
}

bool Fournisseurs::modifier(int id)
{

    QSqlQuery  query;
    QString res = QString::number(id);
    QString tes = QString::number(quantite);
query.prepare("UPDATE Fournisseur SET adresse=:adresse,type_marchandise=:type_marchandise,nom_entreprise=:nom_entreprise,quantite=:quantite WHERE id=:id");
query.bindValue(":id",res);
query.bindValue(":quantite",tes);
query.bindValue(":adresse",adresse);
query.bindValue(":type_marchandise",type_marchandise);
query.bindValue(":nom_entreprise",nom_entreprise);
return query.exec();
}

QSqlQueryModel * Fournisseurs::chercher(int id)
{
    QSqlQuery query;
    QSqlQueryModel * model= new QSqlQueryModel();
    query.prepare("select * from Fournisseur where id =:id");
    query.bindValue(":id",id);
    query.exec();
    model->setQuery(query);

        return model;
}
void Fournisseurs::cleartable(QTableView *table){
     QSqlQueryModel *model=new QSqlQueryModel();
     model->clear();
     table->setModel(model);
 }
void Fournisseurs::chercher_id(QTableView *table, int x)
    {
       QSqlQueryModel *model=new QSqlQueryModel();
       QSqlQuery *query =new QSqlQuery;
       query->prepare("select * from Fournisseur where regexp_like(id,:id);");
       query->bindValue(":id",x);

       if(x==0)
       {
           query->prepare("select * from Fournisseur;");
       }
       query->exec();
       model->setQuery(*query);
       table->setModel(model);
       table->show();
    }








     QSqlQueryModel * Fournisseurs::tri()
 {
     QSqlQueryModel * model= new QSqlQueryModel();
         model->setQuery("select * from Fournisseur order by ID");
         return model;
 }




