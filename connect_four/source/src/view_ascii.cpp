
#include "view_ascii.h"
#include "color.h"
#include "view_cell.h"

#include "rang.h"

#include <iostream>

using namespace connect4;
using namespace std;
using namespace rang;

View_ASCII::View_ASCII(const Board& board) : board(board), current_player("", color_e::red) {}

void View_ASCII::display(bool clear)
{
    if(clear)
        if(std::system("clear") == -1)
            return;

    //    const auto& g =
    print_grid(board.get_grid());

    cout << "-0--1--2--3--4--5--6-\n";

    print_history();

    if(current_player.get_color() == color_e::red)
        cout << style::bold << fg::red << bg::blue;
    else
        cout << style::bold << fg::yellow << bg::blue;

    for(const auto& msg : msgs)
        cout << msg << '\n';

    cout << style::reset << flush;
    msgs.clear();
}

void View_ASCII::message(const std::string& msg) { msgs.push_back(msg); }

void View_ASCII::print_history() const
{
    cout << "history:";
    for(auto h : history)
    {
        if(h)
            cout << (int) h.value();
        else
            cout << '-';
        cout << ",";
    }
    cout << '\n';
}

void View_ASCII::print_grid(const connect4::Board::grid_t& g) const
{
    for(int y = 0; y < Board::N_ROW; ++y)
    {
        for(int i = 0; i < 2; ++i)
        {
            for(int x = 0; x < Board::N_COLUMN; ++x)
            {
                cout << g[x][y] << g[x][y] << g[x][y];
            }
            cout << '\n';
        }
    }
}
}
