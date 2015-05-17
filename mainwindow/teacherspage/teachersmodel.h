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

private:
    void AddTeacher(QAbstractItemModel* model,
                    const QString& induk_no,
                    const QString& name,
                    const QString& phone,
                    const QDate& date,
                    const QString& sex,
                    const QString& certificate,
                    const QString& position,
                    const QString& teach,
                    const QString& fieldofstudy);
    mongo::DBClientConnection c;
};

#endif // TEACHERSMODEL_H
