#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include <QLineEdit>

Login::Login(QWidget *parent)
    : QDialog(parent), ui(new Ui::Login)
{
    ui->setupUi(this);
    connect(ui->usernameEdit, &QLineEdit::returnPressed,
            this, [=]()
            {
                ui->passwordEdit->setFocus();
            });
    connect(ui->passwordEdit, &QLineEdit::returnPressed,
            this, &Login::on_Login_clicked);
}
Login::~Login(){
    delete ui;
}

void Login::on_Login_clicked(){
    QString username = ui->usernameEdit->text().trimmed().toLower();
    QString password = ui->passwordEdit->text();

    if(password.isEmpty()){
        return;
    }

    if(username.isEmpty()){
        ui->usernameEdit->setFocus();
        return;
    }

    if(username == "admin" && password == "1007"){
        accept(); 
    }
    else{
        QMessageBox::warning(this, "Error", "Invalid Username or Password");
        ui->passwordEdit->clear();
        ui->passwordEdit->setFocus();
    }
}
void Login::on_loginButton_clicked(){
    on_Login_clicked();
}
