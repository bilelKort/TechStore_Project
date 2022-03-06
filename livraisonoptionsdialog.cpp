#include "livraisonoptionsdialog.h"
#include "ui_livraisonoptionsdialog.h"

livraisonOptionsDialog::livraisonOptionsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::livraisonOptionsDialog)
{
    ui->setupUi(this);
}

livraisonOptionsDialog::~livraisonOptionsDialog()
{
    delete ui;
}
