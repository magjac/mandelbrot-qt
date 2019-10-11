#-------------------------------------------------
#
# Project created by QtCreator 2019-10-10T10:40:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mandelbrot
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mandelbrot.cpp

HEADERS  += mainwindow.h \
    mandelbrot.h

FORMS    += mainwindow.ui

CONFIG += c++11
QMAKE_CXXFLAGS += -ffast-math
