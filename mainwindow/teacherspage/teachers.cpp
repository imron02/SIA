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

using namespace std;

Teachers::Teachers(QWidget* parent) : QWidget(parent)
{
    setAttribute(Qt::WA_DeleteOnClose);

    sourceView = new QTreeView;
    sourceView->setRootIsDecorated(false);
    sourceView->setAlternatingRowColors(true);
    sourceView->setSortingEnabled(true);
    sourceView->sortByColumn(0, Qt::AscendingOrder);

    filterLabel_ = new QLabel("Cari");
    filterEdit_ = new QLineEdit;
    filterEdit_->setFixedWidth(600);
    addButton_ = new QPushButton("Tambah");
    addButton_->setFixedWidth(100);
    editButton_ = new QPushButton("Edit");
    editButton_->setFixedWidth(100);
    deleteButton_ = new QPushButton("Hapus");
    deleteButton_->setFixedWidth(100);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    QHBoxLayout* filterLayout = new QHBoxLayout;
    QHBoxLayout* sourceLayout = new QHBoxLayout;

    filterLayout->addWidget(filterLabel_, 1);
    filterLayout->addWidget(filterEdit_, 2);
    filterLayout->addWidget(addButton_, 3);
    filterLayout->addWidget(editButton_, 4);
    filterLayout->addWidget(deleteButton_, 5);
    sourceLayout->addWidget(sourceView);

    mainLayout->addLayout(filterLayout);
    mainLayout->addLayout(sourceLayout);
    setLayout(mainLayout);

    TeachersModel teachersModel;
    try {
        SetSourceModel(teachersModel.CreateTeacherModel(this));
    } catch (exception& e) {
        qDebug() << "Caught " << e.what();
        QMessageBox::critical(this, "Error", e.what());
    }
}

void Teachers::SetSourceModel(QAbstractItemModel* model)
{
    sourceView->setModel(model);
    sourceView->setColumnHidden(0, true);
    sourceView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

Teachers::~Teachers() {}
