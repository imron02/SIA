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
    deleteButton_->setFixedWidth(80);
    reloadButton_ = new QPushButton();
    reloadButton_->setIcon(QIcon(":/images/reload.png"));
    reloadButton_->setFixedWidth(20);

    connect(filterPatternLineEdit_, SIGNAL(textChanged(QString)),
            this, SLOT(filterRegExpChanged()));
    connect(filterColumnComboBox_, SIGNAL(currentIndexChanged(int)),
            this, SLOT(filterColumnChanged()));
    connect(addButton_, SIGNAL(clicked()), this, SLOT(addTeacher()));
    connect(editButton_, SIGNAL(clicked()), this, SLOT(editTeacher()));
    connect(reloadButton_, SIGNAL(clicked()), this, SLOT(reloadTeacher()));

    QVBoxLayout *mainLayout = new QVBoxLayout;
    QHBoxLayout *filterLayout = new QHBoxLayout;
    QHBoxLayout *sourceLayout = new QHBoxLayout;

    filterLayout->addWidget(filterPatternLabel_, 1);
    filterLayout->addWidget(filterPatternLineEdit_, 2);
    filterLayout->addWidget(filterColumnComboBox_, 3);
    filterLayout->addWidget(addButton_, 4);
    filterLayout->addWidget(editButton_, 5);
    filterLayout->addWidget(deleteButton_, 6);
    filterLayout->addWidget(reloadButton_, 7);
    sourceLayout->addWidget(proxyView_);

    mainLayout->addLayout(filterLayout);
    mainLayout->addLayout(sourceLayout);
    setLayout(mainLayout);

    teachersModel = new TeachersModel;
    try {
        SetSourceModel("new");
    } catch (exception& e) {
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

void Teachers::SetSourceModel(const QString &keyModel)
{
    if(keyModel == "new") {
        model = teachersModel->CreateTeacherModel(this);
    } else {
        delete teachersModel;
        delete model;
        teachersModel = new TeachersModel;
        model = teachersModel->CreateTeacherModel(this);
    }
    proxyModel_->setSourceModel(model);
    proxyView_->setColumnHidden(9, true);
}

void Teachers::addTeacher()
{
    CrudTeacher *crudTeacher = new CrudTeacher(this);
    crudTeacher->show();
}

void Teachers::editTeacher()
{
    QList<QVariant> teacherData;
    QModelIndex tIndex = proxyModel_->mapToSource(proxyView_->currentIndex());

    // get hidden data column
    QModelIndex hiddenColumIndex = model->sibling(tIndex.row(), model->columnCount()+1, tIndex);
    teacherData.append(model->data(hiddenColumIndex));

    // get all data column
    for(int i = 0; i <= model->columnCount(); i++) {
        QModelIndex columnIndex = model->sibling(tIndex.row(), i, tIndex);
        teacherData.append(model->data(columnIndex));
    }

    CrudTeacher *crudEditTeacher = new CrudTeacher(this);
    crudEditTeacher->UpdateData(teacherData[1].toString(),
                                teacherData[2].toString(),
                                teacherData[3].toString(),
                                teacherData[4].toDate(),
                                teacherData[5].toString(),
                                teacherData[6].toString(),
                                teacherData[7].toString(),
                                teacherData[8].toString(),
                                teacherData[9].toString(),
                                teacherData[10].toString());
    crudEditTeacher->show();
}

void Teachers::reloadTeacher()
{
    SetSourceModel("reloadr");
}


Teachers::~Teachers() {}
