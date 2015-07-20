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
class QTreeView;
class QCheckBox;
class QLabel;
class QLineEdit;
class QPushButton;
class QComboBox;
class QAbstractItemModel;
class QHBoxLayout;
class QVBoxLayout;\
class QSortFilterProxyModel;
QT_END_NAMESPACE

class Teachers : public QWidget
{
    Q_OBJECT

public:
    Teachers(QWidget* parent = 0);
    ~Teachers();

    void SetSourceModel(QAbstractItemModel* model);

private slots:
    void filterRegExpChanged();
    void filterColumnChanged();
    void addTeacher();
    void reloadTeacher();

private:
    QSortFilterProxyModel *proxyModel_;
    QTreeView *proxyView_;
    QLabel *filterPatternLabel_;
    QLineEdit *filterPatternLineEdit_;
    QComboBox *filterColumnComboBox_;
    QPushButton *addButton_;
    QPushButton *editButton_;
    QPushButton *deleteButton_;
    QPushButton *reloadButton_;
    TeachersModel *teachersModel;
};

#endif // TEACHERS_H
