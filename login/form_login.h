/*
|-------------------------------------------------------------------------------
| Name:        formlogin.h
| Author:      Imron Rosdiana
| Modified by:
| Created:     2014-11-27
| Copyright:   (C) Copyright 2014, Imron Rosdiana
| Licence:     GPL (General Public License) V.3
*/

#ifndef FORM_LOGIN_H
#define FORM_LOGIN_H

#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>

class FormLogin : public QDialog {
  Q_OBJECT

 public:
  explicit FormLogin(QWidget* parent = 0);
  ~FormLogin();

 private slots:
  void OnQuit();
  void OnLogin();

 private:
  void reject();

  QLabel* user_label_;
  QLabel* pass_label_;
  QLineEdit* user_lineedit_;
  QLineEdit* pass_lineedit_;
  QPushButton* login_button_;
  QPushButton* quit_button_;
};

#endif  // FORM_LOGIN_H
