#ifndef LIVRAISONOPTIONSDIALOG_H
#define LIVRAISONOPTIONSDIALOG_H

#include <QDialog>

namespace Ui {
class livraisonOptionsDialog;
}

class livraisonOptionsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit livraisonOptionsDialog(QWidget *parent = nullptr);
    ~livraisonOptionsDialog();

private:
    Ui::livraisonOptionsDialog *ui;
};

#endif // LIVRAISONOPTIONSDIALOG_H
