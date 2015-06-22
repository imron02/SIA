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

#include "mainwindow/main_window.h"
#include "login/form_login.h"

int main(int argc, char* argv[]) {
  Q_INIT_RESOURCE(application);

  QApplication app(argc, argv);
  MainWindow* mainWindow = new MainWindow();
//  FormLogin* formLogin = new FormLogin(mainWindow);
  mainWindow->show();
//  formLogin->show();

  return app.exec();
}
