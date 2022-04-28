QT       += core gui sql printsupport widgets location network
QT       += serialport
greaterThan(QT_MAJOR_VERSION, 4): QT +=  widgets quickwidgets

CONFIG += c++11
CONFIG += console
#LIBS += -LC:\Program Files (x86)\OpenSSL-Win32\lib -lubsec
#INCLUDEPATH += C:\Program Files (x86)\OpenSSL-Win32\include
PKGCONFIG += openssl
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    arduino.cpp \
    classlivraison.cpp \
    commande.cpp \
    connection.cpp \
    dialog.cpp \
    employe.cpp \
    enregistrement.cpp \
    enregistrementlivraison.cpp \
    fournisseurs.cpp \
    livraisondialog.cpp \
    main.cpp \
    mainwindow.cpp \
    map.cpp \
    notification.cpp \
    produit.cpp \
    qcustomplot.cpp \
    qrcode.cpp \
    smtp.cpp \
    sponsor.cpp \
    widget.cpp \
    windowcommand.cpp \
    windowemploye.cpp \
    windowfournisseur.cpp \
    windowproduit.cpp \
    windowsponsor.cpp

HEADERS += \
    arduino.h \
    classlivraison.h \
    commande.h \
    connection.h \
    dialog.h \
    employe.h \
    enregistrement.h \
    enregistrementlivraison.h \
    fournisseurs.h \
    livraisondialog.h \
    mainwindow.h \
    map.h \
    notification.h \
    produit.h \
    qcustomplot.h \
    qrcode.h \
    smtp.h \
    sponsor.h \
    widget.h \
    windowcommand.h \
    windowemploye.h \
    windowfournisseur.h \
    windowproduit.h \
    windowsponsor.h

FORMS += \
    commande.ui \
    dialog.ui \
    livraisondialog.ui \
    login.ui \
    mainwindow.ui \
    map.ui \
    widget.ui \
    windowcommand.ui \
    windowemploye.ui \
    windowfournisseur.ui \
    windowproduit.ui \
    windowsponsor.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    qml.qrc \
    resource2.qrc \
    src.qrc

DISTFILES +=
QMAKE_CXXFLAGS += -std=gnu++11

SUBDIRS += \
    calcul.pro
