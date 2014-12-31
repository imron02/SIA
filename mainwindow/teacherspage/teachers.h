/*
|-------------------------------------------------------------------------------
| Name:        teachers.h
| Author:      Imron Rosdiana
| Modified by:
| Created:     2014-12-16
| Copyright:   (C) Copyright 2014, Imron Rosdiana
| Licence:     GPL (General Public License) V.3
*/

#ifndef TEACHERS_H
#define TEACHERS_H

#include <QtWidgets>
#include "mainwindow/teacherspage/teachersmodel.h"

// MongoDB Connection
#ifdef Q_OS_WIN
    #include <WinSock2.h>
#endif // Q_OS_WIN
#include "mongo/client/dbclient.h"

QT_BEGIN_NAMESPACE
class QGroupBox;
class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QStandardItemModel;
class QTime;
class QMessageBox;
QT_END_NAMESPACE

class Teachers : public TeachersModel
{

public:
    Teachers(QWidget* parent = 0);
    ~Teachers();

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

    QAbstractItemModel* CreateTeacherModel(QObject* parent);
    mongo::DBClientConnection c;
};

#endif // TEACHERS_H
