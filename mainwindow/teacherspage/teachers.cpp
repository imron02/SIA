/*
|-------------------------------------------------------------------------------
| Name:        teachers.h
| Author:      Imron Rosdiana
| Modified by:
| Created:     2014-12-16
| Copyright:   (C) Copyright 2014, Imron Rosdiana
| Licence:     GPL (General Public License) V.3
*/

#include <iostream>
#include <exception>
#include "mainwindow/teacherspage/teachers.h"
#include "mainwindow/teacherspage/teachersmodel.h"
#include "mainwindow/teacherspage/crud_teacher.h"

using namespace std;

Teachers::Teachers(QWidget* parent) : QWidget(parent)
{
    proxyModel_ = new QSortFilterProxyModel;

    proxyView_ = new QTreeView;
    proxyView_->setRootIsDecorated(false);
    proxyView_->setAlternatingRowColors(true);
    proxyView_->setModel(proxyModel_);
    proxyView_->setSortingEnabled(true);
    proxyView_->sortByColumn(1, Qt::AscendingOrder);

    filterPatternLineEdit_ = new QLineEdit;
    filterPatternLabel_ = new QLabel("Cari data:");

    filterColumnComboBox_ = new QComboBox;
    filterColumnComboBox_->addItem("No Induk");
    filterColumnComboBox_->addItem("Nama");
    filterColumnComboBox_->setFixedWidth(200);

    addButton_ = new QPushButton("Tambah");
    addButton_->setFixedWidth(100);
    editButton_ = new QPushButton("Edit");
    editButton_->setFixedWidth(100);
    deleteButton_ = new QPushButton("Hapus");
    deleteButton_->setFixedWidth(100);

    connect(filterPatternLineEdit_, SIGNAL(textChanged(QString)),
            this, SLOT(filterRegExpChanged()));
    connect(filterColumnComboBox_, SIGNAL(currentIndexChanged(int)),
            this, SLOT(filterColumnChanged()));
    connect(addButton_, SIGNAL(clicked()), this, SLOT(addTeacher()));

    QVBoxLayout *mainLayout = new QVBoxLayout;
    QHBoxLayout *filterLayout = new QHBoxLayout;
    QHBoxLayout *sourceLayout = new QHBoxLayout;

    filterLayout->addWidget(filterPatternLabel_, 1);
    filterLayout->addWidget(filterPatternLineEdit_, 2);
    filterLayout->addWidget(filterColumnComboBox_, 3);
    filterLayout->addWidget(addButton_, 4);
    filterLayout->addWidget(editButton_, 5);
    filterLayout->addWidget(deleteButton_, 6);
    sourceLayout->addWidget(proxyView_);

    mainLayout->addLayout(filterLayout);
    mainLayout->addLayout(sourceLayout);
    setLayout(mainLayout);

    TeachersModel *teachersModel = new TeachersModel;
    try {
        SetSourceModel(teachersModel->CreateTeacherModel(this));
    } catch (exception& e) {
        qDebug() << "Caught " << e.what();
        QMessageBox::critical(this, "Error", e.what());
    }
}

void Teachers::filterRegExpChanged()
{
    QRegExp regExp(filterPatternLineEdit_->text(), Qt::CaseInsensitive, QRegExp::RegExp);
    proxyModel_->setFilterRegExp(regExp);
}

void Teachers::filterColumnChanged()
{
    proxyModel_->setFilterKeyColumn(filterColumnComboBox_->currentIndex());
}

void Teachers::addTeacher()
{
    CrudTeacher *crudTeacher = new CrudTeacher(this);
    crudTeacher->show();
}

void Teachers::SetSourceModel(QAbstractItemModel* model)
{
    proxyModel_->setSourceModel(model);
    proxyView_->setColumnHidden(9, true);
}


Teachers::~Teachers() {}
