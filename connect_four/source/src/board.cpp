
#include "board.h"

using namespace connect4;
using namespace std;

bool Board::play(const uint8_t x, const color_e color)
{
    if(x >= N_COLUMN)
        return false;

    auto y = find_free_row(x);

    if(!y)
        return false;

    grid[x][y.value()] = color;

    return true;
}

void Board::unplay(const uint8_t x)
{
    int y = 0;
    for(; y < N_ROW; ++y)
        if(grid[x][y])
            break;

    grid[x][y] = cell_t{};
}

optional<uint8_t> Board::find_free_row(const uint8_t x)
{
    for(int8_t y = N_ROW - 1; y >= 0; --y)
    {
        if(!grid[x][y])
            return y;
    }
    return {};
}
