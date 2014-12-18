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

QT_BEGIN_NAMESPACE
class QGroupBox;
class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QStandardItemModel;
class QTime;
QT_END_NAMESPACE

class Teachers : public TeachersModel
{

public:
    Teachers(QWidget* parent = 0);
    ~Teachers();

private:
    void AddMail(QAbstractItemModel* model, const QString& subject,
                 const QString& sender, const QDateTime& date);

    QAbstractItemModel* CreateMailModel(QObject* parent);
    QGroupBox* sourceGroupBox;
    QGroupBox* proxyGroupBox;
};

#endif // TEACHERS_H
