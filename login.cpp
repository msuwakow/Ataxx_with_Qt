#include "login.h"
#include "ui_login.h"
#include "file.h"
#include "mainmenu.h"
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QCryptographicHash>
#include <QMessageBox>

#include <QDebug>

Login::Login(QDialog *parent)
    : QDialog(parent)
    , ui(new Ui::login), last(nullptr)
{

    ui->setupUi(this);

    ui->password_8->setEchoMode(QLineEdit::Password);
    QRegularExpression re("\\w{3,20}");
    QRegularExpressionValidator val(re);
    ui->username_8->setValidator(&val);
    ui->password_8->setValidator(&val);
//    ui->forwards->show();
//    ui->backwards->show();
//    setModal(true);
//    show();
//    exec();
}

Login::~Login() {
    if (last != nullptr) {
        last->close();
        delete last;
        last = nullptr;
    }
    delete ui;
}

GameState lastSucceedLogin::last;

void Login::on_forwards_clicked() {
    if (last != nullptr) {
        last->close();
        delete last;
        last = nullptr;
    }
    auto it = IO.readSingleProfile(ui->username_8->text());
    if (it.username == "" || it.password_md5 !=
            QCryptographicHash::hash((ui->password_8->text() +
            ui->username_8->text()).toLatin1(), QCryptographicHash::Md5).toStdString()) {
        QLabel *hint = new QLabel(this);
        last = hint;
        hint->setText("用户名或密码错误。");
        hint->setGeometry(130, 210, 200, 30);
        hint->show();
        return;
    }
    QMessageBox::information(this, tr("登录成功"),
                    tr("正在为您跳转至主页。"), QMessageBox::Ok);
    lastSucceedLogin::last = it;
    accept();
    close();
    return;
}

void Login::on_backwards_clicked() {
    reject();
    close();
    return;
}
