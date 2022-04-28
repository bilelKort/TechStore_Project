#ifndef WINDOWPRODUIT_H
#define WINDOWPRODUIT_H

#include <QDialog>
#include "connection.h"
#include "produit.h"

namespace Ui {
class windowproduit;
}

class windowproduit : public QDialog
{
    Q_OBJECT

public:
    explicit windowproduit(QWidget *parent = nullptr);
    ~windowproduit();

private slots:
    void on_addbtn_clicked();

    void on_editBtn_clicked();

    void on_ajouterprd_clicked();

    void on_editerprd_clicked();

    void on_suppBtn_clicked();

    void on_supprimerprd_clicked();

private:
    Ui::windowproduit *ui;
    produit prd;
};

#endif // WINDOWPRODUIT_H
