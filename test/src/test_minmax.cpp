
#include <catch.hpp>
#include <vector>

#include "game_p4.h"

/// \warning Nasty trick to access private methods when testing
#define private public

#include "minmax.h"

using namespace p4;
using namespace ai;
using namespace std;

TEST_CASE("evaluate horizontal", "[minmax]")
{
    Game_P4 game;
    game.set_ai(1);

    SECTION("no token")
    {
        Minmax minmax(game.get_player(1), 0);
        REQUIRE(minmax.evaluate(game) == 0);
    }

    SECTION("x0 r3")
    {
        //r
        //r
        //ry y
        Minmax minmax(game.get_player(1), 0);

        for(auto m : vector<int>{0, 1, 0, 3, 0})
            game.play(m);

        REQUIRE(minmax.evaluate(game) == ALIGN3);
    }

    SECTION("x2 r3")
    {
        Minmax minmax(game.get_player(1), 0);

        for(auto m : vector<int>{2, 1, 2, 3, 2})
            game.play(m);

        REQUIRE(minmax.evaluate(game) == ALIGN3);
    }

    SECTION("x2y4 r3")
    {
        Minmax minmax(game.get_player(1), 0);

        for(auto m : vector<int>{0, 2, 2, 4, 2, 6, 2})
            game.play(m);

        REQUIRE(minmax.evaluate(game) == ALIGN3);
    }

    SECTION("x2y4 r3")
    {
        Minmax minmax(game.get_player(1), 0);

        for(auto m : vector<int>{0, 1, 2, 1, 4, 1})
            game.play(m);

        REQUIRE(minmax.evaluate(game) == -ALIGN3);
    }
}

// TEST_CASE("debug")
//{
//    Game_P4 game;
//    game.set_ai(1);
//    Minmax minmax(game.get_player(1), 0);
//
//    for(auto m : vector<int>{0, 1, 0, 3, 0})
//        game.play(m);
//
//    REQUIRE(minmax.evaluate(game) == 3);
//}
