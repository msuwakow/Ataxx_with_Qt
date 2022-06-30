#include "nopainter.h"
#include "ui_nopainter.h"
#include "gamestate.h"
#include "game.h"
#include "pos.h"
#include <QInputDialog>

#include <QDebug>

Nopainter::Nopainter(GameState &x, QDialog *parent)
    : QDialog(parent)
    , ui(new Ui::nopainter)
{

    ui->setupUi(this);

    ui->blackScore->close();
    ui->whiteScore->close();

    ui->leftup->close();
    ui->rightdown->close();

    for (int i = 0; i <= 6; ++i) {
        for (int j = 0; j <= 6; ++j) {
            black[i][j].setParent(this);
            white[i][j].setParent(this);
            black[i][j].setStyleSheet(tr("border-image: "
                                         "url(:/myImages/images/black_selected.png);"));
            white[i][j].setStyleSheet(tr("border-image: "
                                         "url(:/myImages/images/white_selected.png);"));
            black[i][j].setGeometry(66 + j * 72.8, 163 + i * 72.8, 60, 60);
            white[i][j].setGeometry(66 + j * 72.8, 163 + i * 72.8, 60, 60);
            black[i][j].close();
            white[i][j].close();
        }
    }

    Pos::Init();
    Game::Gameloop(x, *this);

}

void Nopainter::paint(GameState &x) {
    int nb = 0, nw = 0;
    for (int i = 0; i <= 6; ++i)
        for (int j = 0; j <= 6; ++j) {
            black[i][j].close();
            white[i][j].close();

            if (x.g.v[0] & (1ull << (i * 8 + j)))
                black[i][j].show(), ++nb;
            if (x.g.v[1] & (1ull << (i * 8 + j)))
                white[i][j].show(), ++nw;
        }
    ui->whiteScore->setText(QString(std::to_string(nw).c_str()));
    ui->blackScore->setText(QString(std::to_string(nb).c_str()));
    ui->whiteScore->show();
    ui->blackScore->show();
    QString p = QString("你还有 ") + QString(std::to_string(x.chances).c_str()) +
                QString(" 次悔棋机会，请善加利用。");
    ui->regrets->setText(p);
    ui->regrets->show();
    exec();
}

std::pair<int, int> Nopainter::ScanPos1() {

    while (1) {
        QString string =
         QInputDialog::getText(this, tr("到你下棋了"),
                tr("请输入你的棋子的起始位置："), QLineEdit::Normal);
        if (string == QString("ZZ")) {
            return std::make_pair(-1, -1);
        }
        if (string == QString("RR")) {
            return std::make_pair(-2, -2);
        }
        if (string[0] >= 'A' && string[0] <= 'G' && string[1] >= '1' && string[1] <= '7') {
            return std::make_pair(string[0].toLatin1() - 65, string[1].toLatin1() - 49);
        }
    }

    return std::make_pair(0, 0);
}

std::pair<int, int> Nopainter::ScanPos2() {
    while (1) {
        QString string =
         QInputDialog::getText(this, tr("到你下棋了"),
                tr("请输入你的棋子的结束位置："), QLineEdit::Normal);
        if (string == QString("ZZ")) {
            return std::make_pair(-1, -1);
        }
        if (string == QString("RR")) {
            return std::make_pair(-2, -2);
        }
        if (string[0] >= 'A' && string[0] <= 'G' && string[1] >= '1' && string[1] <= '7') {
            return std::make_pair(string[0].toLatin1() - 65, string[1].toLatin1() - 49);
        }
    }

    return std::make_pair(0, 0);
}


Nopainter::~Nopainter() {

    delete ui;
}


