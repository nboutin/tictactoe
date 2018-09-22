
#include "board.h"

#include <catch.hpp>

using namespace connect4;

TEST_CASE("play two token", "[board]")
{
    Board b;

    REQUIRE(b.play(0, color_e::red));

    REQUIRE(b.play(0, color_e::yellow));

    const auto& g = b.get_grid();

    REQUIRE(g[0][5] == color_e::red);
    REQUIRE(g[0][4] == color_e::yellow);
    REQUIRE(!g[0][3]);
}

TEST_CASE("boundaries", "[board]")
{
    Board b;

    REQUIRE_FALSE(b.play(-1, color_e::red));
    REQUIRE_FALSE(b.play(Board::N_COLUMN, color_e::yellow));

    bool empty = true;
    for(const auto& g : b.get_grid())
        for(const auto& c : g)
            empty &= !c;
    REQUIRE(empty);
}

TEST_CASE("full column", "[board]")
{
    Board b;

    for(int i = 0; i < Board::N_ROW; ++i)
    {
        REQUIRE(b.play(0, color_e::red));
    }
    const auto& g = b.get_grid();
    REQUIRE(g[0][0] == color_e::red);

    REQUIRE_FALSE(b.play(0, color_e::red));
}
