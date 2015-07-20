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

QDate TeachersModel::DateOfBirth(const BSONElement &datebirth)
{
    return QDate(QDateTime::fromTime_t(datebirth.date()/1000).date());
}

void TeachersModel::AddTeacher(QAbstractItemModel* model,
                               const QString &induk_no,
                               const QString &name,
                               const QString &phone,
                               const QDate &datebirth,
                               const QString &sex,
                               const QString &certificate,
                               const QString &position,
                               const QString &teach,
                               const QString &fieldofstudy,
                               const QString &id)
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
    model->setData(model->index(0, 9), id);
}

QAbstractItemModel* TeachersModel::CreateTeacherModel(QObject* parent)
{
    QStandardItemModel *model = new QStandardItemModel(0, 10, parent);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("No Induk"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nama"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Telepon"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Tanggal Lahir"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Jenis Kelamin"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Ijazah"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Jabatan"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Mengajar"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Bidang Studi"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("Id"));

    #ifdef Q_OS_WIN
        client::initialize();
    #endif // Q_OS_WIN

    c.connect("localhost");
    unique_ptr<DBClientCursor> cursor = c.query("sia.teachers", BSONObj());
    while (cursor->more()) {
        BSONObj p = cursor->next();
        AddTeacher(model, p.getStringField("induk_no"),
                   p.getStringField("name"),
                   p.getStringField("phone"),
                   DateOfBirth(p.getField("datebirth")),
                   p.getStringField("sex"),
                   p.getStringField("certificate"),
                   p.getStringField("position"),
                   p.getStringField("teach"),
                   p.getStringField("fieldofstudy"),
                   QString::fromStdString(p["_id"].OID().toString()));
        }

    return model;
}

void TeachersModel::SaveTeacher(const QString &induk_no,
                                const QString &name,
                                const QString &phone,
                                const QDate &datebirth,
                                const QString &sex,
                                const QString &certificate,
                                const QString &position,
                                const QString &teach,
                                const QString &fieldofstudy)
{
    #ifdef Q_OS_WIN
        client::initialize();
    #endif // Q_OS_WIN

    c.connect("localhost");
    BSONObjBuilder b;
    b.append("induk_no", induk_no.toStdString());
    b.append("name", name.toStdString());
    b.append("phone", phone.toStdString());
    b.appendDate("datebirth", QDateTime(datebirth).toMSecsSinceEpoch());
    b.append("sex", sex.toStdString());
    b.append("certificate", certificate.toStdString());
    b.append("position", position.toStdString());
    b.append("teach", teach.toStdString());
    b.append("fieldofstudy", fieldofstudy.toStdString());
    BSONObj p = b.obj();
    c.insert("sia.teachers", p);
}

TeachersModel::~TeachersModel() {}
