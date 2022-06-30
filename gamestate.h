#ifndef _ATAXX_GAMESTATE_HPP_
#define _ATAXX_GAMESTATE_HPP_

#include <cstdio>
#include <ctime>
#include <vector>
#include <string>

#include <QDebug>

#include "chessboard.h"

class GameState
{
public:
    std::string username;
    std::string password_md5;
    int EXP;
    int chances;

    time_t t;
    int p;
    int d;
    int r;
    ChessBoard g;
    std::vector<ChessBoard> v;

    // r = 0: 到先手了
    // p = 1: 人类是先手


    GameState(void);

    void Read(FILE *f);

    void Write(FILE *f);

// 会 CE，寄
//    friend bool compareEXP(const GameState &a, const GameState &b);
// 要么重载运算符，要么把 .hpp 拆开，哈哈
    bool operator < (const GameState &a) const;
};

//bool compareEXP(const GameState &a, const GameState &b) {
//    return a.EXP > b.EXP;
//}

#endif
