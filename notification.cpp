#include "notification.h"

Notification::Notification()
{

}

void Notification::notification_ajoutab()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    notifyIcon->show();
    notifyIcon->showMessage("gestion des fournisseurs "," fournisseur ajouté ",QSystemTrayIcon::Information,15000);
}

void Notification::notification_supprimerab(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    notifyIcon->show();
    notifyIcon->showMessage("gestion des fournisseurs "," fournisseur supprimé ",QSystemTrayIcon::Information,15000);
}


void Notification::notification_modifierab(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    notifyIcon->show();
    notifyIcon->showMessage("gestion des fournisseurs "," fournisseur modifié  ",QSystemTrayIcon::Information,15000);

}
