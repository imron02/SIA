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
class QToolBar;
class QSignalMapper;
class QStringList;
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget* parent = 0);
  ~MainWindow();

 private slots:
  void cut();
  void AboutApp();
  void CloseTab(const int& index);
  void PageToolbar(const QString&);
  void FullScreenToggle();

 private:
  void CreateAct();
  void CreateMenus();
  void CreateToolBars();
  void CreateTabWidgets();

  QMenu* file_menu_;
  QMenu* edit_menu_;
  QMenu* help_menu_;
  QMenu* window_menu_;
  QMenu* data_menu_;

  QAction* undo_act_;
  QAction* redo_act_;
  QAction* quit_act_;
  QAction* cut_act_;
  QAction* copy_act_;
  QAction* paste_act_;
  QAction* delete_act_;
  QAction* about_act_;
  QAction* aboutqt_act_;
  QAction* back_act_;
  QAction* next_act_;
  QAction* home_act_;
  QAction* show_fullscreen_act_;
  QAction* edit_toolbar_act_;
  QAction* file_toolbar_act_;
  QAction* teachers_act_;

  QToolBar* file_toolbar_;
  QToolBar* edit_toolbar_;
  QTabWidget* page_;

  // signal mapper
  QSignalMapper* signalmapper_;
};

#endif // MAINWINDOW_H
