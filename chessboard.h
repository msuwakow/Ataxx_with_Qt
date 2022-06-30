#ifndef _ATAXX_CHESSBOARD_HPP_
#define _ATAXX_CHESSBOARD_HPP_

#include <utility>
#include "pos.h"

class ChessBoard
{
public:
    unsigned long long v[2];

    ChessBoard(void);

    inline int ID(int x, int y)
    {
        return x << 3 | y;
    }

    inline int ID(std::pair<int, int> x)
    {
        return x.first << 3 | x.second;
    }

    inline std::pair<int, int> DI(int x)
    {
        return std::make_pair(x >> 3, x & 7);
    }

    void Convert(int _v[7][7]);

    void Move(int k, int x, int y);

    inline int Value(void)
    {
        int x, y;

        x = __builtin_popcountll(v[0]);
        y = __builtin_popcountll(v[1]);

        return x - y + (!x ? -64 : !y ? 64 : 0) + (x + y == 49 ? (x > y ? 64 : -64) : 0);
    }
};

#endif
