
#include <iostream>

#include "game_p4.h"
#include "minmax.h"
#include "view_ascii.h"

using namespace p4;
using namespace view;
using namespace std;
using namespace ai;

// https://gist.github.com/application2000/73fd6f4bf1be6600a2cf9f56315a2d91

int main(int argc, char* argv[])
{
    Game_P4 game;
    View_ASCII view(game.get_board());

    game.set_ai(1);
    game.set_name(1, "AI_1");
    Minmax minmax(game.get_player(1), 5);

    view.set_current_player(game.get_current_player());
    view.message(game.get_current_player().get_name() + ":");
    view.display();

    while(game.is_finished() == false)
    {
        int y = 0;
        if(game.get_current_player().is_ai())
            y = minmax.compute(game);
        else
            cin >> y;

        auto r = game.play(y);

        if(r == false)
            view.message("Input is invalid");

        view.set_current_player(game.get_current_player());
        view.message(game.get_current_player().get_name() + ":");
        view.display();
    }
    view.message("Game is finished");
    view.display();
}
