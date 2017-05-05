#-------------------------------------------------
#
# Project created by QtCreator 2014-08-08T17:16:56
# What what
#-------------------------------------------------

QT       += core gui
QT       += sensors

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TiltingIsing
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

INCLUDEPATH += d:\Kody\Libs\


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

CONFIG += mobility
MOBILITY = 

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

OTHER_FILES += \
    android/AndroidManifest.xml

