#include "classlivraison.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

Classlivraison::Classlivraison(int cin,QString nomLivreur,QString adresse,int telLivreur,QString diplome){
    this->cin=cin;
    this->nomLivreur=nomLivreur;
    this->adresse=adresse;
    this->telLivreur=telLivreur;
    this->diplome=diplome;
}


bool Classlivraison::ajouter(){

    QSqlQuery qry;
    QString resc = QString ::number(cin);
    QString rest = QString ::number(telLivreur);
    qry.prepare("INSERT INTO LIVRAISONS (CIN,NOM_LIVREUR,ADRESSE,TEL_LIVREUR,DIPLOME)"
                "VALUES (:cin,:nomLivreur,:adresse,:telLivreur,:diplome);"
                );

    qry.bindValue(":cin",resc);
    qry.bindValue(":nomLivreur",nomLivreur);
    qry.bindValue(":adresse",adresse);
    qry.bindValue(":telLivreur",rest);
    qry.bindValue(":diplome",diplome);

    return qry.exec();
}


bool Classlivraison::modifier(int idRech){
    QSqlQuery qry;
    QString resc = QString ::number(idRech);
    qry.prepare("UPDATE LIVRAISONS SET NOM_LIVREUR=:nomLivreur,ADRESSE=:adresse,TEL_LIVREUR=:telLivreur,DIPLOME=:diplome WHERE CIN= :idRech"
                );

    qry.bindValue(":idRech",resc);
    qry.bindValue(":nomLivreur",nomLivreur);
    qry.bindValue(":adresse",adresse);
    qry.bindValue(":telLivreur",telLivreur);
    qry.bindValue(":diplome",diplome);

    return qry.exec();
}

bool Classlivraison::supprimer(int idRech){
    QSqlQuery qry;
    QString resc = QString ::number(idRech);

    qry.prepare("DELETE FROM LIVRAISONS WHERE CIN = :idRech");
    qry.bindValue(":idRech",resc);

    return qry.exec();
}

QSqlQueryModel * Classlivraison:: afficher()
{

QSqlQueryModel * model =new QSqlQueryModel();
model->setQuery ("SELECT * FROM LIVRAISONS");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM_LIVREUR"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("ADRESSE"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("TEL_LIVREUR"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("DIPLOME"));

return model;

}


