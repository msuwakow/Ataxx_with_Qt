#include "chooser2.h"
#include "ui_chooser2.h"

#include <QDebug>

Chooser2::Chooser2(int &_ans, QDialog *parent)
    : QDialog(parent)
    , ui(new Ui::chooser2), ans(_ans)
{

    ui->setupUi(this);

}

Chooser2::~Chooser2() {
    delete ui;
}

void Chooser2::on_forwards_clicked() {
    if (ans == 0) return;
    accept();
    close();
    return;
}

void Chooser2::on_backwards_clicked() {
    reject();
    close();
    return;
}

void Chooser2::on_b1_clicked() {
    ans = 1;
}
void Chooser2::on_b2_clicked() {
    ans = 2;
}
