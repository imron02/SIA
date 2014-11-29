/*
|-------------------------------------------------------------------------------
| Name:        mainwindow.h
| Author:      Imron Rosdiana
| Modified by:
| Created:     2014-11-28
| Copyright:   (C) Copyright 2014, Imron Rosdiana
| Licence:     GPL (General Public License) V.3
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStatusBar>
#include <QMenu>
#include <QMenuBar>
#include <QShortcut>
#include <QMessageBox>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();

private slots:
    void AboutApp();

private:
    void CreateAct();
    void CreateMenus();
    void AboutQt();

    QMenu* fileMenu;
    QMenu* editMenu;
    QMenu* helpMenu;
    QAction* undoAct;
    QAction* redoAct;
    QAction* quitAct;
    QAction* cutAct;
    QAction* copyAct;
    QAction* pasteAct;
    QAction* deleteAct;
    QAction* aboutAct;
    QAction* aboutQtAct;
};

#endif // MAINWINDOW_H
