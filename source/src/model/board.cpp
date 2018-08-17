
#include "board.h"

using namespace p4;
using namespace std;

bool Board::play(uint8_t column, std::unique_ptr<p4::Token> token)
{
    if(column >= N_COLUMN)
        return false;

    auto row = find_free_row(column);

    if(!row)
    	return false;

    board[row.value()][column].add_token(std::move(token));

    return true;
}

optional<uint8_t> Board::find_free_row(uint8_t column)
{
    for(int8_t r = N_ROW - 1; r >= 0; r--)
    {
        if(board[r][column].is_empty())
            return r;
    }
    return {};
}
