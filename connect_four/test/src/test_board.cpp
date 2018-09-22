
#include <catch.hpp>

#include "board.h"

using namespace connect4;

TEST_CASE("play two token", "[board]")
{
    Board b;

    REQUIRE(b.play(0, color_e::red));

    REQUIRE(b.play(0, color_e::yellow));

    const auto& bn = b.get_grid();

    REQUIRE(bn[0][5].get_color() == color_e::red);
    REQUIRE(bn[0][4].get_color() == color_e::yellow);
    REQUIRE(bn[0][3].is_empty());
}

TEST_CASE("boundaries", "[board]")
{
    Board b;

    REQUIRE_FALSE(b.play(-1, color_e::red));
    REQUIRE_FALSE(b.play(Board::N_COLUMN, color_e::yellow));

    bool empty = true;
    for(const auto& c : b.get_grid())
        for(const auto& r : c)
            empty &= r.is_empty();
    REQUIRE(empty);
}

TEST_CASE("full column", "[board]")
{
    Board b;

    for(int i = 0; i < Board::N_ROW; ++i)
    {
        REQUIRE(b.play(0, color_e::red));
    }
    const auto& bn = b.get_grid();
    REQUIRE(bn[0][0].get_color() == color_e::red);

    REQUIRE_FALSE(b.play(0, color_e::red));
}
