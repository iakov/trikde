#-------------------------------------------------
#
# Project created by QtCreator 2013-07-08T16:35:40
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = trikde
TEMPLATE = app


SOURCES += main.cpp\
        startWidget.cpp \
    baseWidget.cpp \
    fileManagerWidget.cpp \
    showIPAddressWidget.cpp \
    showNetConfigWidget.cpp

HEADERS  += startWidget.h \
    baseWidget.h \
    fileManagerWidget.h \
    showIPAddressWidget.h \
    showNetConfigWidget.h
