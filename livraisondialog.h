#ifndef LIVRAISONDIALOG_H
#define LIVRAISONDIALOG_H

#include "classlivraison.h"
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QDialog>
#include <QMessageBox>
#include <QSystemTrayIcon>
#include "ui_livraisondialog.h"
#include "connection.h"
#include <QTcpSocket>


namespace Ui {
class livraisonDialog;
}

class livraisonDialog : public QDialog
{
    Q_OBJECT

public:
    explicit livraisonDialog(QWidget *parent = nullptr);
    ~livraisonDialog();

private slots:
    void on_addbtn_clicked();
    void on_ajouterbtn_clicked();
    void on_editBtn_clicked();
    void on_suppBtn_clicked();
    void on_editerbtn_clicked();
    void on_supprimerbtn_clicked();
    void on_chercherbtn_clicked();
    void on_tri_clicked();
    void on_tabWidget_currentChanged(int index);

    void on_CHAT_clicked();

private:
    Ui::livraisonDialog *ui;
    Classlivraison livra;
    QTcpSocket*mSocket;

};

#endif // LIVRAISONDIALOG_H
