#ifndef _ATAXX_GAME_HPP_
#define _ATAXX_GAME_HPP_

#include <ctime>
#include <vector>
#include <utility>
#include <QMessageBox>
#include "pos.h"
#include "chessboard.h"
#include "ai.h"
#include "gamestate.h"
#include "nopainter.h"

namespace Game
{
    bool PlayerCheck(ChessBoard &g, int k);

    void MoveChess(ChessBoard &g, std::pair<int, int> x, std::pair<int, int> y);

    bool FlipChess(ChessBoard &g, int k, std::pair<int, int> q);

    void Step(GameState &g, std::pair<int, int> &x, std::pair<int, int> &y, Nopainter &);

    void Gameloop(GameState &g, Nopainter &);

    int check(GameState &g);
}

#endif
