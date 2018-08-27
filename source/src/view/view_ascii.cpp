
#include "view_ascii.h"

#include <iostream>

using namespace view;
using namespace p4;
using namespace std;

View_ASCII::View_ASCII(const Board& board) : board(board), current_player("", color_e::red) {}

void View_ASCII::display(bool clear)
{
    if(clear)
        std::system("clear");

    const auto& b = board.get_grid();

    for(int y = 0; y < Board::N_ROW; ++y)
    {
        for(int x = 0; x < Board::N_COLUMN; ++x)
        {
            cout << cell_to_print(b[x][y]);
        }
        cout << '\n';
    }
    cout << "0123456\n";

    // print history
    cout << "history:";
    for(auto h : history)
    {
        if(h)
            cout << (int)h.value();
        else
            cout << '-';
        cout << ",";
    }
    cout << '\n';

    if(current_player.get_color() == color_e::red)
        cout << "\033[1;31;44m";
    else
        cout << "\033[1;33;44m";

    for(const auto& msg : msgs)
        cout << msg << '\n';

    cout << "\033[0m" << flush;
    msgs.clear();
}

void View_ASCII::message(const std::string& msg) { msgs.push_back(msg); }

string View_ASCII::cell_to_print(const Cell& cell) const
{
    if(cell.is_empty())
    {
        return "\033[4;44m \033[0m";
    }
    else
    {
        if(cell.get_color() == color_e::red)
        {
            return "\033[1;31;44mO\033[0m";
        }
        else
        {
            return "\033[1;33;44mO\033[0m";
        }
    }
    return "E";
}
