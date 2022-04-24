#include "windowcommand.h"
#include "ui_windowcommand.h"
#include"commande.h"
#include<QMessageBox>
#include "connection.h"
#include<QIntValidator>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <iostream>
#include <QMessageBox>
#include  <QDebug>
#include <QRadioButton>
#include<QtPrintSupport/QPrinter>
#include<QPdfWriter>
#include <QPainter>
#include<QFileDialog>
#include<QTextDocument>
#include <QTextEdit>
#include <QtSql/QSqlQueryModel>
#include<QtPrintSupport/QPrinter>
#include <QVector2D>
#include <QVector>
#include <QSqlQuery>
#include<QDesktopServices>
#include <QMessageBox>
#include<QUrl>
#include <QPixmap>
#include <QTabWidget>
#include <QValidator>
#include<QtSql/QSqlQuery>
#include<QVariant>
#include <QSystemTrayIcon>
#include"qrcode.h"
#include<QPixmap>
using namespace  qrcodegen;
using namespace  std;
windowCommand::windowCommand(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::windowCommand)
{
    ui->setupUi(this);
    ui->tableView->setModel(C.afficher("",0));
    ui->tableView_3->setModel(C.statistiques());
    ui->tableView_2->setModel(C.afficher("",0));
    ui->lineEdit_5->setText("");
    ui->stackedWidget->setCurrentWidget(ui->page_2);
    ui->order->setText("décrementé");
    ord=0;
}

windowCommand::~windowCommand()
{
    delete ui;
}

void windowCommand::on_Ajouter_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void windowCommand::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void windowCommand::on_pushButton_2_clicked()
{
       ui->stackedWidget->setCurrentIndex(1);
}

void windowCommand::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void windowCommand::on_pushButton_4_clicked()
{

}

void windowCommand::on_buttonAjout_clicked()
{   int id_c=ui->le_id->text().toInt();
    int prix=ui->le_Prix->text().toInt();
    int quantite=ui->le_Quantite->text().toInt();
    QString DateC=ui->le_Date->text();

    Commande C(id_c,prix,quantite,DateC);
     ui->le_id->setValidator(new QIntValidator(0,999999999,this));
     ui->le_Prix->setValidator(new QIntValidator(0,999999999,this));
     ui->le_Quantite->setValidator(new QIntValidator(0,999999999,this));
    bool test=C.ajouter();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("ajout successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
   ui->tableView->setModel(C.afficher("",ord));
   ui->lineEdit_5->setText("");

   QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
           notifyIcon->show();


          notifyIcon->showMessage("Ajouter ","Commande est bien confirmer avec succèses",QSystemTrayIcon::Information,15000);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("not okay"),
                    QObject::tr("ajout failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}







void windowCommand::on_button_supprimer_clicked()
{  ui->le_id_supp->setValidator(new QIntValidator(0,999999999,this));
    int id_c= ui->le_id_supp->text().toInt();

    bool test=C.supprimer(id_c);

    if (test)


    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("suppression successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
   ui->tableView->setModel(C.afficher("",ord));
   ui->lineEdit_5->setText("");
}
    else
        QMessageBox::critical(nullptr, QObject::tr("not okay"),
                    QObject::tr("suppression failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
void windowCommand::on_buttonAfficher_clicked()
{

}

void windowCommand::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}


void windowCommand::on_pushButton_8_clicked()
{

}

void windowCommand::on_Menu_clicked()
{
      ui->stackedWidget->setCurrentIndex(2);
}

void windowCommand::on_pushButton_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void windowCommand::on_pushButton_13_clicked()
{

      ui->stackedWidget->setCurrentIndex(2);
}

void windowCommand::on_ButtonModifier_clicked()
{ Commande C;
    ui->le_id_modif->setValidator(new QIntValidator(0,999999999,this));
    ui->le_prix_modif->setValidator(new QIntValidator(0,999999999,this));
    ui->le_quantite_modif->setValidator(new QIntValidator(0,999999999,this));

 int id_c=ui->le_id_modif->text().toInt();
C.setPrix(ui->le_prix_modif->text().toInt());
C.setQuantite(ui->le_quantite_modif->text().toInt());
C.setDateC(ui->le_date_modif->text());

   bool test = C.modifier(id_c) ;

       if (test)


       {   ui->setupUi(this);
           ui->tableView->setModel(C.afficher("",ord));
            ui->lineEdit_5->setText("");

           QMessageBox::information(nullptr, QObject::tr("ok"),
                       QObject::tr("update successful.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

   }
       else
           QMessageBox::critical(nullptr, QObject::tr("not okay"),
                       QObject::tr("update failed.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
   }





void windowCommand::on_pushButton_3_clicked()
{
    QString link="https://web.whatsapp.com/";
           QDesktopServices::openUrl(link);
}

void windowCommand::on_pushButton_21_clicked()
{
      ui->stackedWidget->setCurrentIndex(2);
}

void windowCommand::on_lineEdit_5_textChanged(const QString &arg1)
{
     ui->tableView->setModel(C.afficher(arg1,ord));
}

void windowCommand::on_order_clicked()
{       if(ord==0){
        ui->order->setText("incrementé");
        ord=1;}else {ui->order->setText("décrementé");
        ord=0;}
         ui->tableView->setModel(C.afficher(ui->lineEdit_5->text(),ord));

}



void windowCommand::on_qrCode_clicked()
{
    int tabeq=ui->tableView->currentIndex().row();
                 QVariant idd=ui->tableView->model()->data(ui->tableView->model()->index(tabeq,0));
                 QString id_c=idd.toString();
                // QString code=idd.toSTring();
                 QSqlQuery qry;
                 qry.prepare("select * from COMMANDE where id_c=:code");
                 qry.bindValue(":code",id_c);
                 qry.exec();

                  QString DateC;//attributs
                  int prix,quantite;


                while(qry.next()){

                    id_c=qry.value(1).toString();
                     prix=qry.value(3).toInt();
                     quantite=qry.value(4).toInt();
                     DateC=qry.value(6).toString();



                 }
                 id_c=QString(id_c);
                        id_c="CODE:\t" +id_c+ "PRIX\t:" +prix+ "QUANTITE:\t" +quantite+ "DateC:\t" +DateC ;
                 QrCode qr = QrCode::encodeText(id_c.toUtf8().constData(), QrCode::Ecc::HIGH);

                 // Read the black & white pixels
                 QImage im(qr.getSize(),qr.getSize(), QImage::Format_RGB888);
                 for (int y = 0; y < qr.getSize(); y++) {
                     for (int x = 0; x < qr.getSize(); x++) {
                         int color = qr.getModule(x, y);  // 0 for white, 1 for black

                         // You need to modify this part
                         if(color==0)
                             im.setPixel(x, y,qRgb(254, 254, 254));
                         else
                             im.setPixel(x, y,qRgb(0, 0, 0));
                     }
                 }
                 im=im.scaled(200,200);
                 ui->qr_code->setPixmap(QPixmap::fromImage(im));
}
