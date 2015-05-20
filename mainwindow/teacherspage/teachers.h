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
class QPushButton;
class QComboBox;
class QAbstractItemModel;
class QAbstractItemView;
class QHBoxLayout;
class QVBoxLayout;
QT_END_NAMESPACE

class Teachers : public QWidget
{

public:
    Teachers(QWidget* parent = 0);
    ~Teachers();

private:
    void SetSourceModel(QAbstractItemModel* model);

    QTreeView* sourceView;
    QLabel* filterLabel_;
    QLineEdit* filterEdit_;
    QPushButton* addButton_;
    QPushButton* editButton_;
    QPushButton* deleteButton_;
};

#endif // TEACHERS_H
