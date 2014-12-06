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
#include <QDebug>

#include <iostream>

QT_BEGIN_NAMESPACE
class QAction;
class QMenu;
class QTabWidget;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow();
    ~MainWindow();

private slots:
    void AboutApp();
    void CloseTab(int);
    void FullScreenToggle();

private:
    void CreateAct();
    void CreateMenus();
    void CreateToolBars();
    void CreateTabWidgets();

    QMenu* fileMenu;
    QMenu* editMenu;
    QMenu* helpMenu;
    QMenu* windowMenu;
    QAction* undoAct;
    QAction* redoAct;
    QAction* quitAct;
    QAction* cutAct;
    QAction* copyAct;
    QAction* pasteAct;
    QAction* deleteAct;
    QAction* aboutAct;
    QAction* aboutQtAct;
    QAction* backAct;
    QAction* nextAct;
    QAction* showFullScreenAct;
    QAction* editToolBarAct;
    QAction* fileToolBarAct;
    QToolBar* fileToolBar;
    QToolBar* editToolBar;
    QTabWidget* page;
};

#endif // MAINWINDOW_H
