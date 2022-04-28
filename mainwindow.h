#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include "arduino.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
namespace Ui {
class Mainwindow;
}

class Mainwindow : public QDialog
{
    Q_OBJECT

public:
    explicit Mainwindow(QWidget *parent = nullptr);
    ~Mainwindow();
private slots:
    void update_label();
    void on_pushButton_clicked();

private:
    Ui::Mainwindow *ui;
    QByteArray data; // variable contenant les données reçues
    Arduino A; // objet temporaire
    int i=1;
};

#endif // MAINWINDOW_H
