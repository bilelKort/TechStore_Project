QT       += core gui sql printsupport
QT += widgets location network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets quickwidgets

CONFIG += c++11
CONFIG += console

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0



SOURCES += \
    classlivraison.cpp \
    connection.cpp \
    livraisondialog.cpp \
    main.cpp \
    qcustomplot.cpp \
    widget.cpp

HEADERS += \
    classlivraison.h \
    connection.h \
    livraisondialog.h \
    qcustomplot.h \
    widget.h

FORMS += \
    livraisondialog.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    qml.qrc \
    src.qrc

DISTFILES +=
QMAKE_CXXFLAGS += -std=gnu++11
