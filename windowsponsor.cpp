#include "windowsponsor.h"
#include "ui_windowsponsor.h"
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QApplication>
#include "sponsor.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>
//#include <QPrinter>
#include <QDesktopServices>
#include <QUrl>
#include "smtp.h"

windowsponsor::windowsponsor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::windowsponsor)
{
    ui->setupUi(this);
  ui->stackedWidget->setCurrentIndex(0);
    sponsor e ;
    ui->tableView->setModel(e.read());
    ui->table->setModel(e.statistiques());
    //affichage update
    ui->comboBox->setModel(e.read());
    //delete:
    ui->comboBox_2->setModel(e.read());
}

windowsponsor::~windowsponsor()
{
    delete ui;
    /* ui->stackedWidget->setCurrentIndex(0);

     //show table
     sponsor e ;
     ui->tableView->setModel(e.read());
     ui->table->setModel(e.statistiques());
     //affichage update
     ui->comboBox->setModel(e.read());
     //delete:
     ui->comboBox_2->setModel(e.read());*/
}

void windowsponsor::on_pushButton_clicked()
{
ui->stackedWidget->setCurrentIndex(2);
}

void windowsponsor::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void windowsponsor::on_pushButton_5_clicked()
{
    sponsor E(ui->lineEdit->text(),ui->lineEdit_8->text(),ui->lineEdit_2->text(),ui->lineEdit_3->text(),ui->lineEdit_4->text().toInt(),ui->lineEdit_5->text().toInt(),ui->lineEdit_6->text()) ;

    if(E.ajouter_sponsor(E))
    {
            QMessageBox::information(this,"inserted","inserted Successfully");
    }
            else {
           QMessageBox::information(this,"not inserted","not inserted Successfully");
    }
//
    ui->tableView->setModel(E.read());
    //affichage update
    ui->comboBox->setModel(E.read());
    //delete:
    ui->comboBox_2->setModel(E.read());
    //

}

void windowsponsor::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void windowsponsor::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void windowsponsor::on_pushButton_12_clicked()
{
    sponsor E(ui->comboBox->currentText(),ui->lineEdit_15->text(),ui->lineEdit_11->text(),ui->lineEdit_13->text(),ui->lineEdit_14->text().toInt(),ui->lineEdit_16->text().toInt(),ui->lineEdit_12->text()) ;

    if(E.update(E))
    {

            QMessageBox::information(this,"inserted","sponsor modifié");

    }
            else {
           QMessageBox::information(this,"not inserted","sponsor modifié");
    }
    //update combobox
     ui->tableView->setModel(E.read());
    //affichage update
    ui->comboBox->setModel(E.read());
    //delete:
    ui->comboBox_2->setModel(E.read());
    //
}
//button supprimer
void windowsponsor::on_pushButton_13_clicked()
{
    sponsor e ;
    QString id_a_supprimer=ui->comboBox_2->currentText();

    if( e.supprimer_sponsor(id_a_supprimer)) {


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

}

void windowsponsor::on_pushButton_14_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void windowsponsor::on_pushButton_11_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}



void windowsponsor::on_pushButton_9_clicked()
{
  sponsor e;
    ui->tableView->setModel(e.affichertri());
    //affichage update
    ui->comboBox->setModel(e.affichertri());
    //delete:
    ui->comboBox_2->setModel(e.affichertri());
    //
}

void windowsponsor::on_pushButton_16_clicked()
{
    sponsor e;
      ui->tableView->setModel(e.affichertrii());
      //affichage update
      ui->comboBox->setModel(e.affichertrii());
      //delete:
      ui->comboBox_2->setModel(e.affichertrii());
      //
}

//recherche
void windowsponsor::on_lineEdit_7_textChanged(const QString &arg1)
{
    sponsor e ;
    ui->tableView->setModel(e.rechercher(arg1));
}

//mailling
void windowsponsor::on_mailling_clicked()
{
    QString link="https://mail.google.com/mail/u/0/#inbox?compose=new";
        QDesktopServices::openUrl(link);
}



//pdf
void windowsponsor::on_pushButton_4_clicked()
{
    qDebug()<<"hello" ;
    QString strStream;
                      QTextStream out(&strStream);

                       const int rowCount = ui->tableView->model()->rowCount();
                       const int columnCount = ui->tableView->model()->columnCount();
                      out <<  "<html>\n"
                      "<head>\n"
                                       "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                       <<  QString("<title>%1</title>\n").arg("strTitle")
                                       <<  "</head>\n"
                                       "<body bgcolor=#ffffff link=#5000A0>\n"

                                      //     "<align='right'> " << datefich << "</align>"
                                       "<center> <H1>Liste Des SPONSOR</H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                                   // headers
                                   out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                                   out<<"<cellspacing=10 cellpadding=3>";
                                   for (int column = 0; column < columnCount; column++)
                                       if (!ui->tableView->isColumnHidden(column))
                                           out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
                                   out << "</tr></thead>\n";

                                   // data table
                                   for (int row = 0; row < rowCount; row++) {
                                       out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                                       for (int column = 0; column < columnCount; column++) {
                                           if (!ui->tableView->isColumnHidden(column)) {
                                               QString data = ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
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
//recherche
void windowsponsor::on_lineEdit_17_textChanged(const QString &arg1)
{
    sponsor e ;
    //ui->tableView->setModel(e.rechercherc(arg1));
    if (ui->checkBox->isChecked()){
           ui->tableView->setModel(e.rechercher1(arg1));
       }
       if (ui->checkBox_2->isChecked()){
          ui->tableView->setModel(e.rechercher2(arg1));
       }
       if (ui->checkBox_3->isChecked()){
          ui->tableView->setModel(e.rechercher3(arg1));
       }
       if (ui->checkBox_4->isChecked()){
          ui->tableView->setModel(e.rechercher4(arg1));
       }

}




void windowsponsor::on_pushButton_3_clicked()
{
   ui->stackedWidget->setCurrentIndex(4);
}

void windowsponsor::on_pushButton_10_clicked()
{
   ui->stackedWidget->setCurrentIndex(0);
}

void windowsponsor::on_pushButton_7_clicked()
{
    Smtp* smtp = new Smtp("ramzi.bennaser@esprit.tn","201JMT3256","smtp.gmail.com",465);
           connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

           smtp->sendMail("ramzi.bennaser@esprit.tn",ui->mail->text(),ui->subject->text(),ui->body->text());
}
