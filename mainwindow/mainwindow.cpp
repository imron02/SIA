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
#include "mainwindow/mainwindow.h"
#include "mainwindow/homepage/pagehome.h"
#include "mainwindow/teacherspage/teachers.h"

using namespace std;

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent)
{
    resize(800, 800);
    // centering on screen
    move(QApplication::desktop()->availableGeometry().center() - this->rect().center());
    statusBar()->showMessage(tr("Selamat datang di aplikasi sistem informasi akademik"));

    CreateAct();
    CreateToolBars();
    CreateMenus();

    page = new QTabWidget();
    CreateTabWidgets();
}

void MainWindow::CreateAct()
{
    quitAct = new QAction(QIcon::fromTheme("application-exit", QIcon(":/images/exit.png")), tr("&Quit"), this);
    quitAct->setShortcut(Qt::ALT + Qt::Key_X);
    quitAct->setStatusTip(tr("Keluar dari aplikasi"));

    undoAct = new QAction(QIcon::fromTheme("edit-undo", QIcon(":/images/undo.png")), tr("&Undo"), this);
    undoAct->setShortcuts(QKeySequence::Undo);

    redoAct = new QAction(QIcon::fromTheme("edit-redo", QIcon(":/images/redo.png")), tr("&Redo"), this);
    redoAct->setShortcuts(QKeySequence::Redo);

    cutAct = new QAction(QIcon::fromTheme("edit-cut", QIcon(":/images/cut.png")), tr("Cu&t"), this);
    cutAct->setStatusTip(tr("Memotong konten pilihan saat ini ke clipboard"));
    cutAct->setShortcuts(QKeySequence::Cut);

    copyAct = new QAction(QIcon::fromTheme("edit-copy", QIcon(":/images/copy.png")), tr("&Copy"), this);
    copyAct->setStatusTip(tr("Menyalin konten pilihan saat ini ke clipboard"));
    copyAct->setShortcuts(QKeySequence::Copy);

    pasteAct = new QAction(QIcon::fromTheme("edit-paste", QIcon(":/images/paste.png")), tr("&Paste"), this);
    pasteAct->setStatusTip(tr("Paste konten pilihan saat ini"));
    pasteAct->setShortcuts(QKeySequence::Paste);

    deleteAct = new QAction(QIcon::fromTheme("edit-delete", QIcon(":/images/delete.png")), tr("&Delete"), this);
    deleteAct->setStatusTip(tr("Menghapus konten pilihan saat ini"));
    deleteAct->setShortcuts(QKeySequence::Delete);

    aboutAct = new QAction(QIcon::fromTheme("help-about", QIcon(":/images/bookmark.png")), tr("&About"), this);
    aboutAct->setStatusTip("Tampilkan tentang aplikasi");
    aboutAct->setShortcut(Qt::Key_F1);

    aboutQtAct = new QAction(QIcon::fromTheme("face-cool"), tr("About Qt"), this);
    aboutQtAct->setStatusTip("Tampilkan tentang pustaka Qt");

    backAct = new QAction(QIcon::fromTheme("go-previous", QIcon(":/images/arrow-left.png")), tr("Back"), this);
    backAct->setStatusTip(tr("Kembali ke halaman sebelumnya"));
    nextAct = new QAction(QIcon::fromTheme("go-next", QIcon(":/images/arrow-right.png")), tr("Next"), this);
    nextAct->setStatusTip(tr("Pergi ke halaman selanjutnya"));

    homeAct = new QAction(QIcon::fromTheme("go-home"), tr("Home"), this);
    homeAct->setStatusTip(tr("Kembali ke menu utama"));

    showFullScreenAct = new QAction(tr("Full screen"), this);
    showFullScreenAct->setStatusTip(tr("Tampilkan layar secara penuh"));
    showFullScreenAct->setCheckable(true);

    teachersAct = new QAction(tr("Daftar &Guru"), this);
    teachersAct->setStatusTip(tr("Tampilkan daftar-daftar guru"));

    // signal mapper
    signalMapper = new QSignalMapper(this);

    // signal and slot
    connect(quitAct, SIGNAL(triggered()), this, SLOT(close()));
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(AboutApp()));
    connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
    connect(homeAct, SIGNAL(triggered()), signalMapper, SLOT(map()));
    connect(teachersAct, SIGNAL(triggered()), signalMapper, SLOT(map()));

    signalMapper->setMapping(homeAct, tr("Menu Utama"));
    connect(signalMapper, SIGNAL(mapped(QString)), this, SLOT(PageToolbar(const QString&)));
    signalMapper->setMapping(teachersAct, tr("Daftar Guru"));
    connect(signalMapper, SIGNAL(mapped(QString)), this, SLOT(PageToolbar(const QString&)));

}

void MainWindow::CreateMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(quitAct);

    editMenu = menuBar()->addMenu(tr("&Edit"));
    editMenu->addAction(undoAct);
    editMenu->addAction(redoAct);
    editMenu->addSeparator();
    editMenu->addAction(cutAct);
    editMenu->addAction(copyAct);
    editMenu->addAction(pasteAct);
    editMenu->addAction(deleteAct);

    dataMenu = menuBar()->addMenu(tr("&Data"));
    dataMenu->addAction(teachersAct);

    windowMenu = menuBar()->addMenu(tr("&Window"));
    windowMenu->addAction(fileToolBarAct);
    windowMenu->addAction(editToolBarAct);
    windowMenu->addAction(showFullScreenAct);
    connect(showFullScreenAct, SIGNAL(triggered()), this, SLOT(FullScreenToggle()));

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(aboutQtAct);
}

void MainWindow::CreateToolBars()
{
    fileToolBar = addToolBar("File toolbar");
    fileToolBarAct = fileToolBar->toggleViewAction();
    fileToolBar->addAction(homeAct);
    fileToolBar->addAction(backAct);
    fileToolBar->addAction(nextAct);
    fileToolBar->addAction(undoAct);
    fileToolBar->addAction(redoAct);
    fileToolBar->setAllowedAreas(Qt::TopToolBarArea | Qt::LeftToolBarArea);

    editToolBar = addToolBar(tr("Edit toolbar"));
    editToolBarAct = editToolBar->toggleViewAction();
    editToolBar->addAction(cutAct);
    editToolBar->addAction(copyAct);
    editToolBar->addAction(pasteAct);
    editToolBar->setAllowedAreas(Qt::TopToolBarArea | Qt::LeftToolBarArea);
}

void MainWindow::CreateTabWidgets()
{
    // add widget to the menu utama tab
    page->addTab(new PageHome(this), tr("Menu Utama"));
    page->setTabsClosable(true);
    page->tabBar()->tabButton(0, QTabBar::RightSide)->resize(0,0);

    // event for close tab page
    connect(page, SIGNAL(tabCloseRequested(int)), this, SLOT(CloseTab(int)));

    // add tab widget to the main window
    setCentralWidget(page);

}

void MainWindow::AboutApp()
{
    QMessageBox::about(this, tr("About Application"),
             tr("The <b>Application</b> example demonstrates how to "
                "write modern GUI applications using Qt, with a menu bar, "
                "toolbars, and a status bar."));
}

void MainWindow::CloseTab(int index)
{
    // Delete the page widget, which automatically removes
    // the tab as well.
    delete page->widget(index);
}

void MainWindow::PageToolbar(const QString& pageTitle)
{
    short pageCount = page->count();
    bool pageExist = false;
    short i;
    for (i = 0; i < pageCount; i++) {
        if (page->tabText(i) == pageTitle) {
            page->setCurrentIndex(i);
            pageExist = true;
            break;
        }
    }

    // If page not exist, create new page
    if(!pageExist) {
        if(pageTitle == "Menu Utama")
            page->addTab(new PageHome(this), pageTitle);
        else
            page->addTab(new Teachers(this), pageTitle);
    }
}

void MainWindow::FullScreenToggle()
{
    if(showFullScreenAct->isChecked())
        this->showFullScreen();
    else
        this->showNormal();
}

MainWindow::~MainWindow() {}
