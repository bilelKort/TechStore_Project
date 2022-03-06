#ifndef AJOUTERLIVRAISON_H
#define AJOUTERLIVRAISON_H

#include <QDialog>

namespace Ui {
class AjouterLivraison;
}

class AjouterLivraison : public QDialog
{
    Q_OBJECT

public:
    explicit AjouterLivraison(QWidget *parent = nullptr);
    ~AjouterLivraison();

private:
    Ui::AjouterLivraison *ui;
};

#endif // AJOUTERLIVRAISON_H
