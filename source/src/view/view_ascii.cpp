
#include "view_ascii.h"
#include "rang.h"

#include <iostream>

using namespace view;
using namespace p4;
using namespace std;
using namespace rang;

View_ASCII::View_ASCII(const p4::Board& board) : board(board), current_player("", color_e::red) {}

void View_ASCII::display(bool clear)
{
    if(clear)
        std::system("clear");

    //    const auto& g =
    print_grid(board.get_grid());

    cout << "0123456\n";

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

void View_ASCII::print_grid(const p4::Board::grid_t& g) const
{
    for(int y = 0; y < Board::N_ROW; ++y)
    {
        for(int x = 0; x < Board::N_COLUMN; ++x)
        {
            cout << g[x][y];
        }
        cout << '\n';
    }
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

namespace p4
{
inline std::ostream& operator<<(std::ostream& os, const Cell& cell)
{
    if(cell.is_empty())
    {
        return os << style::underline << bg::blue << " " << style::reset;
    }
    else
    {
        if(cell.get_color() == color_e::red)
        {
            return os << style::bold << fg::red << bg::blue << "0" << style::reset;
        }
        else
        {
            return os << style::bold << fg::yellow << bg::blue << "0" << style::reset;
        }
    }

    return os;
}
}
