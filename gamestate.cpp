#include <cstdio>
#include <ctime>
#include <vector>
#include <string>

#include <QDebug>

#include "chessboard.h"
#include "gamestate.h"

    // r = 0: 到先手了
    // p = 1: 人类是先手


    GameState::GameState(void) : EXP(0), chances(0), t(0), p(0), d(0), r(false)
    {
        return;
    }

    void GameState::Read(FILE *f)
    {
        int n;

        int length;
        char tmp[100];

        fread(&length, sizeof length, 1, f);

        fread(tmp, length, 1, f);
        tmp[length] = 0;
        username.assign(tmp);

        fread(tmp, 32, 1, f);
        tmp[32] = 0;
        password_md5.assign(tmp);

        fread(&EXP, sizeof EXP, 1, f);
        fread(&chances, sizeof chances, 1, f);

        fread(&t, sizeof t, 1, f);
        fread(&p, sizeof p, 1, f);
        fread(&d, sizeof d, 1, f);
        fread(&r, sizeof r, 1, f);
        fread(&n, sizeof n, 1, f);
        if(n)
        {
            v.resize(n);
            fread(&v[0], sizeof(ChessBoard), n, f);
            g = v.back();
        }

        return;
    }

    void GameState::Write(FILE *f)
    {
        int n;

        int length = username.length();
        fwrite(&length, sizeof length, 1, f);
        fwrite(username.c_str(), length, 1, f);

        fwrite(password_md5.c_str(), 32, 1, f);

        fwrite(&EXP, sizeof EXP, 1, f);
        fwrite(&chances, sizeof chances, 1, f);

        n = (int)v.size();
        fwrite(&t, sizeof t, 1, f);
        fwrite(&p, sizeof p, 1, f);
        fwrite(&d, sizeof d, 1, f);
        fwrite(&r, sizeof r, 1, f);
        fwrite(&n, sizeof n, 1, f);
        if(n)
            fwrite(&v[0], sizeof(ChessBoard), n, f);

        return;
    }

// 会 CE，寄
//    friend bool compareEXP(const GameState &a, const GameState &b);
// 要么重载运算符，要么把 .hpp 拆开，哈哈
    bool GameState::operator < (const GameState &a) const {
        return EXP > a.EXP;
    }

//bool compareEXP(const GameState &a, const GameState &b) {
//    return a.EXP > b.EXP;
//}
