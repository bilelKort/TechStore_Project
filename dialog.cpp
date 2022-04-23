#include "dialog.h"
#include "ui_dialog.h"

dialog::dialog(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::dialog)
{
    ui->setupUi(this);

    //Configurer un panneau d'affichage vide
    ui->displayPanel->clear();

    //Définissez les indicateurs d'opérateur et de numéro de magasin sur faux
    operatorClicked = false;
    hasStoredNumber = false;
    // Définir l'écouteur du groupe de boutons numériques
    ui->numberGroup->connect(ui->numberGroup,SIGNAL(buttonClicked(QAbstractButton*)),
                             this, SLOT(numberGroup_clicked(QAbstractButton*)));
    //Définir l'écouteur du groupe de boutons de l'opérateur
    ui->actionGroup->connect(ui->actionGroup,SIGNAL(buttonClicked(QAbstractButton*)),
                             this, SLOT(actionGroup_clicked(QAbstractButton*)));

    //Définir la largeur et la hauteur fixes de la fenêtre
    this->setFixedSize(QSize(306, 319));
}

dialog::~dialog()
{
    delete ui;
}

//==================================================================================
//Slot functions
//==================================================================================
//Appelé chaque fois qu'un bouton numérique est cliqué
void dialog::numberGroup_clicked(QAbstractButton* button)
{
    //Get string from display
    QString displayLabel = ui->displayPanel->text();

    /* Check if the previous button that was clicked was an operator button.
     * If so, clear the display and set the flag to false. Then proceed to
     * add the digit requested. */
    if (operatorClicked) {
        displayLabel.clear();
        operatorClicked = false;
    }

    //Ajouter le chiffre uniquement si nous ne dépassons pas la limite de chiffres
    if (displayLabel.length() >= DIGIT_LIMIT) {
        return;
    }


   // Ajouter le chiffre demandé
    displayLabel.append(button->text());

    //Remettre le numéro à afficher
    ui->displayPanel->setText(displayLabel);
}

// Appelé chaque fois qu'un bouton d'action est cliqué
void dialog::actionGroup_clicked(QAbstractButton* button)
{
    /* If the previous button that was clicked was not an operator, then we just need to save the operator
     * that was requested and exit.
     * If it was though, we need to see whether we just need to save the number that is
     * displayed or if there is already a number stored in memory, perform the calculation and
     * store the result.
     * Example for this case: 5 + 7 + -> We need to save 12 in memory and then save operator. */

    if (operatorClicked) {
        storedOperator = button->text().at(0);
    }
    else {
        if (hasStoredNumber) {
            calculate_result();
        }
        else {
            //Définissez le drapeau pour indiquer que nous avons maintenant un nombre stocké en mémoire
            hasStoredNumber = true;

           // Obtenir la chaîne de l'affichage
            QString displayLabel = ui->displayPanel->text();
            //Convert string to double and save
            storedNumber = displayLabel.toDouble();
        }
        //Définissez le drapeau indiquant que le dernier bouton sur lequel vous avez cliqué était un opérateur
        operatorClicked = true;
        //Enregistrer l'opérateur en mémoire
        storedOperator = button->text().at(0);
    }
}

void dialog::on_actionDel_clicked()
{
    //Obtenir la chaîne de l'affichage
    QString displayLabel = ui->displayPanel->text();


    //Vérifiez si l'étiquette est vide
    if (displayLabel.length() == 0) {
        return;
    }

    //Supprimer le dernier chiffre de la chaîne
    displayLabel.QString::chop(1);
    //Remettre le numéro à afficher
    ui->displayPanel->setText(displayLabel);
}

void dialog::on_actionCalc_clicked()
{
    //Obtenir la chaîne de l'affichage
    QString displayLabel = ui->displayPanel->text();
    /* A number must be saved in memory to be able calculate a result.
     * In addition, a number with at least one digit should be present in the display and
     * The last button that was clicked should not be an operator */

    if (!hasStoredNumber || displayLabel.length() < 1 || operatorClicked) {
        return;
    }

    //Calculer le résultat et le mettre à l'écran
    calculate_result();

    //Définissez l'indicateur de numéro stocké sur faux (nous l'avons maintenant à l'écran)
    hasStoredNumber = false;

}

void dialog::on_comma_clicked()
{
    //Obtenir la chaîne de l'affichage
    QString displayLabel = ui->displayPanel->text();

    /* Append the digit only if we are not exceeding the digit limit.
     * More specifically in this case, we need 2 digits to be available.
     * One for the comma and at least another one for a remaining digit.
     * Also check if whether there is another comma already present. */
    if (displayLabel.length() >= (DIGIT_LIMIT - 1) ||
        displayLabel.contains('.', Qt::CaseSensitive)) {
        return;
    }

    //Si l'étiquette est vide, ajoutez zéro, puis ajoutez une virgule
    if (displayLabel.length() == 0) {
        displayLabel = "0";
    }

    //Ajouter une virgule
    displayLabel.append('.');

    //Remettre le numéro à afficher
    ui->displayPanel->setText(displayLabel);
}

void dialog::on_actionClear_clicked()
{
    //Effacer l'étiquette d'affichage (pour l'instant)
    ui->displayPanel->clear();
    //Définissez les indicateurs d'opérateur et de numéro de magasin sur faux
    operatorClicked = false;
    hasStoredNumber = false;
}

void dialog::on_actionPercent_clicked()
{
    //Obtenir la chaîne de l'affichage
    QString displayLabel = ui->displayPanel->text();
    //Convertir en double
    double percentage = displayLabel.toDouble();

   // Multipliez simplement par 0,01 pour en faire un pourcentage
    percentage *= 0.01;

    //Puisqu'il pourrait y avoir un débordement, il est préférable de convertir soigneusement le nombre
    displayLabel = QString::number(percentage,'g', DIGIT_LIMIT);
    //Remettre le numéro à afficher
    ui->displayPanel->setText(displayLabel);
}

void dialog::on_actionSign_clicked()
{

    //Obtenir la chaîne de l'affichage
    QString displayLabel = ui->displayPanel->text();
    //Convert to double
    double percentage = displayLabel.toDouble();
    //Il suffit de multiplier par -1 pour changer son signe
    percentage *= -1;
    //Convertissez soigneusement le nombre
    displayLabel = QString::number(percentage,'g', DIGIT_LIMIT);
//Remettre le numéro à afficher
    ui->displayPanel->setText(displayLabel);
}

//==================================================================================
//Helper functions
//==================================================================================
void dialog::calculate_result() {
    //Obtenir la chaîne de l'affichage
    QString displayLabel = ui->displayPanel->text();

    //Si le nombre affiché se termine par une virgule, supprimez la virgule
     if (displayLabel.endsWith('.',Qt::CaseSensitive)) {
         displayLabel.QString::chop(1);
     }

     //Décidez quoi faire en fonction de l'opération
     if (storedOperator == '+') {
         storedNumber += displayLabel.toDouble();
     }
     else if (storedOperator == '-') {
         storedNumber -= displayLabel.toDouble();
     }
     else if (storedOperator == 'x') {
         storedNumber *= displayLabel.toDouble();
     }
     else if (storedOperator == '/') {
         storedNumber /= displayLabel.toDouble();
     }

     //Puisqu'il pourrait y avoir un débordement, il est préférable de convertir soigneusement le nombre
     displayLabel = QString::number(storedNumber,'g', DIGIT_LIMIT);

     //remettre le numéro à afficher
     ui->displayPanel->setText(displayLabel);
}


//Les boutons du clavier doivent appeler les fonctions correspondantes
void dialog::keyPressEvent(QKeyEvent *e) {
    switch (e->key()) {
        //Numbers
        case Qt::Key_1:
            numberGroup_clicked(ui->num1);
            break;
        case Qt::Key_2:
            numberGroup_clicked(ui->num2);
            break;
        case Qt::Key_3:
            numberGroup_clicked(ui->num3);
            break;
        case Qt::Key_4:
            numberGroup_clicked(ui->num4);
            break;
        case Qt::Key_5:
            numberGroup_clicked(ui->num5);
            break;
        case Qt::Key_6:
            numberGroup_clicked(ui->num6);
            break;
        case Qt::Key_7:
            numberGroup_clicked(ui->num7);
            break;
        case Qt::Key_8:
            numberGroup_clicked(ui->num8);
            break;
        case Qt::Key_9:
            numberGroup_clicked(ui->num9);
            break;
        case Qt::Key_0:
            numberGroup_clicked(ui->num0);
            break;

            //Les opérateurs
        case Qt::Key_Plus:
            actionGroup_clicked(ui->actionPlus);
            break;
        case Qt::Key_Minus:
            actionGroup_clicked(ui->actionMinus);
            break;
        case Qt::Key_Asterisk:
            actionGroup_clicked(ui->actionMul);
            break;
        case Qt::Key_Slash:
            actionGroup_clicked(ui->actionDiv);
            break;
        //Virgule
        case Qt::Key_Period:
            on_comma_clicked();
            break;
        //Retour (entrer)
        case Qt::Key_Enter:
        case Qt::Key_Return:
            on_actionCalc_clicked();
            break;
        //Retour arrière et suppression
        case Qt::Key_Backspace:
            on_actionDel_clicked();
            break;
        case Qt::Key_Delete:
            on_actionClear_clicked();
            break;
        //Pourcentage
        case Qt::Key_Percent:
            on_actionPercent_clicked();
            break;
    }
}
