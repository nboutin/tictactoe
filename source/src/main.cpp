
#include <iostream>

#include "game_p4.h"
#include "view_ascii.h"

using namespace p4;
using namespace view;
using namespace std;

// https://gist.github.com/application2000/73fd6f4bf1be6600a2cf9f56315a2d91

int main(int argc, char* argv[])
{
    Game_P4 game;
    View_ASCII view(game.get_board());

    view.message(game.get_current_player().get_name() + ":");
    view.display();

    while(game.is_finished() == false)
    {
        int y = 0;
        cin >> y;

        auto token = std::make_unique<Token>(game.get_current_player().get_color());
        auto r     = game.play(y, move(token));

        if(r == false)
            view.message("Input is invalid");

        view.message(game.get_current_player().get_name() + ":");
        view.display();
    }
    view.message("Game is finished");
    view.display();
}
