#ifndef WINDOWEMPLOYE_H
#define WINDOWEMPLOYE_H

#include <QDialog>
#include <QMainWindow>
#include <QString>
#include <QMainWindow>
#include <QMessageBox>
#include "arduino.h"

namespace Ui {
class windowemploye;
}

class windowemploye : public QDialog
{
    Q_OBJECT

public:
    explicit windowemploye(QWidget *parent = nullptr);
    ~windowemploye();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_lineEdit_16_textChanged(const QString &arg1);




        void on_pushButton_19_clicked();

        void on_pushButton_20_clicked();

        void on_pushButton_21_clicked();

        void on_pushButton_7_clicked();

        void on_pushButton_14_clicked();

private:
    Ui::windowemploye *ui;
    QByteArray data ;
    Arduino A ;

};

#endif // WINDOWEMPLOYE_H
