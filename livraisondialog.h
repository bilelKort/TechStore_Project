#ifndef LIVRAISONDIALOG_H
#define LIVRAISONDIALOG_H

#include "classlivraison.h"
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QDialog>
#include <QMessageBox>
#include "ui_livraisondialog.h"
#include "connection.h"


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

private:
    Ui::livraisonDialog *ui;
    Classlivraison livra;
};

#endif // LIVRAISONDIALOG_H
