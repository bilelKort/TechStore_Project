#include "enregistrement.h"
#include "connection.h"
#include"arduino.h"

enregistrement::enregistrement()
{

       msg="";

        }
        enregistrement::enregistrement(QString msg )
        {

            this->msg=msg;



        }
        //getter
        QString enregistrement::get_msg(){return msg;}







        bool enregistrement::ajouter()
        {
            //Add row to enregistrementS
            QSqlQuery query;

            query.prepare("INSERT INTO enregistrement (MSG) "
                                "VALUES (:msg, )");

            query.bindValue(":msg",msg);



            return query.exec();

        }
        QSqlQueryModel *enregistrement ::afficher()
        {QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select * from enregistrement");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Message"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date "));


            return model;
}
