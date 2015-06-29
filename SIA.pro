#-------------------------------------------------
#
# Project created by QtCreator 2014-11-27T17:05:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SIA
TEMPLATE = app

RESOURCES += \
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
    mainwindow/teacherspage/teachers.cpp \
    mainwindow/teacherspage/teachersmodel.cpp \
    mainwindow/homepage/home.cpp \
    login/form_login.cpp \
    mainwindow/main_window.cpp \
    login/form_login_model.cpp \
    mainwindow/teacherspage/crud_teacher.cpp

HEADERS  +=\
    mainwindow/teacherspage/teachers.h \
    mainwindow/teacherspage/teachersmodel.h \
    mainwindow/homepage/home.h \
    login/form_login.h \
    mainwindow/main_window.h \
    login/form_login_model.h \
    mainwindow/teacherspage/crud_teacher.h

FORMS    +=

win32:CONFIG(release, debug|release): LIBS += \
    -LF:/workspaces/mongo-install/lib/ -llibmongoclient \
    -LF:/Data/Software/Mongodb/boost_1_58_0/stage/lib/ -llibboost_thread-vc120-mt-1_58 \
    -LF:/Data/Software/Mongodb/boost_1_58_0/stage/lib/ -llibboost_system-vc120-mt-1_58 \
    -LF:/Data/Software/Mongodb/boost_1_58_0/stage/lib/ -llibboost_date_time-vc120-mt-1_58 \
    -LF:/Data/Software/Mongodb/boost_1_58_0/stage/lib/ -llibboost_chrono-vc120-mt-1_58
else:win32:CONFIG(debug, debug|release): LIBS += \
    -LF:/workspaces/mongo-install/lib/ -llibmongoclient-gd \
    -LF:/Data/Software/Mongodb/boost_1_58_0/stage/lib/ -llibboost_thread-vc120-mt-gd-1_58 \
    -LF:/Data/Software/Mongodb/boost_1_58_0/stage/lib/ -llibboost_system-vc120-mt-gd-1_58 \
    -LF:/Data/Software/Mongodb/boost_1_58_0/stage/lib/ -llibboost_date_time-vc120-mt-gd-1_58 \
    -LF:/Data/Software/Mongodb/boost_1_58_0/stage/lib/ -llibboost_chrono-vc120-mt-gd-1_58

win32:INCLUDEPATH += \
    F:/workspaces/mongo-install/include \
    F:/Data/Software/Mongodb/boost_1_58_0 \
    $$PWD/
win32:DEPENDPATH += \
    F:/workspaces/mongo-install/include \
    F:/Data/Software/Mongodb/boost_1_58_0

# Disable warning
win32:CONFIG += warn_off
