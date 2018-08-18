
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

#include "view_ascii.h"
using namespace view;
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

    View_ASCII view(game.get_board());
    view.display();
    REQUIRE(game.is_finished());
}
