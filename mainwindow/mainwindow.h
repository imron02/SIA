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
class QSignalMapper;
class QStringList;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = 0);
    ~MainWindow();

private slots:
    void cut();
    void AboutApp();
    void CloseTab(int);
    void PageToolbar(const QString&);
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
    QMenu* dataMenu;

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
    QAction* homeAct;
    QAction* showFullScreenAct;
    QAction* editToolBarAct;
    QAction* fileToolBarAct;
    QAction* teachersAct;

    QToolBar* fileToolBar;
    QToolBar* editToolBar;

    QTabWidget* page;

    // signal mapper
    QSignalMapper* signalMapper;
};

#endif // MAINWINDOW_H
