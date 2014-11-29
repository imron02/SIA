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
<<<<<<< HEAD
#include <QStatusBar>
#include <QMenu>
#include <QMenuBar>
#include <QShortcut>
#include <QMessageBox>
=======

QT_BEGIN_NAMESPACE
class QAction;
class QMenu;
class QPlainTextEdit;
QT_END_NAMESPACE
>>>>>>> 5401ce1ae65b8f52c140de1906727b13f55d8512

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
<<<<<<< HEAD
    MainWindow();
=======
    explicit MainWindow(QWidget* parent = 0);
>>>>>>> 5401ce1ae65b8f52c140de1906727b13f55d8512
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
