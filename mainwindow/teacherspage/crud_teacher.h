/*
|-------------------------------------------------------------------------------
| Name:        crud_teacher.h
| Author:      Imron Rosdiana
| Modified by:
| Created:     2015-06-07
| Copyright:   (C) Copyright 2014, Imron Rosdiana
| Licence:     GPL (General Public License) V.3
*/

#ifndef CRUD_TEACHER
#define CRUD_TEACHER

#include <QtWidgets>

QT_BEGIN_NAMESPACE
class QDialog;
class QLabel;
class QLineEdit;
class QComboBox;
class QPushButton;
class QDate;
QT_END_NAMESPACE

class CrudTeacher : public QDialog
{
    Q_OBJECT

public:
    CrudTeacher(QWidget *parent = 0);
    ~CrudTeacher();
    void UpdateData(const QString &noInduk,
                 const QString &name,
                 const QString &tlp,
                 const QDate &tgl,
                 const QString &sex,
                 const QString &certificate,
                 const QString &position,
                 const QString &teach,
                 const QString &fieldofstudy,
                 const QString &id);

private slots:
    void OnAdd();
    void OnQuit();

private:
    void CreateWidget();
    void SetLayout();

    QLabel *noIndukLabel_;
    QLabel *nameLabel_;
    QLabel *tlpLabel_;
    QLabel *tglLabel_;
    QLabel *sexLabel_;
    QLabel *certificateLabel_;
    QLabel *positionLabel_;
    QLabel *teachLabel_;
    QLabel *fieldofstudyLabel_;
    QLineEdit *noIndukLineEdit_;
    QLineEdit *nameLineEdit_;
    QLineEdit *tlpLineEdit_;
    QLineEdit *tglLineEdit_;
    QComboBox *sexComboBox_;
    QLineEdit *certificateLineEdit_;
    QLineEdit *positionLineEdit_;
    QLineEdit *teachLineEdit_;
    QLineEdit *fieldofstudyLineEdit_;
    QPushButton *addButton_;
    QPushButton *cancelButton_;
    QString id_;
};

#endif // CRUD_TEACHER

