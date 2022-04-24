#ifndef WINDOWCOMMAND_H
#define WINDOWCOMMAND_H

#include <QDialog>
#include "connection.h"
#include "commande.h"
namespace Ui {
class windowCommand;
}

class windowCommand : public QDialog
{
    Q_OBJECT

public:
    explicit windowCommand(QWidget *parent = nullptr);
    ~windowCommand();

private slots:
    void on_Ajouter_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_4_clicked();

    void on_buttonAjout_clicked();



    void on_button_supprimer_clicked();

    void on_buttonAfficher_clicked();

    void on_pushButton_clicked();

    void on_pushButton_8_clicked();

    void on_Menu_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_13_clicked();

    void on_ButtonModifier_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_21_clicked();

    void on_lineEdit_5_textChanged(const QString &arg1);

    void on_order_clicked();

    void on_qrCode_clicked();

private:
    Ui::windowCommand *ui;
    Commande C;
    int ord;
};

#endif // WINDOWCOMMAND_H
