
#include "minmax.h"

#include <iostream>
#include <limits>

#include "evaluate.h"
//#include "view_ascii.h"

using namespace ai;
using namespace p4;
using namespace std;

Minmax::Minmax(const p4::Player& p, const uint8_t depth) : depth(depth), player(p) {}

uint8_t Minmax::compute(p4::Game_P4 game) const
{
    int16_t max       = std::numeric_limits<int16_t>::min();
    uint8_t best_move = 0;

    for(int m = 0; m < Board::N_COLUMN; ++m)
    {
        if(game.play(m))
        {
            int16_t val = min(game, depth);

            if(val > max)
            {
                max       = val;
                best_move = m;
            }
        }
        game.undo();
    }

    return best_move;
}

int16_t Minmax::min(p4::Game_P4& game, const uint8_t _depth) const
{
    if(_depth == 0 || game.is_finished())
        return evaluate(game.get_board().get_grid(), player.get_color());

    int16_t min = std::numeric_limits<int16_t>::max();

    for(int m = 0; m < Board::N_COLUMN; ++m)
    {
        if(game.play(m))
        {
            int16_t val = max(game, _depth - 1);
            if(val < min)
                min = val;
        }
        game.undo();
    }
    return min;
}

int16_t Minmax::max(p4::Game_P4& game, const uint8_t _depth) const
{
    if(_depth == 0 || game.is_finished())
        return evaluate(game.get_board().get_grid(), player.get_color());

    int16_t max = std::numeric_limits<int16_t>::min();

    for(int m = 0; m < Board::N_COLUMN; ++m)
    {
        if(game.play(m))
        {
            int16_t val = min(game, _depth - 1);
            if(val > max)
                max = val;
        }
        game.undo();
    }
    return max;
}
