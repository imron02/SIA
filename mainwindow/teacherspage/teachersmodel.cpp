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
                       const QString& id,
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
    model->setData(model->index(0, 0), id);
    model->setData(model->index(0, 1), induk_no);
    model->setData(model->index(0, 2), name);
    model->setData(model->index(0, 3), phone);
    model->setData(model->index(0, 4), datebirth);
    model->setData(model->index(0, 5), sex);
    model->setData(model->index(0, 6), certificate);
    model->setData(model->index(0, 7), position);
    model->setData(model->index(0, 8), teach);
    model->setData(model->index(0, 9), fieldofstudy);
}

QAbstractItemModel* TeachersModel::CreateTeacherModel(QObject* parent)
{
    QStandardItemModel* model = new QStandardItemModel(0, 10, parent);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("No Induk"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nama"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Telepon"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Tanggal Lahir"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Jenis Kelamin"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Ijazah"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Jabatan"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Mengajar"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("Bidang Studi"));

    #ifdef Q_OS_WIN
        client::initialize();
    #endif // Q_OS_WIN

    c.connect("localhost");
    unique_ptr<DBClientCursor> cursor = c.query("sia.teachers", BSONObj());
    while (cursor->more()) {
        BSONObj p = cursor->next();
        DateOfBirth(p.getField("datebirth"));
        AddTeacher(model, QString::fromStdString(p["_id"].OID().toString()),
                   p.getStringField("induk_no"), p.getStringField("name"),
                   p.getStringField("phone"),
                   DateOfBirth(p.getField("datebirth")),
                   p.getStringField("sex"), p.getStringField("certificate"),
                   p.getStringField("position"), p.getStringField("teach"),
                   p.getStringField("fieldofstudy"));
        }

    return model;
}

TeachersModel::~TeachersModel() {}
