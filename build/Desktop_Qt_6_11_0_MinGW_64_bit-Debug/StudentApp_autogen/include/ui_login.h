/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QLabel *titleLabel;
    QLabel *usernameLabel;
    QLineEdit *usernameEdit;
    QLineEdit *passwordEdit;
    QLabel *passwordLabel;
    QPushButton *loginButton;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(1822, 897);
        QFont font;
        font.setPointSize(16);
        Login->setFont(font);
        titleLabel = new QLabel(Login);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setGeometry(QRect(630, 260, 121, 41));
        QFont font1;
        font1.setPointSize(12);
        titleLabel->setFont(font1);
        usernameLabel = new QLabel(Login);
        usernameLabel->setObjectName("usernameLabel");
        usernameLabel->setGeometry(QRect(730, 60, 211, 81));
        usernameLabel->setMaximumSize(QSize(211, 81));
        QFont font2;
        font2.setPointSize(18);
        font2.setBold(true);
        usernameLabel->setFont(font2);
        usernameEdit = new QLineEdit(Login);
        usernameEdit->setObjectName("usernameEdit");
        usernameEdit->setGeometry(QRect(900, 270, 221, 31));
        usernameEdit->setMinimumSize(QSize(6, 2));
        passwordEdit = new QLineEdit(Login);
        passwordEdit->setObjectName("passwordEdit");
        passwordEdit->setGeometry(QRect(900, 370, 221, 31));
        passwordEdit->setEchoMode(QLineEdit::EchoMode::Password);
        passwordLabel = new QLabel(Login);
        passwordLabel->setObjectName("passwordLabel");
        passwordLabel->setGeometry(QRect(630, 370, 131, 31));
        passwordLabel->setFont(font1);
        passwordLabel->setAutoFillBackground(false);
        loginButton = new QPushButton(Login);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(770, 570, 91, 31));
        QFont font3;
        font3.setPointSize(10);
        loginButton->setFont(font3);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Login", nullptr));
        titleLabel->setText(QCoreApplication::translate("Login", "Username", nullptr));
        usernameLabel->setText(QCoreApplication::translate("Login", "Login System", nullptr));
        usernameEdit->setText(QString());
        passwordEdit->setText(QString());
        passwordLabel->setText(QCoreApplication::translate("Login", "Password", nullptr));
        loginButton->setText(QCoreApplication::translate("Login", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
