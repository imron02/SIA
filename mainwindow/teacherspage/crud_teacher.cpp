/*
|-------------------------------------------------------------------------------
| Name:        crud_teacher.cpp
| Author:      Imron Rosdiana
| Modified by:
| Created:     2015-06-07
| Copyright:   (C) Copyright 2014, Imron Rosdiana
| Licence:     GPL (General Public License) V.3
*/

#include <QVBoxLayout>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QRegExp>
#include <QDebug>
#include "mainwindow/teacherspage/crud_teacher.h"
#include "mainwindow/teacherspage/teachersmodel.h"

CrudTeacher::CrudTeacher(QWidget *parent) : QDialog(parent)
{
    setModal(true);
    setFixedSize(300, 350);
    setWindowTitle("Tambah data guru");
    setAttribute(Qt::WA_DeleteOnClose);

    this->CreateWidget();
    this->SetLayout();
}

void CrudTeacher::CreateWidget()
{
    noIndukLabel_ = new QLabel("No Induk:");
    nameLabel_ = new QLabel("Nama:");
    tlpLabel_ = new QLabel("Telepon:");
    tglLabel_ = new QLabel("Tanggal Lahir:");
    sexLabel_ = new QLabel("Jenis Kelamin:");
    certificateLabel_ = new QLabel("Ijazah");
    positionLabel_ = new QLabel("Jabatan");
    teachLabel_ = new QLabel("Mengajar");
    fieldofstudyLabel_ = new QLabel("Bidang Studi:");
    noIndukLineEdit_ = new QLineEdit;
    nameLineEdit_ = new QLineEdit;
    tlpLineEdit_ = new QLineEdit;
    tglLineEdit_ = new QLineEdit;
    sexComboBox_ = new QComboBox;
    sexComboBox_->addItem("Laki-laki", QVariant("L"));
    sexComboBox_->addItem("Perempuan", QVariant("P"));
    certificateLineEdit_ = new QLineEdit;
    positionLineEdit_ = new QLineEdit;
    teachLineEdit_ = new QLineEdit;
    fieldofstudyLineEdit_ = new QLineEdit;

    addButton_ = new QPushButton("Tambah");
    cancelButton_ = new QPushButton("Batal");

    //Regex only number
    QRegExp rxNum("\\d+");
    QValidator *valNum = new QRegExpValidator(rxNum, this);
    noIndukLineEdit_->setValidator(valNum);
    tlpLineEdit_->setValidator(valNum);

    // Regex only character
    QRegExp rxChar("^[A-Za-z\\s]+$");
    QValidator *valChar = new QRegExpValidator(rxChar, this);
    nameLineEdit_->setValidator(valChar);

    // Slots
    connect(cancelButton_, SIGNAL(clicked()), this, SLOT(OnQuit()));
    connect(addButton_, SIGNAL(clicked()), this, SLOT(OnAdd()));
}

void CrudTeacher::SetLayout()
{
    QVBoxLayout *mainLayout = new QVBoxLayout;
    QGridLayout *sourceLayout = new QGridLayout;

    sourceLayout->addWidget(noIndukLabel_, 0, 1);
    sourceLayout->addWidget(noIndukLineEdit_, 0, 2);
    sourceLayout->addWidget(nameLabel_, 1, 1);
    sourceLayout->addWidget(nameLineEdit_, 1, 2);
    sourceLayout->addWidget(tlpLabel_, 2, 1);
    sourceLayout->addWidget(tlpLineEdit_, 2, 2);
    sourceLayout->addWidget(tglLabel_, 3, 1);
    sourceLayout->addWidget(tglLineEdit_, 3, 2);
    sourceLayout->addWidget(sexLabel_, 4, 1);
    sourceLayout->addWidget(sexComboBox_, 4, 2);
    sourceLayout->addWidget(certificateLabel_, 5, 1);
    sourceLayout->addWidget(certificateLineEdit_, 5, 2);
    sourceLayout->addWidget(positionLabel_, 6, 1);
    sourceLayout->addWidget(positionLineEdit_, 6, 2);
    sourceLayout->addWidget(teachLabel_, 7, 1);
    sourceLayout->addWidget(teachLineEdit_, 7, 2);
    sourceLayout->addWidget(fieldofstudyLabel_, 8, 1);
    sourceLayout->addWidget(fieldofstudyLineEdit_, 8, 2);

    QHBoxLayout *actionLayout = new QHBoxLayout;
    actionLayout->addWidget(addButton_, 1, Qt::AlignRight);
    actionLayout->addWidget(cancelButton_, 0, Qt::AlignRight);

    mainLayout->addLayout(sourceLayout);
    mainLayout->addLayout(actionLayout);
    setLayout(mainLayout);
}

void CrudTeacher::OnAdd()
{
    TeachersModel *teachersModel = new TeachersModel;
    teachersModel->SaveTeacher(noIndukLineEdit_->text(),
                               nameLineEdit_->text(),
                               tlpLineEdit_->text(),
                               QDate::fromString(tglLineEdit_->text(), "d-M-yyyy"),
                               sexComboBox_->itemData(sexComboBox_->currentIndex()).toString(),
                               certificateLineEdit_->text(),
                               positionLineEdit_->text(),
                               teachLineEdit_->text(),
                               fieldofstudyLineEdit_->text());
//    qDebug() << sexComboBox_->itemData(sexComboBox_->currentIndex()).toString();
//    qDebug() << tglLineEdit_->text();
    this->close();
}

void CrudTeacher::OnQuit()
{
    this->close();
}

CrudTeacher::~CrudTeacher() {}
