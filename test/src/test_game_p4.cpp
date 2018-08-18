
#include <catch.hpp>

#include "game_p4.h"

using namespace p4;

TEST_CASE("current player", "[game_p4]")
{
    Game_P4 game;
    Player p1("p1", Token::color_e::red);
    Player p2("p2", Token::color_e::yellow);

    auto current_player = game.get_current_player();
    REQUIRE(current_player == p1);

    auto token = std::make_unique<Token>(current_player.get_color());
    REQUIRE(game.play(0, move(token)));
    REQUIRE(game.get_current_player() == p2);

    token = std::make_unique<Token>(current_player.get_color());
    REQUIRE(game.play(0, move(token)));
    REQUIRE(game.get_current_player() == p1);
}

TEST_CASE("no more free cell", "[game_p4]")
{
    Game_P4 game;

    for(int y = 0; y < 3; ++y)
        for(int x = 0; x < Board::N_COLUMN - 1; ++x)
        {
            auto token = std::make_unique<Token>(game.get_current_player().get_color());
            game.play(x, move(token));
        }

    for(int y = 0; y < 3; ++y)
    {
        auto token = std::make_unique<Token>(game.get_current_player().get_color());
        game.play(6, move(token));
    }

    for(int y = 0; y < 2; ++y)
        for(int x = 0; x < Board::N_COLUMN; ++x)
        {
            auto token = std::make_unique<Token>(game.get_current_player().get_color());
            game.play(x, move(token));
        }

    for(int x = 1; x < Board::N_COLUMN; ++x)
    {
        auto token = std::make_unique<Token>(game.get_current_player().get_color());
        game.play(x, move(token));
    }

    REQUIRE_FALSE(game.is_finished());

    auto token = std::make_unique<Token>(game.get_current_player().get_color());
    game.play(0, move(token));

    REQUIRE(game.is_finished());
}

#include "view_ascii.h"
TEST_CASE("is winner vertically", "[game_p4]")
{
    Game_P4 game;

    SECTION("red y=0")
    {
        auto token = std::make_unique<Token>(game.get_current_player().get_color());
        game.play(0, move(token));

        token = std::make_unique<Token>(game.get_current_player().get_color());
        game.play(1, move(token));

        token = std::make_unique<Token>(game.get_current_player().get_color());
        game.play(0, move(token));

        token = std::make_unique<Token>(game.get_current_player().get_color());
        game.play(1, move(token));

        token = std::make_unique<Token>(game.get_current_player().get_color());
        game.play(0, move(token));

        token = std::make_unique<Token>(game.get_current_player().get_color());
        game.play(1, move(token));

        token = std::make_unique<Token>(game.get_current_player().get_color());
        game.play(0, move(token));

        REQUIRE(game.is_finished());
    }

    SECTION("yellow y=1")
    {
        auto token = std::make_unique<Token>(game.get_current_player().get_color());
        game.play(0, move(token));

        token = std::make_unique<Token>(game.get_current_player().get_color());
        game.play(1, move(token));

        token = std::make_unique<Token>(game.get_current_player().get_color());
        game.play(0, move(token));

        token = std::make_unique<Token>(game.get_current_player().get_color());
        game.play(1, move(token));

        token = std::make_unique<Token>(game.get_current_player().get_color());
        game.play(0, move(token));

        token = std::make_unique<Token>(game.get_current_player().get_color());
        game.play(1, move(token));

        token = std::make_unique<Token>(game.get_current_player().get_color());
        game.play(2, move(token));

        REQUIRE_FALSE(game.is_finished());

        token = std::make_unique<Token>(game.get_current_player().get_color());
        game.play(1, move(token));

        REQUIRE(game.is_finished());
    }

    SECTION("red y=2 x=3")
    {
        auto token = std::make_unique<Token>(game.get_current_player().get_color());
        game.play(2, move(token));

        token = std::make_unique<Token>(game.get_current_player().get_color());
        game.play(2, move(token));

        token = std::make_unique<Token>(game.get_current_player().get_color());
        game.play(2, move(token));

        token = std::make_unique<Token>(game.get_current_player().get_color());
        game.play(1, move(token));

        token = std::make_unique<Token>(game.get_current_player().get_color());
        game.play(2, move(token));

        token = std::make_unique<Token>(game.get_current_player().get_color());
        game.play(1, move(token));

        token = std::make_unique<Token>(game.get_current_player().get_color());
        game.play(2, move(token));

        token = std::make_unique<Token>(game.get_current_player().get_color());
        game.play(1, move(token));

        token = std::make_unique<Token>(game.get_current_player().get_color());
        game.play(2, move(token));

        view::View_ASCII v(game.get_board());
        v.display();

        REQUIRE(game.is_finished());
    }
}
