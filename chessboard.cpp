#include <utility>
#include "pos.h"
#include "chessboard.h"

    ChessBoard::ChessBoard(void)
    {
        v[0] = v[1] = 0;

        return;
    }


    void ChessBoard::Convert(int _v[7][7])
    {
        int i, j;

        v[0] = v[1] = 0;
        for(i = 0; i < 7; i ++)
            for(j = 0; j < 7; j ++)
                if(_v[i][j] == 1)
                    v[0] |= 1ULL << ID(i, j);
                else if(_v[i][j] == -1)
                    v[1] |= 1ULL << ID(i, j);

        return;
    }

    void ChessBoard::Move(int k, int x, int y)
    {
        unsigned long long s;

        v[k] |= 1ULL << y;
        if(Pos::q[x] >> y & 1)
            v[k] ^= 1ULL << x;
        s = v[!k] & Pos::p[y];
        v[k] |= s;
        v[!k] ^= s;

        return;
    }

