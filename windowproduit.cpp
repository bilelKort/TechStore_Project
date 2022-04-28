#include "windowproduit.h"
#include "ui_windowproduit.h"
#include "produit.h"
#include "connection.h"
#include "classlivraison.h"
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>
#include "QIntValidator"
#include <QDateEdit>
#include <QPlainTextEdit>
#include <QPrinter>
#include <QPrinterInfo>
#include <QPrintDialog>
#include <QTextStream>
#include <QPainter>
#include <QTextStream>
#include <QFileDialog>
#include <QTextDocument>
#include <QtPrintSupport/QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <strstream>
#include <QSystemTrayIcon>
#include <QRegExpValidator>
#include <QDesktopServices>
#include <QUrl>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QTcpSocket>
#include <QQuickItem>

windowproduit::windowproduit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::windowproduit)
{
    ui->setupUi(this);
    ui->tabprd->setModel(prd.afficher());
}

windowproduit::~windowproduit()
{
    delete ui;
}

void windowproduit::on_addbtn_clicked()
{
    int idprd = ui->idprd->text().toInt();
    QString nomprd = ui->nomprd->text();
    QString catprd =  ui->catprd->text();
    int qtprd =  ui->qtprd->text().toInt();
    int prixprd =  ui->prixprd->text().toInt();

    produit prd(idprd,nomprd,catprd,qtprd,prixprd);

    if(prd.ajouter()){
        QMessageBox::information(this,"Done", "information added");
    }else{
        QMessageBox::information(this,"ERROR", "information not added");
    }
}

void windowproduit::on_editBtn_clicked()
{
    int idprd2 = ui->idprd_2->text().toInt();
    QString nomprd2 = ui->nomprd_2->text();
    QString catprd2 =  ui->catprd_2->text();
    int qtprd2 =  ui->qtprd_2->text().toInt();
    int prixprd2 =  ui->prixprd_2->text().toInt();

    produit prd(idprd2,nomprd2,catprd2,qtprd2,prixprd2);
prd.modifier(idprd2);
    if(prd.modifier(idprd2)){
        QMessageBox::information(this,"Done", "information added");
    }else{
        QMessageBox::information(this,"ERROR", "information not added");
    }
}

void windowproduit::on_ajouterprd_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void windowproduit::on_editerprd_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void windowproduit::on_suppBtn_clicked()
{
    int idsupp =  ui->idsupp->text().toInt();


    prd.supprimer(idsupp);

    if(prd.supprimer(idsupp)){
     QMessageBox::information(this,"Done", "information Updated");
     }else{
    QMessageBox::information(this,"ERROR", "information not UPDATED");
     }
}

void windowproduit::on_supprimerprd_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);

}
