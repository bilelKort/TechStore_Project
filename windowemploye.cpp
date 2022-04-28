#include "windowemploye.h"
#include "ui_windowemploye.h"
#include<QtSerialPort/QSerialPort>
#include<QtSerialPort/QSerialPortInfo>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QApplication>
#include "employe.h"
#include <QMessageBox>
#include <QString>
#include <QVariant>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QTextStream>
#include <QTextDocument>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QtWidgets>
#include<QFileDialog>
#include<QTcpSocket>

windowemploye::windowemploye(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::windowemploye)
{
    ui->setupUi(this);

    employe e ;
    ui->tableView->setModel(e.read());

    //affichage update
    ui->comboBox->setModel(e.read());
    //delete:
    ui->comboBox_2->setModel(e.read());
    //CONTRAT:
}

windowemploye::~windowemploye()
{
    delete ui;
}


void windowemploye::on_pushButton_clicked()
{
ui->stackedWidget->setCurrentIndex(1);
}

void windowemploye::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

/*void windowemploye::on_pushButton_5_clicked()
{
    QString cin = ui->lineEdit_9->text();
    QString pass = ui->lineEdit_10->text();

    QSqlQuery query;


         query.prepare(("SELECT *FROM EMPLOYE WHERE CIN =:cin AND PWD=:pass"));
         query.bindValue(":cin",cin);
         query.bindValue(":pass",pass);
         query.exec();
         if(query.next())
         {


             A.write_to_arduino("1") ;

                      ui->stackedWidget->setCurrentIndex(2);
                        }

                        else{


             A.write_to_arduino("0") ;
                        }


}*/

void windowemploye::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void windowemploye::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void windowemploye::on_pushButton_12_clicked()
{

    employe E(ui->comboBox->currentText(),ui->lineEdit_13->text(),ui->lineEdit_12->text(),ui->lineEdit_19->text().toInt(),ui->lineEdit_17->text(),ui->lineEdit_11->text().toInt(),ui->lineEdit_14->text(),ui->lineEdit_18->text().toInt()) ;
    if(E.update(E))
    {

            QMessageBox::information(this,"inserted","employe modifié");

    }
            else {
           QMessageBox::information(this,"not inserted","employe modifié");
    }
    //update combobox
     ui->tableView->setModel(E.read());
    //affichage update
    ui->comboBox->setModel(E.read());
    //delete:
    ui->comboBox_2->setModel(E.read());

    //
    ui->comboBox_2->setModel(E.read());

}
//button supprimer
void windowemploye::on_pushButton_13_clicked()
{
    employe e ;
    QString cin_a_supprimer=ui->comboBox_2->currentText();

    if( e.supprimer_employe(cin_a_supprimer)) {


                  QMessageBox::information(nullptr,QObject::tr("OK"),
                                         QObject::tr("delete done.\n"
                                                     "clic cancel to exit."),QMessageBox::Cancel);
       }
       else

       QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                                  QObject::tr("delete not done .\n"
                                              "clic cancel to exit."),QMessageBox::Cancel);
    //update combobox
    ui->tableView->setModel(e.read());
    //affichage update
    ui->comboBox->setModel(e.read());
    //delete:
    ui->comboBox_2->setModel(e.read());
    ui->comboBox_2->setModel(e.read());


}

void windowemploye::on_pushButton_17_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void windowemploye::on_pushButton_16_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void windowemploye::on_pushButton_15_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void windowemploye::on_pushButton_3_clicked()
{
   ui->stackedWidget->setCurrentIndex(1);
}


void windowemploye::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void windowemploye::on_pushButton_9_clicked()
{
    employe e ;

    ui->tableView->setModel(e.read2());
}

void windowemploye::on_pushButton_18_clicked()
{
    employe e ;
    ui->tableView->setModel(e.read3());
}

void windowemploye::on_pushButton_10_clicked()
{

}

void windowemploye::on_pushButton_11_clicked()
{

    QPdfWriter pdf("C:/Users/lenovo/Desktop/contrat employés/employé.pdf");

                 QPainter painter(&pdf);

                 int i = 4000;
                 painter.setPen(Qt::black);
                 painter.setFont(QFont("Arial", 30));

                 painter.drawText(3000,1500,"CONTRATS DES employés ");
                 painter.setPen(Qt::blue);
                 painter.setFont(QFont("Arial", 50));
                 painter.drawRect(2700,200,6300,2600);
                 painter.drawRect(0,3000,9600,500);
                 painter.setPen(Qt::black);
                 painter.setFont(QFont("Arial", 9));
                 painter.drawText(300,3300,"CIN");
                 painter.drawText(2300,3300,"NOM");
                 painter.drawText(4300,3300,"SALAIRE");
                 painter.drawText(6000,3300,"EMAIL");
                 painter.drawText(8300,3300,"DATENAIS");

                 QSqlQuery query;
                 query.prepare("<SELECT CAST( GETDATE() AS Date ) ");
                 time_t tt;
                 struct tm* ti;
                 time(&tt);
                 ti=localtime(&tt);
                 asctime(ti);
                 painter.drawText(500,300, asctime(ti));
                 query.prepare("SELECT CIN,NOM,SALAIRE,EMAIL,DATENAIS FROM EMPLOYE");
                 query.exec();
                 while (query.next())
                 {
                     painter.drawText(300,i,query.value(0).toString());
                     painter.drawText(2300,i,query.value(1).toString());
                     painter.drawText(4300,i,query.value(2).toString());
                     painter.drawText(6300,i,query.value(3).toString());
                     painter.drawText(8000,i,query.value(4).toString());

                     i = i +500;
                 }

                 painter.setPen(Qt::black);
                 painter.setFont(QFont("Arial",15));
                 painter.drawText(300,13000,"Signature de l'employé");

                 int reponse = QMessageBox::question(this, "contrat généré", "Afficher le contrat ?", QMessageBox::Yes |  QMessageBox::No);
                 if (reponse == QMessageBox::Yes)
                 {
                     QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/lenovo/Desktop/contrat employés/employé.pdf"));

                     painter.end();
                 }
                 if (reponse == QMessageBox::No)
                 {
                     painter.end();
                 }
             }



void windowemploye::on_lineEdit_16_textChanged(const QString &arg1)
{
    employe e ;
    ui->tableView->setModel(e.rechercher(arg1));
}

void windowemploye::on_pushButton_19_clicked()
{

}



void windowemploye::on_pushButton_21_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void windowemploye::on_pushButton_20_clicked()
{
    employe E(ui->lineEdit_15->text(),ui->lineEdit_20->text(),ui->lineEdit_21->text(),ui->lineEdit_22->text().toInt(),ui->lineEdit_23->text(),ui->lineEdit_24->text().toInt(),ui->lineEdit_25->text(),ui->lineEdit_26->text().toInt()) ;

    if(E.ajouter_employe(E))
    {
            QMessageBox::information(this,"inserted","house inserted Successfully");
    }
            else {
           QMessageBox::information(this,"not inserted","house not inserted Successfully");
    }
//
    ui->tableView->setModel(E.read());
    //affichage update
    ui->comboBox->setModel(E.read());
    //delete:
    ui->comboBox_2->setModel(E.read());
    //

}

void windowemploye::on_pushButton_7_clicked()
{
    QString link="https://mail.google.com/mail/u/0/#inbox?compose=jrjtXPVFhjRcLhLDrdwJwgJVqJCwqGvRWlGBhPnLrrgFvZPZDpjdGPpNhhDkfzVJDWKxPgbd";
               QDesktopServices::openUrl(link);
}

void windowemploye::on_pushButton_14_clicked()
{
    QTableView *table;
                           table = ui->tableView;

                           QString filters("CSV files (.xlsx);;All files (.*)");
                           QString defaultFilter("CSV files (*.xlsx)");
                           QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                                              filters, &defaultFilter);
                           QFile file(fileName);

                           QAbstractItemModel *model =  table->model();
                           if (file.open(QFile::WriteOnly | QFile::Truncate)) {
                               QTextStream data(&file);
                               QStringList strList;
                               for (int i = 0; i < model->columnCount(); i++) {
                                   if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                                       strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
                                   else
                                       strList.append("");
                               }
                               data << strList.join(";") << "\n";
                               for (int i = 0; i < model->rowCount(); i++) {
                                   strList.clear();
                                   for (int j = 0; j < model->columnCount(); j++) {

                                       if (model->data(model->index(i, j)).toString().length() > 0)
                                           strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                                       else
                                           strList.append("");
                                   }
                                   data << strList.join(";") + "\n";
                               }
                               file.close();
                               QMessageBox::information(nullptr, QObject::tr("Export excel"),
                                                         QObject::tr("Export avec succes .\n"
                                                                     "Click OK to exit."), QMessageBox::Ok);
                           }
        }
        QString currDate()
        {
            QDate date = QDate::currentDate();
            return date.toString("dd.MM.yyyy");
}
