#-------------------------------------------------
#
# Project created by QtCreator 2017-04-20T19:17:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    bullet.cpp \
    enemy.cpp \
    enemybullet.cpp \
    score.cpp \
    health.cpp \
    energy.cpp \
    enemyhealth.cpp

HEADERS  += mainwindow.h \
    score.h \
    bullet.h \
    enemy.h \
    enemybullet.h \
    health.h \
    energy.h \
    enemyhealth.h \
    poly.h

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc
