#ifndef _ATAXX_AI_HPP_
#define _ATAXX_AI_HPP_

#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <utility>
#include "chessboard.h"

namespace AI
{
    class State
    {
    public:
        int x;
        int y;
        int v;

        State(int _x = 0, int _y = 0, int _v = 0);

        bool operator<(const State &that) const;
    };

    const int TL = int(0.9 * CLOCKS_PER_SEC);

    extern clock_t t;
    extern int p;

    __attribute__((always_inline)) inline void Checkmax(int &a, int b)
    {
        a = a > b ? a : b;

        return;
    }

    __attribute__((always_inline)) inline void Checkmin(int &a, int b)
    {
        a = a < b ? a : b;

        return;
    }

    int AlphaBeta(ChessBoard g, int d, int a, int b, bool m);

    void FirstStep(ChessBoard g, std::vector<State> &f, int d);

    State BetaAlpha(ChessBoard g, State o, int d);

    void Step(ChessBoard g, int p, int l, std::pair<int, int> &x, std::pair<int, int> &y);

}

#endif
