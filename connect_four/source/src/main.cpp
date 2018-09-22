
#include <iostream>

#include "../inc/connect4.h"
#include "minmax.h"
#include "view_ascii.h"

using namespace connect4;
using namespace view;
using namespace std;
using namespace ai;

int main(int argc, char* argv[])
{
    cout << "Choose AI level:";
    auto level = 0;
    cin >> level;

    Connect4 game;
    View_ASCII view(game.get_board());

    game.set_ai(1);
    game.set_name(1, "AI_1");
    Minmax minmax(game.get_player(1), level);

    view.set_current_player(game.get_current_player());
    view.message(game.get_current_player().get_name() + ":");
    view.display();

    while(game.is_finished() == false)
    {
        int y = 0;
        if(game.get_current_player().is_ai())
            y = minmax.compute(game, Minmax::algo::minmax_parallel, chrono::seconds(5));
        else
            cin >> y;

        auto r = game.play(y);

        if(r == false)
            view.message("Input is invalid");

        view.set_current_player(game.get_current_player());
        view.message(game.get_current_player().get_name() + ":");
        view.set_history(game.get_history());
        view.display();
    }
    view.message("Game is finished");
    view.display();
}
