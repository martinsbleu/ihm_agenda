#-------------------------------------------------
#
# Project created by QtCreator 2018-02-21T13:56:56
#
#-------------------------------------------------

QT       += core gui #on rajoute la GUI
QT       += sql #on rajoute SQL

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QTPLUGIN += qsqlmysql
TARGET = Prototype  # La cible de compilation, le résultat
TEMPLATE = app # On veut une application, oui

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \  # La liste des fichiers de source
        main.cpp \
        agenda.cpp

HEADERS += \
        agenda.h

FORMS += \
        agenda.ui



win32: LIBS += -LC:/MySql/mysql-connector-c-6.1.11-win32/lib/ -llibmysql

INCLUDEPATH += C:/MySql/mysql-connector-c-6.1.11-win32/include
DEPENDPATH += C:/MySql/mysql-connector-c-6.1.11-win32/include

#win32: LIBS += -LC:/MySql/lib/ -llibmysql

#INCLUDEPATH += C:/MySql/include
#DEPENDPATH += C:/MySql/include
