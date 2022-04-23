#ifndef DIALOG_H
#define DIALOG_H

#include <QMainWindow>
#include <QAbstractButton>
#include <QKeyEvent>

namespace Ui { class dialog; }

class dialog : public QMainWindow
{
    Q_OBJECT

public:
    explicit dialog(QWidget *parent = 0);
    ~dialog();

private slots:
    void numberGroup_clicked(QAbstractButton*);
    void actionGroup_clicked(QAbstractButton*);

    void on_actionDel_clicked();
    void on_actionCalc_clicked();
    void on_comma_clicked();
    void on_actionClear_clicked();
    void on_actionPercent_clicked();
    void on_actionSign_clicked();

private:
    Ui::dialog *ui;
    //Digit limit
    const int DIGIT_LIMIT = 16;
    //Flag to check whether the previous button that was clicked was an operator
    bool operatorClicked;
    //Last operator requested
    QChar storedOperator;
    //Flag to check whether a number is stored in memory
    bool hasStoredNumber;
    //Stored number
    double storedNumber;
    //Calculate result based on stored number and displayed number
    void calculate_result();

protected:
    void keyPressEvent(QKeyEvent *e);
};

#endif // DIALOG_H
