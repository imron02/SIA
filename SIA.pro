#-------------------------------------------------
#
# Project created by QtCreator 2014-11-27T17:05:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

<<<<<<< HEAD
TARGET = SIA
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

unix {
=======
RESOURCES += \
    application.qrc

TARGET = SIA
TEMPLATE = app

win32: QMAKE_CXXFLAGS += /wd4100

unix {
QMAKE_CXXFLAGS += -std=c++11
>>>>>>> 5401ce1ae65b8f52c140de1906727b13f55d8512
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
<<<<<<< HEAD
    formlogin.cpp \
    config.cpp \
    library/md5.cpp

HEADERS  += \
    formlogin.h \
    config.h \
    mainwindow.h \
    library/md5.h

FORMS    +=
=======
    library/md5.cpp \
    config.cpp \
    formlogin.cpp

HEADERS  += \
    mainwindow.h \
    library/md5.h \
    config.h \
    formlogin.h

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

INCLUDEPATH += \
    $$PWD/../../mongo/mongo-client/include \
    C:/Boost/include/boost-1_56
DEPENDPATH += \
    $$PWD/../../mongo/mongo-client/include\
    C:/Boost/include/boost-1_56
>>>>>>> 5401ce1ae65b8f52c140de1906727b13f55d8512
