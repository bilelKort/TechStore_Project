#include "employe.h"

employe::employe(QString cin,QString nom,QString date,int salaire,QString email,int experience,QString password,int nbrabsence)
{
    this->cin=cin;
        this->nom=nom;
        this->datenaissance=date;
        this->salaire=salaire;
        this->email=email;
        this->experience=experience;
        this->password=password;
        this->nb_absence=nbrabsence;
}
employe::employe()
{
    this->cin="";
        this->nom="";
        this->datenaissance="";
        this->salaire=0;
        this->email="";
        this->experience=0;
        this->password="";
        this->nb_absence=0;
}
bool employe::ajouter_employe(employe E)
{

     QSqlQuery query;
     query.prepare("INSERT INTO EMPLOYE (CIN,DATENAIS,SALAIRE,EXPERIENCE,NBR_ABSENCE,EMAIL,PWD,NOM) VALUES (?,?,?,?,?,?,?,?)");
     query.addBindValue(E.cin);
     query.addBindValue(E.datenaissance);
    // query.addBindValue(Description);
     query.addBindValue(E.salaire);
      query.addBindValue(E.experience);
      query.addBindValue(E.nb_absence);
      query.addBindValue(E.email);
      query.addBindValue(E.password);
      query.addBindValue(E.nom);





     if(!query.exec())
     {
         qDebug()<<"not added";
     }
  return true ;
}
QSqlQueryModel * employe::read()
{   QSqlQueryModel *model=new QSqlQueryModel();
         model->setQuery("SELECT * FROM EMPLOYE");
         model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
         model->setHeaderData(1,Qt::Horizontal,QObject::tr("DATENAIS"));
         model->setHeaderData(2,Qt::Horizontal,QObject::tr("SALAIRE"));
         model->setHeaderData(3,Qt::Horizontal,QObject::tr("EXPERIENCE"));
         model->setHeaderData(4,Qt::Horizontal,QObject::tr("NBR_ABSENCE"));
         model->setHeaderData(5,Qt::Horizontal,QObject::tr("EMAIL"));
         model->setHeaderData(6,Qt::Horizontal,QObject::tr("PWD"));
         model->setHeaderData(7,Qt::Horizontal,QObject::tr("NOM"));







return model;
}QSqlQueryModel * employe::read2()
{   QSqlQueryModel *model=new QSqlQueryModel();
         model->setQuery("SELECT * FROM EMPLOYE ORDER BY EXPERIENCE ");
         model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN ")) ;
         model->setHeaderData(1,Qt::Horizontal,QObject::tr("DATENAIS"));
         model->setHeaderData(2,Qt::Horizontal,QObject::tr("SALAIRE"));
         model->setHeaderData(3,Qt::Horizontal,QObject::tr("EXPERIENCE"));
         model->setHeaderData(4,Qt::Horizontal,QObject::tr("NBR_ABSENCE"));
         model->setHeaderData(5,Qt::Horizontal,QObject::tr("EMAIL"));
         model->setHeaderData(6,Qt::Horizontal,QObject::tr("PWD"));
         model->setHeaderData(7,Qt::Horizontal,QObject::tr("NOM"));







return model;
}

QSqlQueryModel * employe::read3()
{   QSqlQueryModel *model=new QSqlQueryModel();
         model->setQuery("SELECT * FROM EMPLOYE ORDER BY EXPERIENCE DESC ");
         model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
         model->setHeaderData(1,Qt::Horizontal,QObject::tr("DATENAIS"));
         model->setHeaderData(2,Qt::Horizontal,QObject::tr("SALAIRE"));
         model->setHeaderData(3,Qt::Horizontal,QObject::tr("EXPERIENCE"));
         model->setHeaderData(4,Qt::Horizontal,QObject::tr("NBR_ABSENCE"));
         model->setHeaderData(5,Qt::Horizontal,QObject::tr("EMAIL"));
         model->setHeaderData(6,Qt::Horizontal,QObject::tr("PWD"));
         model->setHeaderData(7,Qt::Horizontal,QObject::tr("NOM"));







return model;
}

QSqlQueryModel * employe::read4(QString cin)
{   QSqlQueryModel *model=new QSqlQueryModel();
         model->setQuery("SELECT CIN,NOM,SALAIRE,EXPERIENCE FROM EMPLOYE WHERE CIN=cin");
         model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
         model->setHeaderData(2,Qt::Horizontal,QObject::tr("SALAIRE"));
         model->setHeaderData(3,Qt::Horizontal,QObject::tr("EXPERIENCE"));
         model->setHeaderData(7,Qt::Horizontal,QObject::tr("NOM"));







return model;
}




bool employe::update(employe e)
{

    QSqlQuery  query;

query.prepare("UPDATE EMPLOYE SET SALAIRE=:salaire,NBR_ABSENCE=:nb_absence,EXPERIENCE=:experience,PWD=:password,EMAIL=:email,NOM=:nom,DATENAIS=:date WHERE CIN=:cin");
query.bindValue(":cin",e.cin);
query.bindValue(":salaire",e.salaire);
query.bindValue(":nb_absence",e.nb_absence);
query.bindValue(":password",e.password);
query.bindValue(":experience",e.experience);
query.bindValue(":email",e.email);
query.bindValue(":nom",e.nom);
query.bindValue(":date",e.datenaissance);







qDebug()<<"cin"<<e.cin;
 qDebug()<<"nom"<<e.nom;
  qDebug()<<"date"<<e.datenaissance;


return query.exec();
}
bool employe::supprimer_employe(QString cin)
{
    QSqlQuery query;

    query.prepare("DELETE FROM EMPLOYE where CIN=:id");
    query.bindValue(":id",cin);
return query.exec();

}
QSqlQueryModel *employe::rechercher(QString rech)
{



    QSqlQueryModel *model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM EMPLOYE WHERE CIN LIKE'%"+rech+"%' or NOM LIKE'%"+rech+"%' or EMAIL LIKE'%"+rech+"%'" );
    return model;

}
QSqlQueryModel *employe::rechercher2(QString rech)
{

        QSqlQueryModel *model= new QSqlQueryModel();
        model->setQuery("SELECT * FROM EMPLOYE WHERE CIN LIKE'%"+rech+"%' or NOM LIKE'%"+rech+"%' or EMAIL LIKE'%"+rech+"%'" );
        return model;


}
