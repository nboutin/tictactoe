
#include "evaluate.h"
#include "minmax.h"
#include "view_ascii.h"

#include <catch.hpp>
#include "../../source/inc/connect4.h"

using namespace connect4;
using namespace ai;
using namespace view;

TEST_CASE("bug5", "[!hide]")
{
    // last player yellow
    // 0,3,0,3,0,0,0,4,2,2,0,4,1,1
    Connect4 game;
    for(auto m : {0, 3, 0, 3, 0, 0, 0, 4, 2, 2, 0})
        game.play(m);

    View_ASCII v(game.get_board());
    v.display(false);

    const std::vector<int> expected{1, 1, 1, 1, 1, 1, 1, 1};

    for(size_t d = 0; d < expected.size(); ++d)
    {
        Minmax minmax(game.get_player(1), d);
        REQUIRE(minmax.compute(game, Minmax::algo::minmax) == expected[d]);
    }
}

TEST_CASE("bug4", "[!hide")
{
    // last player red
    // 0,3,0,3,0,0,0,2,1,2,5,5,0,2,1
}

TEST_CASE("bug3", "[!hide]")
{
    // 0,3,0,3,0,0,0,3,3,2,0,3,1,4,5,2,2,1,1,2,4,4,1,1,1,2,2,3,5,5,5,4,4,6,4,6
    // last player yellow and winner
    const std::vector<int> moves{
        0, 3, 0, 3, 0, 0, 0, 3, 3, 2, 0, 3, 1, 4, 5, 2,
        2, 1, 1, 2, 4, 4, 1, 1, 1, 2, 2, 3, 5, 5, 5, 4,
    };

    Connect4 game;

    for(auto m : moves)
        game.play(m);

    View_ASCII v(game.get_board());
    v.display(false);

    SECTION("depth0")
    {
        Minmax minmax(game.get_player(1), 0);
        REQUIRE(minmax.compute(game, Minmax::algo::minmax) == 4);
    }

    SECTION("depth1")
    {
        Minmax minmax(game.get_player(1), 1);
        REQUIRE(minmax.compute(game, Minmax::algo::minmax) == 4);
    }
}
TEST_CASE("bug2", "[!hide]")
{
    Connect4 game;
    const std::vector<int> moves{0, 3, 0, 3, 0, 0, 0, 3, 3, 4, 2, 4, 2, 2, 2, 5};

    for(auto m : moves)
        game.play(m);

    View_ASCII v(game.get_board());
    v.display(false);

    SECTION("depth1")
    {
        Minmax minmax(game.get_player(1), 1);
        REQUIRE(minmax.compute(game, Minmax::algo::minmax) == 6);
    }

    SECTION("depth2")
    {
        Minmax minmax(game.get_player(1), 2);
        REQUIRE(minmax.compute(game, Minmax::algo::minmax) == 6);
    }

    SECTION("depth3")
    {
        Minmax minmax(game.get_player(1), 3);
        REQUIRE(minmax.compute(game, Minmax::algo::minmax) == 6);
    }

    SECTION("depth4")
    {
        Minmax minmax(game.get_player(1), 4);
        REQUIRE(minmax.compute(game, Minmax::algo::minmax) == 6);
    }

    SECTION("depth5")
    {
        Minmax minmax(game.get_player(1), 5);
        REQUIRE(minmax.compute(game, Minmax::algo::minmax) == 6);
    }
}

TEST_CASE("bug1", "[!hide]")
{
    SECTION("")
    {
        Connect4 game;

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

        minmax.compute(game, Minmax::algo::minmax);
    }
}
