/*
|-------------------------------------------------------------------------------
| Name:        form_login_model.cpp
| Author:      Imron Rosdiana
| Modified by:
| Created:     2015-01-04
| Copyright:   (C) Copyright 2014, Imron Rosdiana
| Licence:     GPL (General Public License) V.3
*/

#include "login/form_login_model.h"
#include <QCryptographicHash>

using mongo::DBClientConnection;

FormLoginModel::FormLoginModel(const QString& username,
                               const QString& password) {
  username_ = username;
  password_ = password;
}

QString FormLoginModel::getusername() const {
  return username_;
}

void FormLoginModel::setUsername(const QString &username) {
  username_ = username;
}

QString FormLoginModel::getpassword() const {
  return password_;
}

void FormLoginModel::setPassword(const QString &password) {
  password_ = password;
}

int FormLoginModel::getLogin() const {
#ifdef Q_OS_WIN
  client::initialize();
#endif  // Q_OS_WIN

  DBClientConnection c;
  c.connect("localhost");
  QString cryptPassword = QString(QCryptographicHash::hash(
                                  QByteArray(password_.toUtf8()),
                                  QCryptographicHash::Md5).toHex());
  int n = c.count("sia.users", BSON("username"
                                    << username_.toStdString()
                                    << "password"
                                    << cryptPassword.toStdString()));
  return n;
}

FormLoginModel::~FormLoginModel() {}
