
#include "evaluate.h"
#include "connect4.h"

using namespace connect4;
using namespace std;

namespace ai
{
int16_t evaluate(const connect4::Connect4& g, const color_e win_color)
{
    if(g.is_finished() && g.get_winner_player() != nullptr)
    {
        if(g.get_winner_player()->get_color() == win_color)
            return WIN_POINT;
        else
            return LOOSE_POINT;
    }
    return 0;
}
}
