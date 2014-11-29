#-------------------------------------------------
#
# Project created by QtCreator 2014-11-27T17:05:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SIA
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

unix {
LIBS += -pthread\
        -lmongoclient \
        -lboost_thread \
        -lboost_system \
        -lboost_regex \
        -lboost_filesystem \
        -lssl \
        -lcrypto
}

SOURCES += main.cpp\
    mainwindow.cpp \
    formlogin.cpp \
    config.cpp \
    library/md5.cpp

HEADERS  += \
    formlogin.h \
    config.h \
    mainwindow.h \
    library/md5.h

FORMS    +=
