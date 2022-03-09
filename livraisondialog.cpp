#include "livraisondialog.h"
#include "ui_livraisondialog.h"
#include "connection.h"
#include "classlivraison.h"
#include <QSqlQueryModel>




livraisonDialog::livraisonDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::livraisonDialog)
{
    ui->setupUi(this);
    ui->tab_livraison->setModel(livra.afficher());
}

livraisonDialog::~livraisonDialog()
{
    delete ui;
}


void livraisonDialog::on_ajouterbtn_clicked()
{
      ui->stackedWidget->setCurrentIndex(1);

}


void livraisonDialog::on_editerbtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void livraisonDialog::on_supprimerbtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);

}


void livraisonDialog::on_addbtn_clicked()
{
    int cin = ui->cin->text().toInt();
    QString nomLivreur = ui->nomLivreur->text();
    QString adresse =  ui->adresse->text();
    int telLivreur =  ui->telLivreur->text().toInt();
    QString diplome =  ui->diplome->text();

    Classlivraison liv(cin,nomLivreur,adresse,telLivreur,diplome);

    if(liv.ajouter()){
        QMessageBox::information(this,"Done", "information added");
    }else{
        QMessageBox::information(this,"ERROR", "information not added");
    }

}


void livraisonDialog::on_editBtn_clicked()
{
    int cin = ui->cinEdit->text().toInt();
    QString nomLivreur = ui->nomLivreurEdit->text();
    QString adresse =  ui->adresseEdit->text();
    int telLivreur =  ui->telLivreurEdit->text().toInt();
    QString diplome =  ui->diplomeEdit->text();

    Classlivraison liv(cin,nomLivreur,adresse,telLivreur,diplome);
    liv.modifier(cin);

    if(liv.modifier(cin)){
     QMessageBox::information(this,"Done", "information Updated");
     }else{
    QMessageBox::information(this,"ERROR", "information not UPDATED");
     }
}

void livraisonDialog::on_suppBtn_clicked()
{
    int cin = ui->cinSupp->text().toInt();


    livra.supprimer(cin);

    if(livra.supprimer(cin)){
     QMessageBox::information(this,"Done", "information Updated");
     }else{
    QMessageBox::information(this,"ERROR", "information not UPDATED");
     }
}



