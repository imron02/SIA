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

    QHBoxLayout* sourceLayout = new QHBoxLayout;
    sourceLayout->addWidget(sourceView);
    setLayout(sourceLayout);

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
}

Teachers::~Teachers() {}
