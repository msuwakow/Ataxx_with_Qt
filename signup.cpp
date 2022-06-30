#include "signup.h"
#include "ui_signup.h"
#include "file.h"
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QCryptographicHash>
#include <QMessageBox>

#include <QDebug>

Signup::Signup(QDialog *parent)
    : QDialog(parent)
    , ui(new Ui::Form), last(nullptr)
{

    ui->setupUi(this);

    ui->repeat_2->setEchoMode(QLineEdit::Password);
    ui->password_2->setEchoMode(QLineEdit::Password);
    QRegularExpression re("\\w{3,20}");
    QRegularExpressionValidator val(re);
    ui->username_2->setValidator(&val);
    ui->password_2->setValidator(&val);
    ui->repeat_2->setValidator(&val);
//    ui->forwards->show();
//    ui->backwards->show();
//    setModal(true);
//    show();
//    exec();
}

Signup::~Signup() {
    if (last != nullptr) {
        last->close();
        delete last;
        last = nullptr;
    }
    delete ui;
}

void Signup::on_forwards_clicked() {
    if (last != nullptr) {
        last->close();
        delete last;
        last = nullptr;
    }
    if (ui->username_2->text().length() < 3) {
        QLabel *hint = new QLabel(this);
        last = hint;
        hint->setText("用户名过短。");
        hint->setGeometry(130, 210, 200, 30);
        hint->show();
        return;
    }
    if (ui->password_2->text().length() < 3) {
        QLabel *hint = new QLabel(this);
        last = hint;
        hint->setText("密码过短。");
        hint->setGeometry(130, 210, 200, 30);
        hint->show();
        return;
    }
    if (ui->password_2->text() != ui->repeat_2->text()) {
        QLabel *hint = new QLabel(this);
        last = hint;
        hint->setText("两次输入的密码不一致。");
        hint->setGeometry(130, 210, 200, 30);
        hint->show();
        return;
    }
    auto it = IO.readSingleProfile(ui->username_2->text());
    if (it.username != "") {
        QLabel *hint = new QLabel(this);
        last = hint;
        hint->setText("该用户名已被占用。");
        hint->setGeometry(130, 210, 200, 30);
        hint->show();
        return;
    }
    QMessageBox::information(this, tr("注册成功"),
                    tr("您现在可以从“本地登录”处登录了。"), QMessageBox::Ok);
    close();
    GameState ret;
    ret.EXP = 1000;
    ret.username = ui->username_2->text().toStdString();
    ret.password_md5 = QCryptographicHash::hash((ui->password_2->text() +
            ui->username_2->text()).toLatin1(), QCryptographicHash::Md5).toStdString();
    IO.writeSingleProfile(ret);
    return;
}

void Signup::on_backwards_clicked() {
    close();
    return;
}
