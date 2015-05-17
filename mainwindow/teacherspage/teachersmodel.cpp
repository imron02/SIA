/*
|-------------------------------------------------------------------------------
| Name:        teachersmodel.cpp
| Author:      Imron Rosdiana
| Modified by:
| Created:     2014-12-16
| Copyright:   (C) Copyright 2014, Imron Rosdiana
| Licence:     GPL (General Public License) V.3
*/

#include <QtWidgets>
#include <QDebug>
#include <iostream>
#include "mainwindow/teacherspage/teachersmodel.h"

using namespace std;
using namespace mongo;

QDate TeachersModel::DateOfBirth(const BSONElement& datebirth)
{
    return QDate(QDateTime::fromTime_t(datebirth.date()/1000).date());
}

void TeachersModel::AddTeacher(QAbstractItemModel* model,
                       const QString& induk_no,
                       const QString& name,
                       const QString& phone,
                       const QDate& datebirth,
                       const QString& sex,
                       const QString& certificate,
                       const QString& position,
                       const QString& teach,
                       const QString& fieldofstudy)
{
    model->insertRow(0);
    model->setData(model->index(0, 0), induk_no);
    model->setData(model->index(0, 1), name);
    model->setData(model->index(0, 2), phone);
    model->setData(model->index(0, 3), datebirth);
    model->setData(model->index(0, 4), sex);
    model->setData(model->index(0, 5), certificate);
    model->setData(model->index(0, 6), position);
    model->setData(model->index(0, 7), teach);
    model->setData(model->index(0, 8), fieldofstudy);
}

QAbstractItemModel* TeachersModel::CreateTeacherModel(QObject* parent)
{
    QStandardItemModel* model = new QStandardItemModel(0, 9, parent);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("No Induk"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nama"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Telepon"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Tanggal Lahir"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Jenis Kelamin"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Ijazah"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Jabatan"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Mengajar"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Bidang Studi"));

    #ifdef Q_OS_WIN
        client::initialize();
    #endif // Q_OS_WIN

//    try {
        c.connect("localhost");
        unique_ptr<DBClientCursor> cursor = c.query("sia.teachers", BSONObj());
        while (cursor->more()) {
           BSONObj p = cursor->next();
           DateOfBirth(p.getField("datebirth"));
           AddTeacher(model, p.getStringField("induk_no"), p.getStringField("name"),
                      p.getStringField("phone"),
                      DateOfBirth(p.getField("datebirth")),
                      p.getStringField("sex"), p.getStringField("certificate"),
                      p.getStringField("position"), p.getStringField("teach"),
                      p.getStringField("fieldofstudy"));
        }
//    } catch (const DBException &e) {

//    }

    return model;
}

TeachersModel::~TeachersModel() {}
