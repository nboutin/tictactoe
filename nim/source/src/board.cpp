
#include "board.h"

using namespace nim;

bool Board::play(const move_t m)
{
    if((m < MOVE_MIN) || (m > MOVE_MAX) || (tokens - m) < TOKEN_MIN)
        return false;

    tokens -= m;
    return true;
}

void Board::unplay(const move_t m) { tokens += m; }
