
#include <catch.hpp>

#include "game_p4.h"
#include "minmax.h"
#include "view_ascii.h"

using namespace p4;
using namespace ai;
using namespace view;

TEST_CASE("bug")
{
    SECTION("")
    {
        Game_P4 game;

//        const std::vector<int> moves{0, 3, 0, 2, 0, 0, 1, 3, 0, 3, 3, 2, 5, 4, 0, 4, 1};
        const std::vector<int> moves{0, 3, 0, 2, 0, 0, 1, 3, 0, 3, 3, 2, 5, 4};

        for(auto m : moves)
            game.play(m);

        View_ASCII v(game.get_board());
        v.display();

        Minmax minmax(game.get_player(1), 3);
    }
}
