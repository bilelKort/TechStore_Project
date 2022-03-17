#include "livraisondialog.h"
#include "ui_livraisondialog.h"
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

livraisonDialog::livraisonDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::livraisonDialog)
{
    ui->setupUi(this);
    ui->tab_livraison->setModel(livra.afficher());
    ui->suppbox->setModel(livra.suppcombo());
    ui->quickWidget->setSource(QUrl(QStringLiteral("grc:/map.qml")));
    ui->quickWidget->show();
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
    //int cin = ui->cinSupp->text().toInt();
    int cin =  ui->suppbox->currentText().toInt();


    livra.supprimer(cin);

    if(livra.supprimer(cin)){
     QMessageBox::information(this,"Done", "information Updated");
     }else{
    QMessageBox::information(this,"ERROR", "information not UPDATED");
     }
}




void livraisonDialog::on_chercherbtn_clicked()
{
    QString adresse = ui->adresserech->text();
    QSqlQueryModel *verif=livra.recherche(adresse);
    if(verif!=nullptr){
        ui->tab_livraison_rech->setModel(verif);
        ui->tab_livraison_rech->show();
      }
    else{
     QMessageBox::information(this,"ERROR", "ERROR");
        }

}

void livraisonDialog::on_tri_clicked()
{
    ui->tab_livraison->setModel(livra.trie());
    ui->tab_livraison->show();
}

void livraisonDialog::on_tabWidget_currentChanged(int index)
{
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(90, 90, 90));
    gradient.setColorAt(0.38, QColor(105, 105, 105));
    gradient.setColorAt(1, QColor(70, 70, 70));
    ui->plot->setBackground(QBrush(gradient));

    QCPBars *amande = new QCPBars(ui->plot->xAxis, ui->plot->yAxis);
    amande->setAntialiased(false);
    amande->setStackingGap(1);
     //couleurs
    amande->setName("Repartition des produit selon quantite ");
    amande->setPen(QPen(QColor(0, 168, 140).lighter(130)));
    amande->setBrush(QColor(0, 168, 140));

     //axe des abscisses
    QVector<double> ticks;
    QVector<QString> labels;

    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    ui->plot->xAxis->setTicker(textTicker);
    ui->plot->xAxis->setTickLabelRotation(60);
    ui->plot->xAxis->setSubTicks(false);
    ui->plot->xAxis->setTickLength(0, 4);
    ui->plot->xAxis->setRange(0, 8);
    ui->plot->xAxis->setBasePen(QPen(Qt::white));
    ui->plot->xAxis->setTickPen(QPen(Qt::white));
    ui->plot->xAxis->grid()->setVisible(true);
    ui->plot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    ui->plot->xAxis->setTickLabelColor(Qt::white);
    ui->plot->xAxis->setLabelColor(Qt::white);

    // axe des ordonnées
    ui->plot->yAxis->setRange(0,10);
    ui->plot->yAxis->setPadding(5);
    ui->plot->yAxis->setLabel("Statistiques");
    ui->plot->yAxis->setBasePen(QPen(Qt::white));
    ui->plot->yAxis->setTickPen(QPen(Qt::white));
    ui->plot->yAxis->setSubTickPen(QPen(Qt::white));
    ui->plot->yAxis->grid()->setSubGridVisible(true);
    ui->plot->yAxis->setTickLabelColor(Qt::white);
    ui->plot->yAxis->setLabelColor(Qt::white);
    ui->plot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    ui->plot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));


}
