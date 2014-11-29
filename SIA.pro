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
win32DEPENDPATH += \
    $$PWD/../../mongo/mongo-client/include\
    C:/Boost/include/boost-1_56
