#include "enregistrementLivraison.h"

#include "connection.h"
#include"arduino.h"

enregistrementLivraison::enregistrementLivraison()
{

       total="";

        }
        enregistrementLivraison::enregistrementLivraison(QString total )
        {

            this->total=total;



        }
        //getter
        QString enregistrementLivraison::get_total(){return total;}


        bool enregistrementLivraison::ajouter()
        {
            //Add row to enregistrementLivraisonS
            QSqlQuery query;

            query.prepare("INSERT INTO arduino (total) "
                                "VALUES (:total, )");

            query.bindValue(":total",total);

            return query.exec();

        }
        QSqlQueryModel *enregistrementLivraison ::afficher()
        {QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select * from arduino");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("total"));
       // model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date "));


            return model;
}
