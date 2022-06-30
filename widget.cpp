#include "widget.h"
#include "ui_widget.h"
#include "file.h"
#include "gamestate.h"
#include "level.h"
#include "signup.h"
#include "login.h"
#include "mainmenu.h"

#include <QMessageBox>
#include <QWizardPage>
#include <QLabel>
#include <QVector>
#include <QString>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QTableWidgetItem>

#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle(QString::fromUtf8("Ataxx Max Pro Plus Premium Ultra Supreme Special Remastered GotY Deluxe Edition"));
}

void Widget::on_aboutButton_clicked() {
    QMessageBox::about(this, tr("关于我们"),
                       tr("小组名称：花青大学\n"
                          "组长：袁傲慕飞\n"
                          "组员：梁浩奋 王浩如\n"
                          "感谢你玩我们的游戏！"));
}

void Widget::on_quitButton_clicked() {
    close();
}

void Widget::on_leaderBoardButton_clicked() {
    // 把所有玩家的数据读进来
    // 俺寻思复杂度也不高，毕竟没几个人玩这垃圾游戏
    // Waaaaaaaagh!!
    QVector<GameState> data = IO.readAllProfiles();
    std::sort(data.begin(), data.end());
    while (data.size() < 15) {
        GameState tmp;
        tmp.username = "虚位以待";
        data.emplaceBack(tmp);
    }
    QDialog *cushion = new QDialog(this);
    cushion->setObjectName(QString::fromUtf8("cushion"));
    cushion->setGeometry(QRect(100, 100, 400, 600));
    cushion->setWindowTitle(QString("Leader Board of the Top 15"));
    cushion->setModal(true);
    cushion->show();
    QTableWidget *tableWidget = new QTableWidget(cushion);
    tableWidget->setGeometry(QRect(0, 0, 400, 580));
    tableWidget->setColumnCount(3);
    tableWidget->setRowCount(15);
    QStringList m_Header;
    m_Header<<QString("用户名")<<QString("积分（EXP)")<<QString("等级");
    tableWidget->setHorizontalHeaderLabels(m_Header);
    for (int i = 0; i < 15; ++i) {
        tableWidget->setItem(i, 0, new QTableWidgetItem(data[i].username.c_str()));
        tableWidget->setItem(i, 1, new QTableWidgetItem(data[i].EXP));
        tableWidget->setItem(i, 2, new QTableWidgetItem(LEVEL::findLevel(data[i].EXP).second));
    }
    tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableWidget->show();
    QPushButton *bt = new QPushButton(QString("返回主菜单"), tableWidget);
    bt->setGeometry(150, 500, 100, 40);
    bt->show();
    connect(bt, &QPushButton::clicked, tableWidget, &QTableWidget::close);
    connect(bt, &QPushButton::clicked, cushion, &QWidget::close);
}

void Widget::on_rulesButton_clicked() {
    QWizard wizard(this);
    wizard.setWindowTitle(tr("规则速览"));
    wizard.addPage(createPage1());
    wizard.resize(400, 500);
    wizard.exec();
}

QWizardPage * Widget::createPage1() {
    QWizardPage *page = new QWizardPage;
    page->setTitle(tr("同化棋（Ataxx）规则速览"));

    QLabel *label = new QLabel("同化棋（Ataxx），是 Dave Crummack 和 Craig Galley 在 1988 年发明，1990 年出品于电视游戏而流行的两人棋类，可说是黑白棋的衍生。\n"
                               "游戏在 7*7 的方格棋盘上进行，以黑白色棋子区分对局双方，执黑棋者先手。\n"
                               "初始布置为双方各将两枚棋子放在最外的对角格。\n"
                               "玩家必须轮流移动一枚己子到一个空棋位，该棋位可以是邻近八格（包括对角相邻的格）之一，或相隔一格的次邻十二格之一。移动的新棋位，会使邻近的所有敌棋如黑白棋一样变成己方。如果棋子移到的是邻接八格，会有一颗新己棋出现在原先棋位。\n"
                               "无法行棋需弃权。当两方都无法行棋时，游戏结束。以最多子者胜。\n"
                               "在我们的 Ataxx Max Pro Plus Premium Ultra Supreme Special Remastered GotY Deluxe Edition 中，每位注册玩家按照与不同 AI 对局的胜负场数积累经验，提升等级，并按照等级享有不同的每局悔棋次数。\n"
                               "So......\n"
                               "Let's Rock'n Roll!!");

    label->setWordWrap(true);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(label);
    page->setLayout(layout);

    return page;
}

void Widget::on_signupButton_clicked() {
    Signup sg;
    sg.exec();
}

void Widget::on_loginButton_clicked() {
    Login lg;
    if (lg.exec() == QDialog::Accepted) {
        close();

        Mainmenu mn(lastSucceedLogin::last);
        mn.exec();

        show();
    }
}

Widget::~Widget()
{
    delete ui;
}

