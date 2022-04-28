#include "windowfournisseur.h"
#include "ui_windowfournisseur.h"
#include "fournisseurs.h"
#include<QMessageBox>
#include<QIntValidator>
#include <QString>
#include <QtSql>
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>
#include<QFileDialog>
windowfournisseur::windowfournisseur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::windowfournisseur)
{
    ui->setupUi(this);
    ui->le_id->setValidator(new QIntValidator(0, 99999999, this));
    ui->tab_Fournisseur->setModel(F.afficher());
}

windowfournisseur::~windowfournisseur()
{
    delete ui;
}


void windowfournisseur::on_pb_ajouter_2_clicked()
{

    ui->le_quantite->setValidator(new QIntValidator (0,99999999,this));
    int id=ui->le_id->text().toInt();
    ui->le_id->setValidator(new QIntValidator (0,99999999,this));
    int quantite=ui->le_quantite->text().toInt();
    QString adresse=ui->le_adresse->text();
    QString nom_entreprise=ui->le_nom_entreprise->text();
    QString type_marchandise=ui->le_type_marchandise->text();

   Fournisseurs F(id,quantite,adresse,nom_entreprise,type_marchandise);
   bool test=F.ajouter();
              if(test)
              {
                  ui->tab_Fournisseur->setModel(F.afficher());
                  n.notification_ajoutab();
                  QMessageBox::information(nullptr,QObject::tr("OK"),
                                         QObject::tr("data ajouté.\n"
                                                     "click cancel to exit."),QMessageBox::Cancel);
              }
              else

              {
                  ui->tab_Fournisseur->setModel(F.afficher());
                  QMessageBox::critical(nullptr,QObject::tr("OK"),
                                         QObject::tr("data non ajouté.\n"
                                                     "click cancel to exit."),QMessageBox::Cancel);
              }
  }






void windowfournisseur::on_pb_supp_clicked()
{
    int id = ui->le_id_supp->text().toInt();
    F.supprimer(id);
    QMessageBox msgBox;

    if(F.supprimer(id))
    { msgBox.setText("suppression faite aves success");
        ui->tab_Fournisseur->setModel(F.afficher());
        n.notification_supprimerab();

    }
    else
        msgBox.setText("suppression failed");
}



void windowfournisseur::on_pb_modi_clicked()
{
    ui->le_id->setValidator(new QIntValidator (0,99999999,this));
    ui->le_quantite->setValidator(new QIntValidator (0,99999999,this));
    int id=ui->le_id->text().toInt();
    int quantite=ui->le_quantite->text().toInt();
    QString adresse=ui->le_adresse->text();
    QString type_marchandise=ui->le_type_marchandise->text();
    QString nom_entreprise=ui->le_nom_entreprise->text();

Fournisseurs newf (id,quantite,adresse,type_marchandise,nom_entreprise);
             bool test2=newf.modifier(id);
             if(test2)
             {   /*ui->tab_Fournisseur->setModel(F.read());*/
                 ui->tab_Fournisseur->setModel(newf.afficher());
                 n.notification_modifierab();
         QMessageBox::information(nullptr,QObject::tr("OK"),
                                QObject::tr("update effectue.\n"
                                            "clic cancel to exit."),QMessageBox::Cancel);

             }
     else
         {/*ui->tab_Fournisseur->setModel(F.read());*/
     QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                                QObject::tr("update non effectue.\n"
                                            "clic cancel to exit."),QMessageBox::Cancel);}




}




void windowfournisseur::on_pb_rech_clicked()
{
     int id = ui->le_id_supp->text().toInt();
       ui->tab_Fournisseur->setModel(F.chercher(id));
      QMessageBox::information(nullptr,QObject::tr("ok"),
                                QMessageBox::tr("recherche effectue.\n"
                                                "clic cancel to exit."),QMessageBox::Cancel);
}


void windowfournisseur::on_pb_tri_clicked()
{
        ui->tab_Fournisseur->setModel(F.tri());
            QMessageBox::information(nullptr, QObject::tr("Ok"),
                        QObject::tr("tri effectu.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}


void windowfournisseur::on_pb_pdf_clicked()
{
    qDebug()<<"hello" ;
        QString strStream;
                          QTextStream out(&strStream);

                           const int rowCount = ui->tab_Fournisseur->model()->rowCount();
                           const int columnCount = ui->tab_Fournisseur->model()->columnCount();
                          out <<  "<html>\n"
                          "<head>\n"
                                           "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                           <<  QString("<title>%1</title>\n").arg("strTitle")
                                           <<  "</head>\n"
               "<body bgcolor=#ffffff link=#5000A0>\n"
     //     "<align='right'> " << datefich << "</align>"
 "<center> <H1>Gestion Des Fournissurs</H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

       // headers
    out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
  out<<"<cellspacing=10 cellpadding=3>";
  for (int column = 0; column < columnCount; column++)
 if (!ui->tab_Fournisseur->isColumnHidden(column))
 out << QString("<th>%1</th>").arg(ui->tab_Fournisseur->model()->headerData(column, Qt::Horizontal).toString());
 out << "</tr></thead>\n";

 // data table
  for (int row = 0; row < rowCount; row++) {
 out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
  for (int column = 0; column < columnCount; column++) {
  if (!ui->tab_Fournisseur->isColumnHidden(column)) {
  QString data = ui->tab_Fournisseur->model()->data(ui->tab_Fournisseur->model()->index(row, column)).toString().simplified();
 out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
  }
  }
  out << "</tr>\n";
  }
 out <<  "</table> </center>\n"
  "</body>\n"
       "</html>\n";

 QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

       QPrinter printer (QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
         printer.setPaperSize(QPrinter::A4);
        printer.setOutputFileName(fileName);

               QTextDocument doc;
              doc.setHtml(strStream);
           doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
           doc.print(&printer);
    }


void windowfournisseur::on_pushButton_13_clicked()
{
    this->hide();
    dialog * newmain = new dialog();
    newmain->show();
}
