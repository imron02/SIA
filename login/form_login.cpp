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
#include <QDebug>
#include <QCryptographicHash>
#include <QString>

using mongo::DBClientConnection;
using mongo::DBException;

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
  QString username = user_lineedit_->text();
  QString password = pass_lineedit_->text();

  // Checking if username or password is empty
  if (username.isEmpty() || password.isEmpty()) {
    QMessageBox::information(this, tr("Peringatan!"),
                 "Username atau password tidak boleh kosong");
    return;
  }

#ifdef Q_OS_WIN
  client::initialize();
#endif  // Q_OS_WIN

  try {
    DBClientConnection c;
    c.connect("localhost");
    QString cryptPassword = QString(QCryptographicHash::hash(
                                    QByteArray(password.toUtf8()),
                                    QCryptographicHash::Md5).toHex());
    int8_t n = c.count("sia.users", BSON("username"
                                        << username.toStdString()
                                        << "password"
                                        << cryptPassword.toStdString()));
    if  (n > 0) {
      this->accept();
    } else {
      QMessageBox::information(this, tr("Peringatan!"),
                   "Username atau Password Salah");
    }
  } catch (const DBException &e) {
      qDebug() << "caught " << e.what();
      QMessageBox::warning(this, "Error", "Database tidak terkoneksi");
  }
}

FormLogin::~FormLogin() {}
