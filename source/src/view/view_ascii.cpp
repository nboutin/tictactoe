
#include "view_ascii.h"

#include <iostream>

using namespace view;
using namespace p4;
using namespace std;

View_ASCII::View_ASCII(const Board& board) : board(board) {}

void View_ASCII::display()
{
    const auto& b = board.get_board();

    for(int y = 0; y < Board::N_ROW; ++y)
    {
        for(int x = 0; x < Board::N_COLUMN; ++x)
        {
            cout << cell_to_char(b[x][y]);
        }
        cout << '\n';
    }
    cout << endl;
}

char View_ASCII::cell_to_char(const Cell& cell)
{
    if(cell.is_empty())
        return '-';
    else
    {
        auto piece = cell.get_token();

        if(piece.get_color() == Token::color_e::red)
            return 'r';
        else
            return 'y';
    }
    return 'x';
}
