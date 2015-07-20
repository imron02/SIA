/*
|-------------------------------------------------------------------------------
| Name:        mainwindow.cpp
| Author:      Imron Rosdiana
| Modified by:
| Created:     2014-11-28
| Copyright:   (C) Copyright 2014, Imron Rosdiana
| Licence:     GPL (General Public License) V.3
*/

#include <QtWidgets>
#include <QDebug>
#include "mainwindow/main_window.h"
#include "mainwindow/homepage/home.h"
#include "mainwindow/teacherspage/teachers.h"
#include <cstdint>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
  setAttribute(Qt::WA_DeleteOnClose);

  resize(800, 500);
  // centering on screen
  move(QApplication::desktop()
       ->availableGeometry().center() - this->rect().center());
  statusBar()->showMessage(
       tr("Selamat datang di aplikasi sistem informasi akademik"));

  CreateAct();
  CreateToolBars();
  CreateMenus();

  page_ = new QTabWidget();
  CreateTabWidgets();
}

void MainWindow::CreateAct() {
  quit_act_ = new QAction(QIcon(":/images/exit.png"), tr("&Quit"), this);
  quit_act_->setShortcut(Qt::ALT + Qt::Key_X);
  quit_act_->setStatusTip(tr("Keluar dari aplikasi"));

  undo_act_ = new QAction(QIcon(":/images/undo.png"), tr("&Undo"), this);
  undo_act_->setShortcuts(QKeySequence::Undo);

  redo_act_ = new QAction(QIcon(":/images/redo.png"), tr("&Redo"), this);
  redo_act_->setShortcuts(QKeySequence::Redo);

  cut_act_ = new QAction(QIcon(":/images/cut.png"), tr("Cu&t"), this);
  cut_act_->setStatusTip(tr("Memotong konten pilihan saat ini ke clipboard"));
  cut_act_->setShortcuts(QKeySequence::Cut);

  copy_act_ = new QAction(QIcon(":/images/copy.png"), tr("&Copy"), this);
  copy_act_->setStatusTip(tr("Menyalin konten pilihan saat ini ke clipboard"));
  copy_act_->setShortcuts(QKeySequence::Copy);

  paste_act_ = new QAction(QIcon(":/images/paste.png"), tr("&Paste"), this);
  paste_act_->setStatusTip(tr("Paste konten pilihan saat ini"));
  paste_act_->setShortcuts(QKeySequence::Paste);

  delete_act_ = new QAction(QIcon(":/images/delete.png"), tr("&Delete"), this);
  delete_act_->setStatusTip(tr("Menghapus konten pilihan saat ini"));
  delete_act_->setShortcuts(QKeySequence::Delete);

  about_act_ = new QAction(QIcon(":/images/bookmark.png"), tr("&About"), this);
  about_act_->setStatusTip("Tampilkan tentang aplikasi");
  about_act_->setShortcut(Qt::Key_F1);

  aboutqt_act_ = new QAction(QIcon::fromTheme("face-cool"),
                             tr("About Qt"), this);
  aboutqt_act_->setStatusTip("Tampilkan tentang pustaka Qt");

  back_act_ = new QAction(QIcon(":/images/go-previous.png"), tr("Back"), this);
  back_act_->setStatusTip(tr("Kembali ke halaman sebelumnya"));
  next_act_ = new QAction(QIcon(":/images/go-next.png"), tr("Next"), this);
  next_act_->setStatusTip(tr("Pergi ke halaman selanjutnya"));

  home_act_ = new QAction(QIcon(":/images/go-home.png"), tr("Home"), this);
  home_act_->setStatusTip(tr("Kembali ke menu utama"));

  show_fullscreen_act_ = new QAction(tr("Full screen"), this);
  show_fullscreen_act_->setStatusTip(tr("Tampilkan layar secara penuh"));
  show_fullscreen_act_->setCheckable(true);

  teachers_act_ = new QAction(tr("Daftar &Guru"), this);
  teachers_act_->setStatusTip(tr("Tampilkan daftar-daftar guru"));

  // signal mapper
  signalmapper_ = new QSignalMapper(this);

  // signal and slot
  connect(quit_act_, SIGNAL(triggered()), this, SLOT(close()));
  connect(cut_act_, SIGNAL(triggered()), this, SLOT(cut()));
  connect(about_act_, SIGNAL(triggered()), this, SLOT(AboutApp()));
  connect(aboutqt_act_, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
  connect(home_act_, SIGNAL(triggered()), signalmapper_, SLOT(map()));
  connect(teachers_act_, SIGNAL(triggered()), signalmapper_, SLOT(map()));

  signalmapper_->setMapping(home_act_, tr("Menu Utama"));
  connect(signalmapper_, SIGNAL(mapped(QString)),
          this, SLOT(PageToolbar(const QString&)));
  signalmapper_->setMapping(teachers_act_, tr("Daftar Guru"));
  connect(signalmapper_, SIGNAL(mapped(QString)),
          this, SLOT(PageToolbar(const QString&)));
}

void MainWindow::CreateMenus() {
  file_menu_ = menuBar()->addMenu(tr("&File"));
  file_menu_->addAction(quit_act_);

  edit_menu_ = menuBar()->addMenu(tr("&Edit"));
  edit_menu_->addAction(undo_act_);
  edit_menu_->addAction(redo_act_);
  edit_menu_->addSeparator();
  edit_menu_->addAction(cut_act_);
  edit_menu_->addAction(copy_act_);
  edit_menu_->addAction(paste_act_);
  edit_menu_->addAction(delete_act_);

  data_menu_ = menuBar()->addMenu(tr("&Data"));
  data_menu_->addAction(teachers_act_);

  window_menu_ = menuBar()->addMenu(tr("&Window"));
  window_menu_->addAction(file_toolbar_act_);
  window_menu_->addAction(edit_toolbar_act_);
  window_menu_->addAction(show_fullscreen_act_);

  help_menu_ = menuBar()->addMenu(tr("&Help"));
  help_menu_->addAction(about_act_);
  help_menu_->addAction(aboutqt_act_);

  connect(show_fullscreen_act_, SIGNAL(triggered()),
          this, SLOT(FullScreenToggle()));
}

void MainWindow::CreateToolBars() {
  file_toolbar_ = addToolBar("File toolbar");
  file_toolbar_act_ = file_toolbar_->toggleViewAction();
  file_toolbar_->addAction(home_act_);
  file_toolbar_->addAction(back_act_);
  file_toolbar_->addAction(next_act_);
  file_toolbar_->addAction(undo_act_);
  file_toolbar_->addAction(redo_act_);
  file_toolbar_->setAllowedAreas(Qt::TopToolBarArea | Qt::LeftToolBarArea);

  edit_toolbar_ = addToolBar(tr("Edit toolbar"));
  edit_toolbar_act_ = edit_toolbar_->toggleViewAction();
  edit_toolbar_->addAction(cut_act_);
  edit_toolbar_->addAction(copy_act_);
  edit_toolbar_->addAction(paste_act_);
  edit_toolbar_->setAllowedAreas(Qt::TopToolBarArea | Qt::LeftToolBarArea);
}

void MainWindow::CreateTabWidgets() {
  // add widget to the menu utama tab
  page_->addTab(new PageHome(this), tr("Menu Utama"));
  page_->setTabsClosable(true);
  page_->tabBar()->tabButton(0, QTabBar::RightSide)->resize(0, 0);
  // event for close tab page
  connect(page_, SIGNAL(tabCloseRequested(int)),
          this, SLOT(CloseTab(const int&)));

  // add tab widget to the main window
  setCentralWidget(page_);
}

void MainWindow::cut() {
  // get the last child widget which has focus and
  // try to cast it as line edit
  QLineEdit* line_edit = dynamic_cast<QLineEdit*>(focusWidget());
  if (line_edit) line_edit->cut();
}

void MainWindow::AboutApp() {
  QMessageBox::about(this, tr("About Application"),
               tr("The <b>Application</b> example demonstrates how to "
               "write modern GUI applications using Qt, with a menu bar, "
               "toolbars, and a status bar."));
}

void MainWindow::CloseTab(const int& index) {
  // Delete the page widget, which automatically removes
  // the tab as well.
  delete page_->widget(index);
}

void MainWindow::PageToolbar(const QString& page_title) {
  int8_t page_count = page_->count();
  bool page_exist = false;
  int8_t i;
  for (i = 0; i < page_count; i++) {
    if (page_->tabText(i) == page_title) {
      page_->setCurrentIndex(i);
      page_exist = true;
      break;
    }
  }

  // If page not exist, create new page
  if (!page_exist) {
    if (page_title == "Menu Utama") {
      page_->addTab(new PageHome(this), page_title);
    } else {
      page_->addTab(new Teachers(this), page_title);
    }
  }
}

void MainWindow::FullScreenToggle() {
  if (show_fullscreen_act_->isChecked())
    this->showFullScreen();
  else
    this->showNormal();
}

MainWindow::~MainWindow() {}
