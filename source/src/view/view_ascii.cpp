
#include "view_ascii.h"

#include <iostream>

using namespace view;
using namespace p4;
using namespace std;

View_ASCII::View_ASCII(const Board& board) : board(board) {}

void View_ASCII::display()
{
    for(const auto& row : board.get_board())
    {
        for(const auto& cell : row)
        {
            cout << cell_to_char(cell);
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
