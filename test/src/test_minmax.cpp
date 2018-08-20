
#include <catch.hpp>
#include <vector>

#include "game_p4.h"
#include "view_ascii.h"

/// \warning Nasty trick to access private methods when testing
/// DO NOT put header file below
#define private public
#include "minmax.h"

using namespace p4;
using namespace ai;
using namespace std;

TEST_CASE("evaluate vertical", "[minmax]")
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
        // r
        // r
        // ry y
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

    SECTION("r4")
    {
        Minmax minmax(game.get_player(1), 0);

        for(auto m : vector<int>{6, 0, 6, 0, 6, 0, 6})
            game.play(m);

        REQUIRE(minmax.evaluate(game) == MAX);
    }

    SECTION("y4")
    {
        Minmax minmax(game.get_player(1), 0);

        for(auto m : vector<int>{1, 0, 1, 0, 3, 1, 0, 1, 0, 1, 3, 1})
            game.play(m);

        REQUIRE(minmax.evaluate(game) == MIN);
    }
}

TEST_CASE("evaluate horizontal", "[minmax][eval_h]")
{
    Game_P4 game;
    game.set_ai(1);

    SECTION("r4 x0y5")
    {
        Minmax minmax(game.get_player(1), 0);

        for(auto m : vector<int>{0, 0, 1, 1, 2, 2, 3})
            game.play(m);

        REQUIRE(minmax.evaluate(game) == MAX);
    }

    SECTION("r4 x3y5")
    {
        Minmax minmax(game.get_player(1), 0);

        for(auto m : vector<int>{3, 3, 4, 4, 5, 5, 6})
            game.play(m);

        REQUIRE(minmax.evaluate(game) == MAX);
    }

    SECTION("y4 x2y0")
    {
        Minmax minmax(game.get_player(1), 0);

        for(auto m : vector<int>{2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 4,
                                 4, 4, 4, 4, 4, 6, 5, 5, 5, 5, 5, 0, 5})
            game.play(m);

        REQUIRE(minmax.evaluate(game) == MIN);
    }
}

//TEST_CASE("debug", "")
//{
//    Game_P4 game;
//    game.set_ai(1);
//    Minmax minmax(game.get_player(1), 0);
//
//    for(auto m :
//        vector<int>{2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 6, 5, 5, 5, 5, 5, 0, 5})
//        game.play(m);
//
//    view::View_ASCII v(game.get_board());
//    v.display(false);
//
//    REQUIRE(minmax.evaluate(game) == MIN);
//}
