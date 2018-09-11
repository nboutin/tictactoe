
#include "board.h"

using namespace tictactoe;
using namespace std;

bool Board::play(const Point p, const token_e token)
{
    if(p.x >= N_COLUMN || p.y >= N_ROW)
        return false;

    // Check free cell
    if(grid[p.x][p.y])
        return false;

    // add token to grid
    grid[p.x][p.y] = token;

    return true;
}

void Board::undo(const Point p)
{
    if(p.x >= N_COLUMN || p.y >= N_ROW)
        return;
    grid[p.x][p.y] = cell_t{};
}
