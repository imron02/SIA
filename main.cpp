/*
|-------------------------------------------------------------------------------
| Name:        main.cpp
| Author:      Imron Rosdiana
| Modified by:
| Created:     2014-11-27
| Copyright:   (C) Copyright 2014, Imron Rosdiana
| Licence:     GPL (General Public License) V.3
*/

#include "formlogin.h"
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow* mainWindow = new MainWindow();
    FormLogin* formLogin = new FormLogin(mainWindow);
    mainWindow->show();
    formLogin->show();

    return a.exec();
}
