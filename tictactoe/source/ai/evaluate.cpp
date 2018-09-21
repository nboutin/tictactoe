
#include "evaluate.h"

int16_t evaluate(const tictactoe::TicTacToe& g, tictactoe::token_e win_token)
{
    if(g.is_finished())
    {
        if(g.get_winner_player().get_token() == win_token)
            return WIN_POINT;
        else
            return LOOSE_POINT;
    }
    return 0;
}
