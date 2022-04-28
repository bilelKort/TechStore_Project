#ifndef WINDOWSPONSOR_H
#define WINDOWSPONSOR_H

#include <QDialog>
#include "sponsor.h"
namespace Ui {
class windowsponsor;
}

class windowsponsor : public QDialog
{
    Q_OBJECT

public:
    explicit windowsponsor(QWidget *parent = nullptr);
    ~windowsponsor();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_16_clicked();

    void on_lineEdit_7_textChanged(const QString &arg1);

    void on_pushButton_10_clicked();

    void on_mailling_clicked();

    void on_pushButton_4_clicked();

    void on_lineEdit_17_textChanged(const QString &arg1);

    void on_pushButton_3_clicked();

    void on_pushButton_7_clicked();



private:
    Ui::windowsponsor *ui;
sponsor e;
};

#endif // WINDOWSPONSOR_H
