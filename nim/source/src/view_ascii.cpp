
#include "view_ascii.h"

#include <iomanip>
#include <iostream>

using namespace nim;
using namespace std;

View_ASCII::View_ASCII(const Board::grid_t& g) : grid(g), current_player("") {}

void View_ASCII::display(bool clear)
{
    if(clear && std::system("clear") == -1)
        return;

    for(auto i = 1; i < Board::TOKEN_COUNT + 1; ++i)
        cout << setw(3) << std::to_string(i);
    cout << '\n';

    print_grid(grid);
    print_history();

    for(const auto& msg : msgs)
        cout << msg << '\n';

    cout << flush;
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

void View_ASCII::print_grid(const Board::grid_t& g) const
{
    for(auto i = 0; i < g; ++i)
        cout << " | ";
    cout << '\n';
}
