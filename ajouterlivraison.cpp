#include "ajouterlivraison.h"
#include "ui_ajouterlivraison.h"

AjouterLivraison::AjouterLivraison(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AjouterLivraison)
{
    ui->setupUi(this);
}

AjouterLivraison::~AjouterLivraison()
{
    delete ui;
}
