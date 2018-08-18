
#include "view_ascii.h"

#include <iostream>

using namespace view;
using namespace p4;
using namespace std;

View_ASCII::View_ASCII(const Board& board) : board(board) {}

void View_ASCII::display()
{
    std::system("clear");

    const auto& b = board.get_board();

    for(int y = 0; y < Board::N_ROW; ++y)
    {
        for(int x = 0; x < Board::N_COLUMN; ++x)
        {
            cout << cell_to_print(b[x][y]);
        }
        cout << '\n';
    }
    cout << endl;
}

string View_ASCII::cell_to_print(const Cell& cell)
{
    if(cell.is_empty())
        return "\033[4;44m \033[0m";
    else
    {
        auto piece = cell.get_token();

        if(piece.get_color() == Token::color_e::red)
            return "\033[1;31;44mO\033[0m";
        else
        	return "\033[1;33;44mO\033[0m";
    }
    return "E";
}
