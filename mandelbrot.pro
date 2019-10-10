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
    mandelbrot.cpp \
    complex.cpp

HEADERS  += mainwindow.h \
    mandelbrot.h \
    complex.h

FORMS    += mainwindow.ui
