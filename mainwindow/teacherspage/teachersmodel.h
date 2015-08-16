/*
|-------------------------------------------------------------------------------
| Name:        teachersmodel.h
| Author:      Imron Rosdiana
| Modified by:
| Created:     2014-12-16
| Copyright:   (C) Copyright 2014, Imron Rosdiana
| Licence:     GPL (General Public License) V.3
*/

#ifndef TEACHERSMODEL_H
#define TEACHERSMODEL_H

#include <QAbstractItemModel>
#include <QString>
#include <QTime>
#include <QDate>
#include <QDateTime>

// MongoDB Connection
#ifdef Q_OS_WIN
    #include <WinSock2.h>
#endif // Q_OS_WIN
#include "mongo/client/dbclient.h"

class TeachersModel
{
public:
    ~TeachersModel();

    QAbstractItemModel* CreateTeacherModel(QObject* parent);
    void SaveTeacher(const QString &induk_no,
                    const QString &name,
                    const QString &phone,
                    const QDate &datebirth,
                    const QString &sex,
                    const QString &certificate,
                    const QString &position,
                    const QString &teach,
                    const QString &fieldofstudy);
    void UpdateTeacher(const QString &id,
                       const QString &induk_no,
                       const QString &name,
                       const QString &phone,
                       const QDate &datebirth,
                       const QString &sex,
                       const QString &certificate,
                       const QString &position,
                       const QString &teach,
                       const QString &fieldofstudy);

private:
    QDate DateOfBirth(const mongo::BSONElement& datebirth);
    void AddTeacher(QAbstractItemModel* model,
                    const QString &induk_no,
                    const QString &name,
                    const QString &phone,
                    const QDate &datebirth,
                    const QString &sex,
                    const QString &certificate,
                    const QString &position,
                    const QString &teach,
                    const QString &fieldofstudy,
                    const QString &id);
    mongo::DBClientConnection c;
};

#endif // TEACHERSMODEL_H
