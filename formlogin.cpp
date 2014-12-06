/*
|-------------------------------------------------------------------------------
| Name:        formlogin.cpp
| Author:      Imron Rosdiana
| Modified by:
| Created:     2014-11-27
| Copyright:   (C) Copyright 2014, Imron Rosdiana
| Licence:     GPL (General Public License) V.3
*/

#include "formlogin.h"
#include <iostream>

using namespace std;
using namespace configApp;

FormLogin::FormLogin(QWidget* parent) : QDialog(parent)
{
    setFixedSize(300, 120);
    setWindowTitle("Form Login");
    setModal(true);

    userLabel = new QLabel("Username:");
    passLabel = new QLabel("Password:");
    userLineEdit = new QLineEdit();
    passLineEdit = new QLineEdit();
    passLineEdit->setEchoMode(QLineEdit::Password);
    loginButton = new QPushButton("Login");
    quitButton = new QPushButton("Quit");


    QVBoxLayout* vbox = new QVBoxLayout(this);
    QHBoxLayout* hbox1 = new QHBoxLayout();
    QHBoxLayout* hbox2 = new QHBoxLayout();
    QHBoxLayout* hbox3 = new QHBoxLayout();

    hbox1->addWidget(userLabel, 1);
    hbox1->addWidget(userLineEdit, 2);
    hbox2->addWidget(passLabel, 1);
    hbox2->addWidget(passLineEdit, 2);
    hbox3->addWidget(loginButton, 1, Qt::AlignRight);
    hbox3->addWidget(quitButton, 0, Qt::AlignRight);

    vbox->addStretch(1);
    vbox->addLayout(hbox1);
    vbox->addLayout(hbox2);
    vbox->addLayout(hbox3);

    connect(quitButton, SIGNAL(clicked()), this, SLOT(OnQuit()));
    connect(loginButton, SIGNAL(clicked()), this, SLOT(OnLogin()));
}

void FormLogin::reject()
{
    OnQuit();
}

void FormLogin::OnQuit()
{
    this->close();
    parentWidget()->close();
}

void FormLogin::OnLogin()
{
    QString username = userLineEdit->text();
    QString password = passLineEdit->text();

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::information(this, tr("Peringatan!"), "Username atau password tidak boleh kosong");
    } else {
        MD5 md5;
        // check user in database is exist or not
        int isAuth = CheckUser(username.toStdString(), md5(password.toStdString()));
        if (isAuth > 0) {
            // user is logged in and destroy form login
            this->accept();
        } else {
            QMessageBox::information(this, tr("Peringatan!"), "Username atau Password Salah");
        }
    }
    #ifdef _WIN32
        // Disconnect database
        Config::DisconnectDB();
    #endif _WIN32
}

int FormLogin::CheckUser(string username, string password)
{
    // initialization user
    int n = 0;
    // if connect success
    if (Config::ConnectDB() > 0) {
        QMessageBox::warning(this, "Error", "Database tidak terkoneksi");
        return n;
    }
    // check user in database
    n = c.count("sia.users", BSON("username" << username << "password" << password));
    return n;
}

FormLogin::~FormLogin() {}
