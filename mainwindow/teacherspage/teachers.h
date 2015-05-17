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

QT_BEGIN_NAMESPACE
class QTreeView;
class QCheckBox;
class QLabel;
class QLineEdit;
class QComboBox;
class QAbstractItemModel;
class QHBoxLayout;
QT_END_NAMESPACE

class Teachers : public QWidget
{

public:
    Teachers(QWidget* parent = 0);
    ~Teachers();

private:
    void SetSourceModel(QAbstractItemModel* model);

    QTreeView* sourceView;
};

#endif // TEACHERS_H
