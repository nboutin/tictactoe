
#include <catch.hpp>
#include "../../source/inc/connect4.h"

#include "view_ascii.h"

using namespace connect4;
using namespace view;

// View_ASCII v(game.get_board());
// v.display();

TEST_CASE("current player", "[game_p4]")
{
    Connect4 game;
    Player p1("Player 1", color_e::red);
    Player p2("Player 2", color_e::yellow);

    auto current_player = game.get_current_player();
    REQUIRE(current_player == p1);

    REQUIRE(game.play(0));
    REQUIRE(game.get_current_player() == p2);

    REQUIRE(game.play(0));
    REQUIRE(game.get_current_player() == p1);
}

TEST_CASE("no more free cell", "[game_p4]")
{
    Connect4 game;

    std::vector<int> moves{0, 1, 0, 1, 0, 1, 2, 3, 2, 3, 2, 3, 4, 5, 4, 5, 4, 5, 1, 2, 1,
                           2, 1, 2, 3, 4, 3, 4, 3, 4, 6, 0, 6, 0, 6, 0, 5, 6, 5, 6, 5};
    for(auto m : moves)
        game.play(m);

    REQUIRE_FALSE(game.is_finished());

    game.play(6);

    REQUIRE(game.is_finished());
}

TEST_CASE("is winner vertically", "[game_p4]")
{
    Connect4 game;

    SECTION("red y=0")
    {
        std::vector<int> moves{0, 1, 0, 1, 0, 1, 0};
        for(auto m : moves)
            game.play(m);

        REQUIRE(game.is_finished());
    }

    SECTION("yellow y=1")
    {
        std::vector<int> moves{0, 1, 0, 1, 0, 1, 2};
        for(auto m : moves)
            game.play(m);

        REQUIRE_FALSE(game.is_finished());

        game.play(1);

        REQUIRE(game.is_finished());
    }

    SECTION("red y=2 x=3")
    {
        std::vector<int> moves{2, 2, 2, 1, 2, 1, 2, 1, 2};
        for(auto m : moves)
            game.play(m);

        REQUIRE(game.is_finished());
    }
}

TEST_CASE("is winner horizontally", "[game_p4]")
{
    Connect4 game;

    SECTION("red x=0")
    {
        std::vector<int> moves{0, 0, 1, 1, 2, 2, 3};
        for(auto m : moves)
            game.play(m);

        REQUIRE(game.is_finished());
    }

    SECTION("red middle")
    {
        for(int x = 2; x < 5; ++x)
            for(int y = 0; y < 4; ++y)
                game.play(x);

        std::vector<int> moves{0, 5, 5, 5, 0, 5};
        for(auto m : moves)
            game.play(m);

        REQUIRE(game.is_finished());
    }
}

TEST_CASE("is winner diagonal", "[game_p4]")
{
    Connect4 game;

    SECTION("diag up")
    {
        std::vector<int> moves{0, 1, 1, 2, 2, 3, 2, 3, 3, 0, 3};

        for(auto m : moves)
        {
            game.play(m);
        }
        REQUIRE(game.is_finished());
    }

    SECTION("diag up 2")
    {
        std::vector<int> moves{0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 2, 3, 3, 3, 3, 6, 3};

        for(auto m : moves)
        {
            game.play(m);
        }

        REQUIRE(game.is_finished());
    }

    SECTION("diag down")
    {
        std::vector<int> moves{1, 1, 1, 2, 1, 2, 2, 3, 3, 0, 4};

        for(auto m : moves)
        {
            game.play(m);
        }

        REQUIRE(game.is_finished());
    }

    SECTION("diag down 2")
    {
        std::vector<int> moves{6, 6, 6, 5, 5, 5, 5, 4, 4, 4, 4, 3, 4, 3, 3, 3, 3, 0, 3};

        for(auto m : moves)
        {
            game.play(m);
        }

        REQUIRE(game.is_finished());
    }
}

TEST_CASE("is finished", "[game_p4]")
{
    Connect4 game;

    for(int x = 0; x < 3; ++x)
        for(int y = 0; y < 2; ++y)
        {
            game.play(x);
        }

    REQUIRE_FALSE(game.is_finished());

    game.play(3);

    REQUIRE(game.is_finished());

    REQUIRE_FALSE(game.play(3));
}
