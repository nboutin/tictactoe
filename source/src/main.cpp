
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
    view.display();

    while(game.is_finished() == false)
    {
        auto current_player = game.get_current_player();

        cout << current_player.get_name() << ":";
        int y = 0;
        cin >> y;

        auto token = std::make_unique<Token>(current_player.get_color());
        auto r     = game.play(y, move(token));

        view.display();
        if(r == false)
        {
            cout << "invalid" << endl;
        }
    }
    cout << "Game is finished" << endl;
}
