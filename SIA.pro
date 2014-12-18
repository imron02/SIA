#-------------------------------------------------
#
# Project created by QtCreator 2014-11-27T17:05:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SIA
TEMPLATE = app

win32:RESOURCES +=

win32: QMAKE_CXXFLAGS += /wd4100

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
    library/md5.cpp \
    mainwindow/mainwindow.cpp \
    config/config.cpp \
    mainwindow/homepage/pagehome.cpp \
    mainwindow/teacherspage/teachers.cpp \
    mainwindow/teacherspage/teachersmodel.cpp

HEADERS  += login/formlogin.h\
    library/md5.h \
    mainwindow/mainwindow.h \
    config/config.h \
    mainwindow/homepage/pagehome.h \
    mainwindow/teacherspage/teachers.h \
    mainwindow/teacherspage/teachersmodel.h

FORMS    +=

win32:CONFIG(release, debug|release): LIBS += \
    -L$$PWD/../../mongo/mongo-client/lib/ -llibmongoclient \
    -L$$PWD/../../mongo/mongo-client/lib/ -lmongoclient \
    -LC:/Boost/lib/ -lboost_thread-vc120-mt-1_56 \
    -LC:/Boost/lib/ -lboost_system-vc120-mt-1_56 \
    -LC:/Boost/lib/ -lboost_date_time-vc120-mt-1_56 \
    -LC:/Boost/lib/ -lboost_chrono-vc120-mt-1_56
else:win32:CONFIG(debug, debug|release): LIBS += \
    -L$$PWD/../../mongo/mongo-client/lib/ -llibmongoclient-gd \
    -L$$PWD/../../mongo/mongo-client/lib/ -lmongoclient-gd \
    -LC:/Boost/lib/ -lboost_thread-vc120-mt-gd-1_56 \
    -LC:/Boost/lib/ -lboost_system-vc120-mt-gd-1_56 \
    -LC:/Boost/lib/ -lboost_date_time-vc120-mt-gd-1_56 \
    -LC:/Boost/lib/ -lboost_chrono-vc120-mt-gd-1_56

win32:INCLUDEPATH += \
    $$PWD/../../mongo/mongo-client/include \
    C:/Boost/include/boost-1_56
win32:DEPENDPATH += \
    $$PWD/../../mongo/mongo-client/include\
    C:/Boost/include/boost-1_56
