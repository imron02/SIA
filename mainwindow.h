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

QT_BEGIN_NAMESPACE
class QAction;
class QMenu;
class QPlainTextEdit;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = 0);
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
