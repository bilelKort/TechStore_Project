#include "classlivraison.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QTcpSocket>

Classlivraison::Classlivraison(int cin,QString nomLivreur,QString adresse,int telLivreur,QString diplome,int quantite){
    this->cin=cin;
    this->nomLivreur=nomLivreur;
    this->adresse=adresse;
    this->telLivreur=telLivreur;
    this->diplome=diplome;
    this->quantite=quantite;
}


bool Classlivraison::ajouter(){

    QSqlQuery qry;
    QString resc = QString ::number(cin);
    QString rest = QString ::number(telLivreur);
    QString resm = QString ::number(quantite);
    qry.prepare("INSERT INTO LIVRAISONS (CIN,NOM_LIVREUR,ADRESSE,TEL_LIVREUR,DIPLOME,QUANTITE)"
                "VALUES (:cin,:nomLivreur,:adresse,:telLivreur,:diplome,:quantite);"
                );

    qry.bindValue(":cin",resc);
    qry.bindValue(":nomLivreur",nomLivreur);
    qry.bindValue(":adresse",adresse);
    qry.bindValue(":telLivreur",rest);
    qry.bindValue(":diplome",diplome);
    qry.bindValue(":quantite",resm);


    return qry.exec();
}


bool Classlivraison::modifier(int idRech){
    QSqlQuery qry;
    QString resc = QString ::number(idRech);
    qry.prepare("UPDATE LIVRAISONS SET NOM_LIVREUR=:nomLivreur,ADRESSE=:adresse,TEL_LIVREUR=:telLivreur,DIPLOME=:diplome,QUANTITE=:quantite WHERE CIN= :idRech"
                );

    qry.bindValue(":idRech",resc);
    qry.bindValue(":nomLivreur",nomLivreur);
    qry.bindValue(":adresse",adresse);
    qry.bindValue(":telLivreur",telLivreur);
    qry.bindValue(":diplome",diplome);
    qry.bindValue(":quantite",quantite);

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
model->setHeaderData(4,Qt::Horizontal,QObject::tr("QUANTITE"));

return model;

}

QSqlQueryModel * Classlivraison:: suppcombo(){

QSqlQuery query;
query.prepare("SELECT CIN FROM LIVRAISONS"); //remplir le combo Box
QSqlQueryModel *model=new QSqlQueryModel();
query.exec();
model->setQuery(query);

return model;
}

QSqlQueryModel * Classlivraison::recherche(QString adresserech)
{
    QSqlQuery qry;
    qry.prepare("SELECT * FROM livraisons WHERE adresse like '"+adresserech+"%'");
    qry.bindValue(":adresse",adresserech);
    qry.exec();

    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery(qry);


    return model;
}

QSqlQueryModel * Classlivraison::trie()
{
    QSqlQueryModel * model =new QSqlQueryModel();
    model->setQuery ("SELECT * FROM LIVRAISONS order by ADRESSE");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM_LIVREUR"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("ADRESSE"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("TEL_LIVREUR"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("DIPLOME"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("QUANTITE"));

    return model;
}

void Classlivraison::statistique(QVector<double>* ticks,QVector<QString> *labels)
{
    QSqlQuery q;
    int i=0;
    q.exec("select QUANTITE from livraisons");
    while (q.next())
    {
        QString identifiant = q.value(0).toString();
        i++;
        *ticks<<i;
        *labels <<identifiant;
    }
}
