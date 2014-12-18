/*
|-------------------------------------------------------------------------------
| Name:        main.cpp
| Author:      Imron Rosdiana
| Modified by:
| Created:     2014-11-27
| Copyright:   (C) Copyright 2014, Imron Rosdiana
| Licence:     GPL (General Public License) V.3
*/

#include <QApplication>
#include <QtPlugin>

#include "mainwindow/mainwindow.h"
#include "login/formlogin.h"

int main(int argc, char* argv[])
{
    #ifdef _WIN32
        Q_INIT_RESOURCE(application);
    #endif // _WIN32

    QApplication app(argc, argv);
    MainWindow* mainWindow = new MainWindow();
//    FormLogin* formLogin = new FormLogin(mainWindow);
//    formLogin->show();
    mainWindow->show();

    return app.exec();
}
