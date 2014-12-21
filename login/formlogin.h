/*
|-------------------------------------------------------------------------------
| Name:        formlogin.h
| Author:      Imron Rosdiana
| Modified by:
| Created:     2014-11-27
| Copyright:   (C) Copyright 2014, Imron Rosdiana
| Licence:     GPL (General Public License) V.3
*/

#ifndef FORMLOGIN_H
#define FORMLOGIN_H

#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>

// MongoDB Connection
#ifdef Q_OS_WIN
    #include <WinSock2.h>
    #include <Windows.h>
#endif //Q_OS_WIN
#include "mongo/client/dbclient.h" // for the driver

class FormLogin : public QDialog
{
    Q_OBJECT

public:
    explicit FormLogin(QWidget* parent = 0);
    ~FormLogin();

private slots:
    void OnQuit();
    void OnLogin();

private:
    void reject();

    QLabel* userLabel;
    QLabel* passLabel;
    QLineEdit* userLineEdit;
    QLineEdit* passLineEdit;
    QPushButton* loginButton;
    QPushButton* quitButton;
};

#endif // FORMLOGIN_H
