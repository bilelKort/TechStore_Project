#ifndef CLASSLIVRAISON_H
#define CLASSLIVRAISON_H
#include <QtSql>
#include <QSqlDatabase>
#include <QDialog>
#include <QMessageBox>
#include <QString>
#include <QSqlQueryModel>

class Classlivraison
{
    private:
    int cin;
    QString nomLivreur;
    QString adresse;
    int telLivreur;
    QString diplome;

public:
    Classlivraison(int cin=0,QString nomLivreur="",QString adresse="",int telLivreur=0,QString diplome="");
    bool ajouter();
    bool modifier(int);
    bool supprimer(int);
    QSqlQueryModel * afficher();
    QSqlQueryModel * suppcombo();
    QSqlQueryModel * recherche(QString adresserech);
    QSqlQueryModel * trie();

};

#endif // CLASSLIVRAISON_H
