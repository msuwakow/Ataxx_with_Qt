#include <ctime>
#include <vector>
#include <utility>
#include <QMessageBox>
#include "pos.h"
#include "chessboard.h"
#include "ai.h"
#include "nopainter.h"
#include "game.h"

namespace Game
{
    bool PlayerCheck(ChessBoard &g, int k)
    {
        int i;

        for(i = 0; i < 64; i ++)
            if((g.v[k] >> i & 1) && (~(g.v[0] | g.v[1]) & (Pos::p[i] | Pos::q[i])))
                return true;

        return false;
    }

    void MoveChess(ChessBoard &g, std::pair<int, int> x, std::pair<int, int> y)
    {
        int k;

        k = !(g.v[0] >> g.ID(x) & 1);
        g.v[k] |= 1ULL << g.ID(y);
        if(Pos::Chebyshev(x, y) == 2)
            g.v[k] ^= 1ULL << g.ID(x);

        return;
    }

    bool FlipChess(ChessBoard &g, int k, std::pair<int, int> q)
    {
        unsigned long long o;

        o = g.v[!k] & Pos::p[g.ID(q)];
        g.v[k] |= o;
        g.v[!k] ^= o;

        return !!o;
    }

    void Step(GameState &g, std::pair<int, int> &x, std::pair<int, int> &y, Nopainter &pt)
    {
        if(!PlayerCheck(g.g, g.r))
        {
            QMessageBox msgBox;
            msgBox.setWindowTitle("哎呀!");
            msgBox.setText("你无路可走了。");
            msgBox.setInformativeText("想要悔棋吗？");
            msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            msgBox.setDefaultButton(QMessageBox::No);
            int ret = msgBox.exec();
            if (ret == QMessageBox::Yes && g.chances <= 0) {
                QMessageBox::warning(nullptr, QString("糟糕！"),
                    QString("你的悔棋次数用完了"), QMessageBox::Ok);
               ret = QMessageBox::No;
            }
            x.first = (ret == QMessageBox::Yes) ? -2 : -1;
        }
        else
        {
//            printf("Enter Ax By to move your chess (ZZ for quit, RR for regret): ");
            while(true)
            {
                x = pt.ScanPos1();
                if(x.first == -1)
                    break;
                if(x.first == -2)
                {
                    if (g.chances <= 0) {
                        QMessageBox::warning(nullptr, QString("糟糕！"),
                            QString("你的悔棋次数用完了"), QMessageBox::Ok);
                       continue;
                    }
                    if(g.v.size() <= 2U)
                    {
                        QMessageBox::warning(nullptr, QString("不行！"),
                            QString("现在已经无棋可悔了"), QMessageBox::Ok);
                        continue;
                    }
                    break;
                }
                while((y = pt.ScanPos2()).first < 0)
                    ;
                if(~g.g.v[g.r] >> g.g.ID(x) & 1) {
                    QMessageBox::warning(nullptr, QString("错误！"),
                        QString("你移动的不是你的棋子"), QMessageBox::Ok);
                }
                else if(g.g.v[0] >> g.g.ID(y) & 1 || g.g.v[1] >> g.g.ID(y) & 1) {
                    QMessageBox::warning(nullptr, QString("错误！"),
                        QString("棋子的落点不是空地"), QMessageBox::Ok);
                }
                else if(Pos::Chebyshev(x, y) < 1 || Pos::Chebyshev(x, y) > 2) {
                    QMessageBox::warning(nullptr, QString("错误！"),
                        QString("太远了，你的棋子过不去"), QMessageBox::Ok);
                }
                else
                    break;
            }
        }

        return;
    }

    int check(GameState &g) {
        int x, y, w;

        x = __builtin_popcountll(g.g.v[0]);
        y = __builtin_popcountll(g.g.v[1]);
        if(!y || (x + y == 49 && x > y))
            w = 0;
        else if(!x || (x + y == 49 && y > x))
            w = 1;
        else
            w = -1;
       return w;
    }

    void Gameloop(GameState &g, Nopainter &pt)
    {
        qDebug() << g.g.v[0] << ' ' << g.g.v[1] << Qt::endl;
        std::pair<int, int> x, y;
        int w;
        bool s;

        while(true)
        {
            g.v.push_back(g.g);
            pt.paint(g);

            if(!g.d || (g.p == 1) ^ g.r)
            {
                Step(g, x, y, pt);
                if(x.first == -1)
                {
                    g.t = time(NULL);
                    return;
                }
                else if(x.first == -2)
                {
                    --g.chances;
                    g.v.pop_back();
                    g.v.pop_back();
                    g.g = g.v.back();
                    g.v.pop_back();
                    continue;
                }
            }
            else
            {
                AI::Step(g.g, g.p, g.d == 1 ? 4 : g.d == 2 ? 6 : 2147483647, x, y);
                if(x.first == -1)
                {
                    QMessageBox::information(nullptr, QString("摸了！"),
                            QString("AI 这回合放弃了思考。"));
                }
            }

            if(x.first != -1)
            {
                MoveChess(g.g, x, y);
                pt.paint(g);
                s = FlipChess(g.g, g.r, y);
                w = check(g);
                if(s)
                {
                    pt.paint(g);
                }
                if(w != -1)
                {
                    if((g.p == 1) ^ w) {
                        QMessageBox::information(nullptr, QString("Good Game！"),
                            QString("AI 彻底放弃了思考。你赢了！"));
                    }
                    else {
                        if (g.d == 1) {
                            QMessageBox::information(nullptr, QString("不会吧不会吧"),
                                QString("竟然有人连最菜的 AI 都打不过？"));
                        }
                        else if (g.d == 2) {
                            QMessageBox::information(nullptr, QString("就这"),
                                QString("菜就多练练"));
                        }
                        else {
                            QMessageBox::information(nullptr, QString("寄！"),
                                QString("感觉不如 Alpha Go... 算力"));
                        }

                    }
                    g.p = 0;
                    break;
                }
            }

            g.r ^= 1;
        }

        return;
    }
}
