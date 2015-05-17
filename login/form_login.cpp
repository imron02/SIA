/*
|-------------------------------------------------------------------------------
| Name:        formlogin.cpp
| Author:      Imron Rosdiana
| Modified by:
| Created:     2014-11-27
| Copyright:   (C) Copyright 2014, Imron Rosdiana
| Licence:     GPL (General Public License) V.3
*/

#include "login/form_login.h"
#include "form_login_model.h"
#include <QDebug>
#include <QString>
#include <iostream>
#include <exception>
#include <QMessageBox>

using std::cout;
using std::endl;
using std::exception;

FormLogin::FormLogin(QWidget* parent) : QDialog(parent) {
  setFixedSize(300, 120);
  setWindowTitle("Form Login");
  setModal(true);
  setAttribute(Qt::WA_DeleteOnClose);

  user_label_ = new QLabel("Username:");
  pass_label_ = new QLabel("Password:");
  user_lineedit_ = new QLineEdit();
  pass_lineedit_ = new QLineEdit();
  pass_lineedit_->setEchoMode(QLineEdit::Password);
  login_button_ = new QPushButton("Login");
  quit_button_ = new QPushButton("Quit");

  QVBoxLayout* vbox = new QVBoxLayout(this);
  QHBoxLayout* hbox1 = new QHBoxLayout();
  QHBoxLayout* hbox2 = new QHBoxLayout();
  QHBoxLayout* hbox3 = new QHBoxLayout();

  hbox1->addWidget(user_label_, 1);
  hbox1->addWidget(user_lineedit_, 2);
  hbox2->addWidget(pass_label_, 1);
  hbox2->addWidget(pass_lineedit_, 2);
  hbox3->addWidget(login_button_, 1, Qt::AlignRight);
  hbox3->addWidget(quit_button_, 0, Qt::AlignRight);

  vbox->addSpacing(1);
  vbox->addLayout(hbox1);
  vbox->addLayout(hbox2);
  vbox->addLayout(hbox3);

  connect(quit_button_, SIGNAL(clicked()), this, SLOT(OnQuit()));
  connect(login_button_, SIGNAL(clicked()), this, SLOT(OnLogin()));
}

void FormLogin::reject() {
  OnQuit();
}

void FormLogin::OnQuit() {
  close();
  parentWidget()->close();
}

void FormLogin::OnLogin() {
  FormLoginModel formLoginModel(user_lineedit_->text(),
                                pass_lineedit_->text());

  // Checking if username or password is empty
  if (formLoginModel.getusername().isEmpty()
      || formLoginModel.getpassword().isEmpty()) {
    QMessageBox::information(this, tr("Peringatan!"),
                "Username atau password tidak boleh kosong");
    return;
  }

  try {
    if  (formLoginModel.getLogin() > 0) {
      this->accept();
    } else {
      QMessageBox::information(this, tr("Peringatan!"),
                   "Username atau Password Salah");
    }
  } catch (const exception& e) {
      QMessageBox::critical(this, "Error", e.what());
  }
}

FormLogin::~FormLogin() {}
