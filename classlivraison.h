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
    int quantite;

public:
    Classlivraison(int cin=0,QString nomLivreur="",QString adresse="",int telLivreur=0,QString diplome="",int quantite=0);
    bool ajouter();
    bool modifier(int);
    bool supprimer(int);
    QSqlQueryModel * afficher();
    QSqlQueryModel * suppcombo();
    QSqlQueryModel * recherche(QString adresserech);
    QSqlQueryModel * trie();
    void statistique(QVector<double>* ticks,QVector<QString> *labels);

};

#endif // CLASSLIVRAISON_H
