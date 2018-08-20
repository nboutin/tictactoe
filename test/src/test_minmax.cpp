
#include <catch.hpp>
#include <vector>

#include "game_p4.h"
#include "minmax.h"

using namespace p4;
using namespace ai;
using namespace std;

TEST_CASE("evaluate", "[minmax]")
{
    Game_P4 game;
    game.set_ai(1);

    SECTION("no token p=0")
    {
        Minmax minmax(game.get_player(1), 0);
        REQUIRE(minmax.compute(game) == 0);
    }

    SECTION("vertical 3 token, x0")
    {
        Minmax minmax(game.get_player(1), 0);

        for(auto m : vector<int>{0, 1, 0, 3})
            game.play(m);

        REQUIRE(minmax.compute(game) == 0);
    }

    SECTION("vertical 3 token, x2")
    {
        Minmax minmax(game.get_player(1), 0);

        for(auto m : vector<int>{2, 1, 2, 3})
            game.play(m);

        REQUIRE(minmax.compute(game) == 2);
    }
}
