
#include "evaluate.h"
#include "game_p4.h"
#include "minmax.h"
#include "view_ascii.h"

#include <catch.hpp>

using namespace p4;
using namespace ai;
using namespace view;

TEST_CASE("bug3")
{
    // 0,3,0,3,0,0,0,3,3,2,0,3,1,4,5,2,2,1,1,2,4,4,1,1,1,2,2,3,5,5,5,4,4,6,4,6
    // last player yellow and winner
    const std::vector<int> moves{
        0, 3, 0, 3, 0, 0, 0, 3, 3, 2, 0, 3, 1, 4, 5, 2,
        2, 1, 1, 2, 4, 4, 1, 1, 1, 2, 2, 3, 5, 5, 5, 4,
    };

    Game_P4 game;

    for(auto m : moves)
        game.play(m);

    View_ASCII v(game.get_board());
    v.display(false);

    SECTION("depth0")
    {
        Minmax minmax(game.get_player(1), 0);
        REQUIRE(minmax.compute(game) == 4);
    }

    SECTION("depth1")
    {
        Minmax minmax(game.get_player(1), 1);
        REQUIRE(minmax.compute(game) == 4);
    }
}
TEST_CASE("bug2")
{
    Game_P4 game;
    const std::vector<int> moves{0, 3, 0, 3, 0, 0, 0, 3, 3, 4, 2, 4, 2, 2, 2, 5};

    for(auto m : moves)
        game.play(m);

    View_ASCII v(game.get_board());
    v.display(false);

    SECTION("depth1")
    {
        Minmax minmax(game.get_player(1), 1);
        REQUIRE(minmax.compute(game) == 6);
    }

    SECTION("depth2")
    {
        Minmax minmax(game.get_player(1), 2);
        REQUIRE(minmax.compute(game) == 6);
    }

    SECTION("depth3")
    {
        Minmax minmax(game.get_player(1), 3);
        REQUIRE(minmax.compute(game) == 6);
    }

    SECTION("depth4")
    {
        Minmax minmax(game.get_player(1), 4);
        REQUIRE(minmax.compute(game) == 6);
    }

    SECTION("depth5")
    {
        Minmax minmax(game.get_player(1), 5);
        REQUIRE(minmax.compute(game) == 6);
    }
}

TEST_CASE("bug1")
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
