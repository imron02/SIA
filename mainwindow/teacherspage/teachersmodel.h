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

#include <QWidget>

QT_BEGIN_NAMESPACE
class QSortFilterProxyModel;
class QTreeView;
class QCheckBox;
class QLabel;
class QLineEdit;
class QComboBox;
class QAbstractItemModel;
QT_END_NAMESPACE

class TeachersModel : public QWidget
{
    Q_OBJECT

public:
    TeachersModel(QWidget* parent = 0);
    ~TeachersModel();

private slots:
    void FilterRegExpChanged();
    void FilterColumnChanged();
    void SortChanged();

protected:
    void SetSourceModel(QAbstractItemModel* model);

    QTreeView* sourceView;
    QCheckBox* filterCaseSensitivityCheckBox;
    QCheckBox* sortCaseSensitivityCheckBox;
    QLabel* filterPatternLabel;
    QLabel* filterSyntaxLabel;
    QLabel* filterColumnLabel;
    QLineEdit* filterPatternLineEdit;
    QComboBox* filterSyntaxComboBox;
    QComboBox* filterColumnComboBox;

private:
    QSortFilterProxyModel* proxyModel;
};

#endif // TEACHERSMODEL_H
