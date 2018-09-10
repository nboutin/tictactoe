
#include "tictactoe.h"
//#include "minmax.h"
#include "view_ascii.h"

#include <iostream>

using namespace tictactoe;
using namespace view;
using namespace std;
// using namespace ai;

int main(int argc, char* argv[])
{
    //    cout << "Choose AI level:";
    //    auto level = 0;
    //    cin >> level;

    TicTacToe game;
    View_ASCII view(game.get_board().get_grid());

    //    game.set_ai(1);
    //    game.set_name(1, "AI_1");
    //    Minmax minmax(game.get_player(1), level);

    view.set_current_player(game.get_current_player());
    view.message(game.get_current_player().get_name() + ":");
    view.display();

    while(game.is_finished() == false)
    {
        Board::Point p{};
        //        if(game.get_current_player().is_ai())
        //            y = minmax.compute(game, Minmax::algo::minmax_parallel, chrono::seconds(5));
        //        else
        cin >> p.x >> p.y;

        auto r = game.play(p);

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
