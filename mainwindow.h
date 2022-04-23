#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "fournisseurs.h"
#include "notification.h"
#include "dialog.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_pushButton_5_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_10_clicked();

    void on_pb_ajouter_2_clicked();

    void on_pushButton_18_clicked();

    void on_pb_supp_clicked();

    void on_pushButton_19_clicked();


    void on_pb_modi_clicked();

    void on_pb_supp_2_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_11_clicked();

    void on_pb_rech_clicked();

    void on_pb_tri_clicked();

    void on_pb_pdf_clicked();

    void on_pushButton_13_clicked();



private:
    Ui::MainWindow *ui;
    Fournisseurs F;
    Notification n;
    dialog d;
};

#endif // MAINWINDOW_H
