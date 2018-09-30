
#include "minmax.h"
#include "tictactoe.h"
#include "view_ascii.h"

#include <iostream>

using namespace tictactoe;
using namespace view;
using namespace std;

int main(int argc, char* argv[])
{
    cout << "Choose AI level:";
    auto level = 0;
    cin >> level;

    TicTacToe game;
    game.set_ai(player_e::p1);
    game.set_name(player_e::p1, "AI_1");

    View_ASCII view(game.get_board().get_grid());

    ai::Minmax minmax(game.get_player(player_e::p1), level);

    while(game.is_finished() == false)
    {
        // Display
        view.set_current_player(game.get_current_player());
        view.set_history(game.get_history());
        view.display();

        // Input
        Board::Point p{};
        if(game.get_current_player().is_ai())
            p = minmax.compute(game, ai::Minmax::algo::minmax_parallel, chrono::seconds(5));
        else
            cin >> p.x >> p.y;

        // Compute
        if(game.play(p) == false)
            view.message("Input is invalid");
    }
    view.message("Game is finished");
    view.set_history(game.get_history());
    view.display();
}
