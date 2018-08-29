
#include "evaluate.h"
#include "game_p4.h"
#include "minmax.h"
#include "view_ascii.h"

#include <catch.hpp>

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

        // depth 0
        //        constexpr std::array<int, 7> compute{0, 0, 0, 0, 0, 0, 0};

        // depth 1
        //        constexpr std::array<int, 7> compute{0, LOOSE_POINT, 0, 0, 0, 0, 0};

        // depth 2
        //        constexpr std::array<int, 7> compute{0, LOOSE_POINT, 0, 0, 0, 0, 0};

        // depth 3
        //        constexpr std::array<int, 7> compute{
        //            LOOSE_POINT, LOOSE_POINT, LOOSE_POINT, LOOSE_POINT, 0, LOOSE_POINT,
        //            LOOSE_POINT};

        for(auto m : moves)
            game.play(m);

        View_ASCII v(game.get_board());
        v.display();

        const int depth = 2;

        Minmax minmax(game.get_player(1), depth);

        minmax.compute(game);
    }
}
