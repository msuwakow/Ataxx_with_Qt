#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "gamestate.h"
#include "level.h"
#include "file.h"
#include "chooser1.h"
#include "chooser2.h"
#include "game.h"
#include "nopainter.h"
#include <QDebug>
#include <QMessageBox>

Mainmenu::Mainmenu(GameState x, QDialog *parent)
    : QDialog(parent)
    , ui(new Ui::mainmenu)
    , st(x)
{

    ui->setupUi(this);

    setWindowTitle(QString::fromUtf8("Ataxx Max Pro Plus Premium Ultra Supreme Special Remastered GotY Deluxe Edition"));

    auto rank = LEVEL::findLevel(st.EXP);

    QString myWelcome = "";
    myWelcome += QString("欢迎游玩同化棋（Ataxx），");
    myWelcome += QString(st.username.c_str());
    myWelcome += QString("。\n你现在的积分是 ");
    myWelcome += QString(std::to_string(st.EXP).c_str());
    myWelcome += QString(" 分，头衔是 ");
    myWelcome += rank.second;
    myWelcome += QString("。");

    ui->welcome->setText(myWelcome);
    ui->welcome->show();

    QString myWarning = "请注意，你目前有尚未完成的对局。\n"
                        "如果你开始新对局，你可能会丢失此前的对局信息！";

    ui->warning->setText(myWarning);
    if (st.p) {
        ui->warning->show();
    }
    else {
        ui->warning->hide();
    }

}

Mainmenu::~Mainmenu() {
    delete ui;

}

void Mainmenu::on_newGame_clicked() {
    int ans = 0;
    Chooser1 aiLev(ans);
    if (aiLev.exec() == QDialog::Rejected) {
        return;
    }
    int color = 0;
    Chooser2 col(color);
    if (col.exec() == QDialog::Rejected) {
        return;
    }
    GameState g;
    g.username = st.username;
    g.password_md5 = st.password_md5;
    g.EXP = st.EXP;
    g.chances = LEVEL::findLevel(g.EXP).first + 1;

    g.d = ans;
    g.p = color == 1 ? 1 : -1;
    g.g.v[0] = 1 | 1ULL << g.g.ID(6, 6);
    g.g.v[1] = 1ULL << g.g.ID(0, 6) | 1ULL << g.g.ID(6, 0);

    qDebug() << "QAQ " << g.g.v[0] << ' ' << g.g.v[1] << Qt::endl;

    close();
    Nopainter npt(g);
    npt.exec();
}

void Mainmenu::on_saveGame_clicked() {
    IO.writeSingleProfile(st);
    QMessageBox::information(this, QString("保存成功！"),
                        QString("温馨提示：请不要利用存读档功能悔棋"));
}

void Mainmenu::on_loadGame_clicked() {
    st = IO.readSingleProfile(QString(st.username.c_str()));
    QMessageBox::information(this, QString("读取成功！"),
                        QString("温馨提示：请不要利用存读档功能悔棋"));
    close();
    Nopainter npt(st);
    npt.exec();
}

void Mainmenu::on_quitGame_clicked() {
    close();
}


