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
#include "mainwindow.h"

<<<<<<< HEAD
MainWindow::MainWindow()
=======
MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent)
>>>>>>> 5401ce1ae65b8f52c140de1906727b13f55d8512
{
    setMinimumSize(800, 600);
    statusBar()->showMessage(tr("Selamat datang di aplikasi sistem informasi akademik"));

    CreateAct();
    CreateMenus();
}

void MainWindow::AboutApp()
{
    QMessageBox::about(this, tr("About Application"),
             tr("The <b>Application</b> example demonstrates how to "
                "write modern GUI applications using Qt, with a menu bar, "
                "toolbars, and a status bar."));
}

void MainWindow::AboutQt()
{
    QMessageBox::about(this, tr("About Application"),
                 tr("The <b>Application</b> example demonstrates how to "
                    "write modern GUI applications using Qt, with a menu bar, "
                    "toolbars, and a status bar."));
}

void MainWindow::CreateAct()
{
<<<<<<< HEAD
    quitAct = new QAction(QIcon::fromTheme("application-exit"), tr("&Quit"), this);
    quitAct->setShortcuts(QKeySequence::Quit);
    quitAct->setStatusTip(tr("Keluar dari aplikasi"));
    connect(quitAct, SIGNAL(triggered()), SLOT(close()));

    undoAct = new QAction(QIcon::fromTheme("edit-undo"), tr("&Undo"), this);
    undoAct->setShortcuts(QKeySequence::Undo);

    redoAct = new QAction(QIcon::fromTheme("edit-redo"), tr("&Redo"), this);
    redoAct->setShortcuts(QKeySequence::Redo);

    cutAct = new QAction(QIcon::fromTheme("edit-cut"), tr("Cu&t"), this);
    cutAct->setStatusTip(tr("Memotong konten pilihan saat ini ke clipboard"));
    cutAct->setShortcuts(QKeySequence::Cut);

    copyAct = new QAction(QIcon::fromTheme("edit-copy"), tr("&Copy"), this);
    copyAct->setStatusTip(tr("Menyalin konten pilihan saat ini ke clipboard"));
    copyAct->setShortcuts(QKeySequence::Copy);

    pasteAct = new QAction(QIcon::fromTheme("edit-paste"), tr("&Paste"), this);
=======
    quitAct = new QAction(QIcon::fromTheme("application-exit", QIcon(":/images/exit.png")), tr("&Quit"), this);
    quitAct->setShortcut(Qt::ALT + Qt::Key_X);
    quitAct->setStatusTip(tr("Keluar dari aplikasi"));
    connect(quitAct, SIGNAL(triggered()), this, SLOT(close()));

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
>>>>>>> 5401ce1ae65b8f52c140de1906727b13f55d8512
    pasteAct->setStatusTip(tr("Paste konten pilihan saat ini"));
    pasteAct->setShortcuts(QKeySequence::Paste);

    deleteAct = new QAction(QIcon::fromTheme("edit-delete"), tr("&Delete"), this);
    deleteAct->setStatusTip(tr("Menghapus konten pilihan saat ini"));
    deleteAct->setShortcuts(QKeySequence::Delete);

    aboutAct = new QAction(QIcon::fromTheme("help-about"), tr("&About"), this);
    aboutAct->setStatusTip("Tampilkan tentang aplikasi");
    aboutAct->setShortcut(Qt::Key_F1);
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(AboutApp()));

    aboutQtAct = new QAction(QIcon::fromTheme("face-cool"), tr("About Qt"), this);
    aboutQtAct->setStatusTip("Tampilkan tentang pustaka Qt");
    connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
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

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(aboutQtAct);
}

<<<<<<< HEAD
MainWindow::~MainWindow() {}
=======
MainWindow::~MainWindow()
{
    delete helpMenu;
}
>>>>>>> 5401ce1ae65b8f52c140de1906727b13f55d8512
