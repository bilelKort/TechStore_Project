#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "livraisondialog.h"
#include "windowcommand.h"
#include "windowfournisseur.h"
#include "windowsponsor.h"
#include "windowemploye.h"
#include "windowproduit.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Widget *ui;
    livraisonDialog *livraison;
    windowCommand * command;
    windowfournisseur * fournisseur;
    windowsponsor* sponsor;
    windowemploye *employe;
    windowproduit *produit;
};
#endif // WIDGET_H
