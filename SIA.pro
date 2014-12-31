#-------------------------------------------------
#
# Project created by QtCreator 2014-11-27T17:05:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SIA
TEMPLATE = app

win32:RESOURCES += \
    application.qrc

# Include winsock2.h
win32:DEFINES += _WINSOCKAPI_

unix {
QMAKE_CXXFLAGS += -std=c++11
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
    login/formlogin.cpp \
    mainwindow/mainwindow.cpp \
    mainwindow/teacherspage/teachers.cpp \
    mainwindow/teacherspage/teachersmodel.cpp \
    mainwindow/homepage/home.cpp

HEADERS  += login/formlogin.h\
    mainwindow/mainwindow.h \
    mainwindow/teacherspage/teachers.h \
    mainwindow/teacherspage/teachersmodel.h \
    mainwindow/homepage/home.h

FORMS    +=

win32:CONFIG(release, debug|release): LIBS += \
    -LD:/Aplikasi/MongoDB/mongo-lib/lib/ -llibmongoclient \
    -LC:/boost/lib/ -llibboost_thread-vc120-mt-1_57 \
    -LC:/boost/lib/ -llibboost_system-vc120-mt-1_57 \
    -LC:/boost/lib/ -llibboost_date_time-vc120-mt-1_57 \
    -LC:/boost/lib/ -llibboost_chrono-vc120-mt-1_57
else:win32:CONFIG(debug, debug|release): LIBS += \
    -LD:/Aplikasi/MongoDB/mongo-lib/lib/ -llibmongoclient-gd \
    -LC:/boost/lib/ -llibboost_thread-vc120-mt-gd-1_57 \
    -LC:/boost/lib/ -llibboost_system-vc120-mt-gd-1_57 \
    -LC:/boost/lib/ -llibboost_date_time-vc120-mt-gd-1_57 \
    -LC:/boost/lib/ -llibboost_chrono-vc120-mt-gd-1_57

win32:INCLUDEPATH += \
    D:/Aplikasi/MongoDB/mongo-lib/include \
    C:/boost/include/boost-1_57 \
    $$PWD/
win32:DEPENDPATH += \
    D:/Aplikasi/MongoDB/mongo-lib/include \
    C:/boost/include/boost-1_57
