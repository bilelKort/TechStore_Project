#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_2_clicked()
{
    livraison = new livraisonDialog;
    livraison->show();
}


void Widget::on_pushButton_3_clicked()
{
    command = new windowCommand;
    command->show();
}

void Widget::on_pushButton_6_clicked()
{
    fournisseur = new windowfournisseur;
    fournisseur->show();
}

void Widget::on_pushButton_5_clicked()
{
    sponsor = new windowsponsor;
    sponsor->show();
}

void Widget::on_pushButton_clicked()
{
    employe = new windowemploye;
    employe->show();
}

void Widget::on_pushButton_4_clicked()
{
    produit = new windowproduit;
    produit->show();
}
