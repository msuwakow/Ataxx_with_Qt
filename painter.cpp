#include "painter.h"
#include "ui_painter.h"
#include "gamestate.h"
#include "game.h"
#include "chessboard.h"

#include <QDebug>

Painter::Painter(QDialog *parent)
//    : QDialog(parent)
//    , ui(new Ui::painter)
{
//    ui->setupUi(this);
//    ui->pushButton->close();
//    ui->pushButton_2->close();

//    for (int i = 0; i <= 6; ++i) {
//        for (int j = 0; j <= 6; ++j) {
//            black[i][j].setStyleSheet(tr("border-image: "
//                                         "url(:/myImages/images/black_normal.png);"));
//            white[i][j].setStyleSheet(tr("border-image: "
//                                         "url(:/myImages/images/white_normal.png);"));
//            blackWithdraw[i][j].setStyleSheet(tr("border-image: "
//                                        "url(:/myImages/images/black_selected.png);"));
//            whiteWithdraw[i][j].setStyleSheet(tr("border-image: "
//                                        "url(:/myImages/images/white_selected.png);"));
//            spaceCloser[i][j].setStyleSheet(tr("border-image: "
//                                        "url(:/myImages/images/space_green.png);"));
//            spaceFarther[i][j].setStyleSheet(tr("border-image: "
//                                        "url(:/myImages/images/space_blue.png);"));
//            blackOpposite[i][j].setStyleSheet(tr("border-image: "
//                                        "url(:/myImages/images/black_normal.png);"));
//            whiteOpposite[i][j].setStyleSheet(tr("border-image: "
//                                        "url(:/myImages/images/white_normal.png);"));
//            black[i][j].setGeometry(34 + j * 78.5, 116 + i * 78.5, 60, 60);
//            white[i][j].setGeometry(34 + j * 78.5, 116 + i * 78.5, 60, 60);
//            blackWithdraw[i][j].setGeometry(34 + j * 78.5, 116 + i * 78.5, 60, 60);
//            whiteWithdraw[i][j].setGeometry(34 + j * 78.5, 116 + i * 78.5, 60, 60);
//            spaceCloser[i][j].setGeometry(34 + j * 78.5, 116 + i * 78.5, 60, 60);
//            spaceFarther[i][j].setGeometry(34 + j * 78.5, 116 + i * 78.5, 60, 60);
//            blackOpposite[i][j].setGeometry(34 + j * 78.5, 116 + i * 78.5, 60, 60);
//            whiteOpposite[i][j].setGeometry(34 + j * 78.5, 116 + i * 78.5, 60, 60);
//            black[i][j].close();
//            white[i][j].close();
//            blackWithdraw[i][j].close();
//            whiteWithdraw[i][j].close();
//            spaceCloser[i][j].close();
//            spaceFarther[i][j].close();
//            blackOpposite[i][j].close();
//            whiteOpposite[i][j].close();
//        }
//    }
}

Painter::~Painter() {

    delete ui;
}

void Painter::on_regret_clicked() {

}

void Painter::on_quit_clicked() {

}

std::pair<int, int> Painter::query(GameState a) {
    reset(a);
}

void Painter::paint(GameState a) {
    reset(a);
    return;
}

void Painter::reset(GameState a) {
//    if ((a.p == 1) ^ a.r) {
//        for (int i = 0; i <= 6; ++i)
//            for (int j = 0; j <= 6; ++j) {
//                black[i][j].close();
//                white[i][j].close();
//                blackWithdraw[i][j].close();
//                whiteWithdraw[i][j].close();
//                spaceCloser[i][j].close();
//                spaceFarther[i][j].close();
//                blackOpposite[i][j].close();
//                whiteOpposite[i][j].close();
//                if (a.g.v[0] & (1ll << (i * 8 + j))) {
//                    if (a.p == 1)
//                        black[i][j].show();
//                    else
//                        blackOpposite[i][j].show();
//                }
//                if (a.g.v[1] & (1ll << (i * 8 + j))) {
//                    if (a.p == -1)
//                        white[i][j].show();
//                    else
//                        whiteOpposite[i][j].show();
//                }
//            }
//    }
//    else {
//        for (int i = 0; i <= 6; ++i)
//            for (int j = 0; j <= 6; ++j) {
//                black[i][j].close();
//                white[i][j].close();
//                blackWithdraw[i][j].close();
//                whiteWithdraw[i][j].close();
//                spaceCloser[i][j].close();
//                spaceFarther[i][j].close();
//                blackOpposite[i][j].close();
//                whiteOpposite[i][j].close();
//                if (a.g.v[0] & (1ll << (i * 8 + j)))
//                    blackOpposite[i][j].show();
//                if (a.g.v[1] & (1ll << (i * 8 + j)))
//                    whiteOpposite[i][j].show();
//            }
//    }
}

//Painter pt;
