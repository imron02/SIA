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
#include <QDebug>
#include <QCryptographicHash>
#include <QString>

using namespace mongo;

FormLogin::FormLogin(QWidget* parent) : QDialog(parent)
{
    setFixedSize(300, 120);
    setWindowTitle("Form Login");
    setModal(true);
    setAttribute(Qt::WA_DeleteOnClose);

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

    vbox->addSpacing(1);
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

    // Checking if username or password is empty
    if (username.isEmpty() || password.isEmpty())
        QMessageBox::information(this, tr("Peringatan!"), "Username atau password tidak boleh kosong");

    #ifdef Q_OS_WIN
        client::initialize();
    #endif // Q_OS_WIN

    try {
        DBClientConnection c;
        c.connect("localhost");

        QCryptographicHash md5Generator(QCryptographicHash::Md5);
        md5Generator.addData(QByteArray(password.toUtf8()));
        QString cryptPassword = md5Generator.result().toHex();

        short n = c.count("sia.users", BSON("username" << username.toStdString()
                                             << "password" << cryptPassword.toStdString()));
        if  (n > 0)
            this->accept();
        else
          QMessageBox::information(this, tr("Peringatan!"), "Username atau Password Salah");
    } catch (const DBException &e) {
        qDebug() << "caught " << e.what();
        QMessageBox::warning(this, "Error", "Database tidak terkoneksi");
    }

    #ifdef Q_OS_WIN
        client::shutdown();
    #endif // Q_OS_WIN
}

FormLogin::~FormLogin() {}
