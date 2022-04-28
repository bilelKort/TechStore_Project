#ifndef WINDOWFOURNISSEUR_H
#define WINDOWFOURNISSEUR_H

#include <QDialog>
#include "fournisseurs.h"
#include "notification.h"
#include "dialog.h"
namespace Ui {
class windowfournisseur;
}

class windowfournisseur : public QDialog
{
    Q_OBJECT

public:
    explicit windowfournisseur(QWidget *parent = nullptr);
    ~windowfournisseur();

private slots:

    void on_pb_ajouter_2_clicked();

    void on_pb_supp_clicked();

    void on_pb_modi_clicked();

    void on_pb_rech_clicked();

    void on_pb_tri_clicked();

    void on_pb_pdf_clicked();

    void on_pushButton_13_clicked();




private:
    Ui::windowfournisseur *ui;
    Fournisseurs F;
    Notification n;
    dialog d;
};

#endif // WINDOWFOURNISSEUR_H
