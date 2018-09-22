
#include "view_ascii.h"
#include "token.h"

#include <iostream>

using namespace view;
using namespace tictactoe;
using namespace std;

View_ASCII::View_ASCII(const Board::grid_t& g) : grid(g), current_player("", token_e::cross) {}

void View_ASCII::display(bool clear)
{
    if(clear)
        std::system("clear");

    print_grid(grid);
    print_history();
    print_messages();
}

void View_ASCII::print_messages()
{
    // Current player
    cout << current_player.get_name() << ":\n";
    for(const auto& msg : msgs)
        cout << msg << '\n';

    msgs.clear();
}

void View_ASCII::print_history() const
{
    cout << "History:";
    for(auto m : moves)
    {
        if(m)
            cout << '[' << (int) m.value().x << ',' << (int) m.value().y << ']';
        else
            cout << '-';
        cout << ",";
    }
    cout << '\n';
}

void View_ASCII::print_grid(const tictactoe::Board::grid_t& g) const
{
    cout << "  012\n";
    for(int y = 0; y < Board::N_ROW; ++y)
    {
        cout << std::to_string(y) << " ";
        for(int x = 0; x < Board::N_COLUMN; ++x)
        {
            cout << g[x][y];
        }
        cout << '\n';
    }
}
