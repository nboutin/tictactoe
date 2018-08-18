
#include "board.h"

using namespace p4;
using namespace std;

bool Board::play(uint8_t x, std::unique_ptr<p4::Token> token)
{
    if(x >= N_COLUMN)
        return false;

    auto y = find_free_row(x);

    if(!y)
        return false;

    board[x][y.value()].add_token(std::move(token));

    return true;
}

optional<uint8_t> Board::find_free_row(uint8_t x)
{
    for(int8_t y = N_ROW - 1; y >= 0; y--)
    {
        if(board[x][y].is_empty())
            return y;
    }
    return {};
}
