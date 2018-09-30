
#include <catch.hpp>

#define private public
#include "tictactoe.h"

using namespace tictactoe;

TEST_CASE("winner diagonal", "[tictactoe]")
{
    TicTacToe game;

    {
        Board b;
        b.play({0, 0}, token_e::cross);
        b.play({1, 1}, token_e::cross);
        b.play({2, 2}, token_e::cross);

        auto r = game.is_winner_diagonal(b.get_grid());
        REQUIRE(r);
    }

    {
        Board b;
        b.play({0, 2}, token_e::cross);
        b.play({1, 1}, token_e::cross);
        b.play({2, 0}, token_e::cross);

        auto r = game.is_winner_diagonal(b.get_grid());
        REQUIRE(r);
    }
}

TEST_CASE("winner horizontal", "[tictactoe]")
{
    TicTacToe game;

    {
        Board b;
        b.play({0, 0}, token_e::cross);
        b.play({1, 0}, token_e::cross);
        b.play({2, 0}, token_e::cross);

        auto r = game.is_winner_horizontal(b.get_grid());
        REQUIRE(r);
    }

    {
        Board b;
        b.play({0, 1}, token_e::cross);
        b.play({1, 1}, token_e::cross);
        b.play({2, 1}, token_e::cross);

        auto r = game.is_winner_horizontal(b.get_grid());
        REQUIRE(r);
    }

    {
        Board b;
        b.play({0, 2}, token_e::cross);
        b.play({1, 2}, token_e::cross);
        b.play({2, 2}, token_e::cross);

        auto r = game.is_winner_horizontal(b.get_grid());
        REQUIRE(r);
    }
}

TEST_CASE("winner vertical", "[tictactoe]")
{
    TicTacToe game;

    {
        Board b;
        b.play({0, 0}, token_e::cross);
        b.play({0, 1}, token_e::cross);
        b.play({0, 2}, token_e::cross);

        auto r = game.is_winner_vertical(b.get_grid());
        REQUIRE(r);
    }

    {
        Board b;
        b.play({1, 0}, token_e::cross);
        b.play({1, 1}, token_e::cross);
        b.play({1, 2}, token_e::cross);

        auto r = game.is_winner_vertical(b.get_grid());
        REQUIRE(r);
    }

    {
        Board b;
        b.play({2, 0}, token_e::cross);
        b.play({2, 1}, token_e::cross);
        b.play({2, 2}, token_e::cross);

        auto r = game.is_winner_vertical(b.get_grid());
        REQUIRE(r);
    }
}
