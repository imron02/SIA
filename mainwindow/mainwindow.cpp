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
    // signal mapper
    signalMapper = new QSignalMapper(this);

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
    pasteAct->setStatusTip(tr("Paste konten pilihan saat ini"));
    pasteAct->setShortcuts(QKeySequence::Paste);

    deleteAct = new QAction(QIcon::fromTheme("edit-delete", QIcon(":/images/delete.png")), tr("&Delete"), this);
    deleteAct->setStatusTip(tr("Menghapus konten pilihan saat ini"));
    deleteAct->setShortcuts(QKeySequence::Delete);

    aboutAct = new QAction(QIcon::fromTheme("help-about", QIcon(":/images/bookmark.png")), tr("&About"), this);
    aboutAct->setStatusTip("Tampilkan tentang aplikasi");
    aboutAct->setShortcut(Qt::Key_F1);
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(AboutApp()));

    aboutQtAct = new QAction(QIcon::fromTheme("face-cool"), tr("About Qt"), this);
    aboutQtAct->setStatusTip("Tampilkan tentang pustaka Qt");
    connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

    backAct = new QAction(QIcon::fromTheme("go-previous", QIcon(":/images/arrow-left.png")), tr("Back"), this);
    backAct->setStatusTip(tr("Kembali ke halaman sebelumnya"));
    nextAct = new QAction(QIcon::fromTheme("go-next", QIcon(":/images/arrow-right.png")), tr("Next"), this);
    nextAct->setStatusTip(tr("Pergi ke halaman selanjutnya"));

    homeAct = new QAction(QIcon::fromTheme("go-home"), tr("Home"), this);
    homeAct->setStatusTip(tr("Kembali ke menu utama"));

    showFullScreenAct = new QAction(tr("Full screen"), this);
    showFullScreenAct->setStatusTip(tr("Tampilkan layar secara penuh"));
    showFullScreenAct->setCheckable(true);

    // signal and slot
    connect(homeAct, SIGNAL(triggered()), signalMapper, SLOT(map()));

    signalMapper->setMapping(homeAct, "menu utama");
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
    windowHome = new QWidget();
    QString string = "<html><body>"
                     "<h3>Selamat Datang di Aplikasi Sistem Informasi Akademik</h3>"
                     "<br/><b>Mengenai aplikasi</b><br/>"
                     "<p>Aplikasi sistem informasi akademik adalah aplikasi yang ditunjukkan untuk"
                     "membantu sekolah dalam mengolah data-data akademik secara cepat dan mudah.</p>"
                     "<p><b>Fitur</b></p>"
                     "<p>Dengan aplikasi SIA, pihak sekolah dapat melakukan berbagai hal seperti:</p>"
                     "<ul>"
                     "<li>Mudah mengolah data-data guru</li>"
                     "<li>Mudah mengolah data-data siswa</li>"
                     "<li>Fitur pembayaran SPP</li>"
                     "<li>Fitur penjurusan siswa</li>"
                     "</ul>"
                     "<p>See README.txt for more information.</p>"
                     "</body></html>";
    QLabel* label = new QLabel(string);

    QVBoxLayout* vbox = new QVBoxLayout(windowHome);
    vbox->addWidget(label);
    vbox->addStretch(1);

    windowHome->setLayout(vbox);

    // add widget to the menu utama tab
    page->addTab(windowHome, tr("Menu Utama"));
    page->addTab(new QLabel("TabA"), "TabA");
    page->addTab(new QLabel("TabB"), "TabB");
    page->addTab(new QLabel("TabC"), "TabC");
    page->setTabsClosable(true);

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
    qDebug() << pageTitle;
    short pageCount = page->count();
    bool pageExist = false;
    for (short i = 0; i < pageCount; i++) {
        if (page->tabText(i).toLower() == pageTitle) {
            page->setCurrentIndex(i);
            pageExist = true;
            break;
        }
    }

//    if(!pageExist) {
//        page->insertTab(0, windowHome, tr("Menu Utama"));
//    }
}

void MainWindow::FullScreenToggle()
{
    if(showFullScreenAct->isChecked())
        this->showFullScreen();
    else
        this->showNormal();
}

MainWindow::~MainWindow() {}
