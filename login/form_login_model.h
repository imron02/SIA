/*
|-------------------------------------------------------------------------------
| Name:        form_login_model.h
| Author:      Imron Rosdiana
| Modified by:
| Created:     2015-01-04
| Copyright:   (C) Copyright 2014, Imron Rosdiana
| Licence:     GPL (General Public License) V.3
*/

#ifndef FORM_LOGIN_MODEL_H
#define FORM_LOGIN_MODEL_H

#include <QString>

// MongoDB Connection
#ifdef Q_OS_WIN
    #include <WinSock2.h>
#endif  // Q_OS_WIN
#include "mongo/client/dbclient.h"

class FormLoginModel {
 public:
  FormLoginModel(const QString& username, const QString& password);
  ~FormLoginModel();
  QString getusername() const;
  void setUsername(const QString& username);
  QString getpassword() const;
  void setPassword(const QString& password);
  int getLogin() const;

 private:
  QString username_;
  QString password_;
};

#endif  // FORM_LOGIN_MODEL_H
