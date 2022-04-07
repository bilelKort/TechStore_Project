#include "sponsor.h"

//seter (modification)
sponsor::sponsor(QString id ,QString cin ,QString nom ,QString email ,int nbretoile,int tel ,QString date)
{
    this->id=id;
        this->cin=cin;
        this->nom=nom;
        this->email=email;
        this->nbretoile=nbretoile;
        this->tel=tel;
        this->date=date;

}
//geter(initialisation)
sponsor::sponsor()
{
    this->id="";
        this->cin="";
        this->nom="";
        this->email="";
        this->nbretoile=0;
        this->tel=0;
        this->date="";
}


//AJOUT
bool sponsor::ajouter_sponsor(sponsor E)
{

     QSqlQuery query;
     query.prepare("INSERT INTO SPONSOR (ID_S,CIN,NOM_S,MAIL_S,NB_ETOILE,TEL_S,DATES) VALUES (?,?,?,?,?,?,?)");//t7ather requet lil execution
     query.addBindValue(E.id);//liaison de position
     query.addBindValue(E.cin);
     query.addBindValue(E.nom);
     query.addBindValue(E.email);
     query.addBindValue(E.nbretoile);
     query.addBindValue(E.tel) ;
     query.addBindValue(E.date);

     if(!query.exec())
     {
         qDebug()<<"not added";//detecter les erreur
     }
  return true ;
}


//DATA FROM BASE DE DONNEE
QSqlQueryModel * sponsor::read()//nhoto fih il data mil base de donne
{   QSqlQueryModel *model=new QSqlQueryModel();
         model->setQuery("SELECT * FROM SPONSOR");
         model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_S"));
         model->setHeaderData(1,Qt::Horizontal,QObject::tr("CIN"));
         model->setHeaderData(2,Qt::Horizontal,QObject::tr("NOM_S"));
         model->setHeaderData(3,Qt::Horizontal,QObject::tr("MAIL_S"));
         model->setHeaderData(4,Qt::Horizontal,QObject::tr("NB_ETOILE"));
         model->setHeaderData(5,Qt::Horizontal,QObject::tr("TEL_S"));
         model->setHeaderData(6,Qt::Horizontal,QObject::tr("DATES"));
return model;
}


//tri A-Z
QSqlQueryModel * sponsor::affichertrii()
{   QSqlQueryModel *model=new QSqlQueryModel();
model->setQuery("SELECT * FROM SPONSOR order by NOM_S Asc");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_S"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("CIN"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("NOM_S"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("MAIL_S"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("NB_ETOILE"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("TEL_S"));
model->setHeaderData(6,Qt::Horizontal,QObject::tr("DATES"));
return model;
}


//tri Z-A
QSqlQueryModel * sponsor::affichertri()
{   QSqlQueryModel *model=new QSqlQueryModel();
model->setQuery("SELECT * FROM SPONSOR order by NOM_S desc");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_S"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("CIN"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("NOM_S"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("MAIL_S"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("NB_ETOILE"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("TEL_S"));
model->setHeaderData(6,Qt::Horizontal,QObject::tr("DATES"));
return model;
}


//UPDATE
bool sponsor::update(sponsor e)
{
    QSqlQuery  query;
query.prepare("UPDATE SPONSOR SET ID_S=:id,CIN=:cin,NOM_S=:nom,MAIL_S=:email,NB_ETOILE=:nbr,TEL_S=:tel,DATES=:date WHERE ID_S=:id");
query.bindValue(":id",e.id);
query.bindValue(":cin",e.cin);

query.bindValue(":nom",e.nom);
query.bindValue(":email",e.email);
query.bindValue(":nbr",e.nbretoile);
query.bindValue(":tel",e.tel);
query.bindValue(":date",e.date);
return query.exec();//envoie le requet pour l'executer
}



//Supprimer
bool sponsor::supprimer_sponsor(QString id)
{
    QSqlQuery query;

    query.prepare("DELETE FROM SPONSOR where ID_S=:id");
    query.bindValue(":id",id);
return query.exec();//envoie le requet pour l'executer

}

//recherche

QSqlQueryModel *sponsor::rechercher(QString rech)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM SPONSOR WHERE NOM_S LIKE'%"+rech+"%'");
    return model;


}
QSqlQueryModel *sponsor::rechercherc(QString rech)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM SPONSOR WHERE NOM_S LIKE'%"+rech+"%'");
    return model;


}
QSqlQueryModel *sponsor::rechercher1(QString rech)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM SPONSOR WHERE NOM_S LIKE'%"+rech+"%'AND NB_ETOILE = 1");
    return model;


}
QSqlQueryModel *sponsor::rechercher2(QString rech)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM SPONSOR WHERE NOM_S LIKE'%"+rech+"%'AND NB_ETOILE = 2");
    return model;


}
QSqlQueryModel *sponsor::rechercher3(QString rech)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM SPONSOR WHERE NOM_S LIKE'%"+rech+"%'AND NB_ETOILE = 3");
    return model;


}
QSqlQueryModel *sponsor::rechercher4(QString rech)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM SPONSOR WHERE NOM_S LIKE'%"+rech+"%'AND NB_ETOILE = 4");
    return model;


}
