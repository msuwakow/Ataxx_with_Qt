#include "chooser1.h"
#include "ui_chooser1.h"

#include <QDebug>

Chooser1::Chooser1(int &_ans, QDialog *parent)
    : QDialog(parent)
    , ui(new Ui::chooser1), ans(_ans)
{

    ui->setupUi(this);

}

Chooser1::~Chooser1() {
    delete ui;
}

void Chooser1::on_forwards_clicked() {
    if (ans == 0) return;
    accept();
    close();
    return;
}

void Chooser1::on_backwards_clicked() {
    reject();
    close();
    return;
}

void Chooser1::on_b1_clicked() {
    ans = 1;
}
void Chooser1::on_b2_clicked() {
    ans = 2;
}
void Chooser1::on_b3_clicked() {
    ans = 3;
}
