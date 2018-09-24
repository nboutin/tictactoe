
#include "nim.h"
//#include "minmax.h"
#include "view_ascii.h"

#include <iostream>

using namespace nim;
using namespace std;
// using namespace ai;

int main(int argc, char* argv[])
{
    //    cout << "Choose AI level:";
    //    auto level = 0;
    //    cin >> level;

    Nim game;
    //    game.set_ai(player_e::p1);
    //    game.set_name(player_e::p1, "AI_1");

    View_ASCII view(game.get_board().get_tokens());

    //    Minmax minmax(game.get_player(player_e::p1), level);

    while(game.is_finished() == false)
    {
        // Display
        view.set_current_player(game.get_current_player());
        view.message(game.get_current_player().get_name() + ":");
        view.set_history(game.get_history());
        view.display();

        // Input
        Board::move_t m = 0;
        //        if(game.get_current_player().is_ai())
        //            y = minmax.compute(game, Minmax::algo::minmax_parallel, chrono::seconds(5));
        //        else
        cin >> m;

        // Compute
        if(game.play(m) == false)
            view.message("Input is invalid");
    }
    view.message("Game is finished");
    view.set_history(game.get_history());
    view.display();
}
