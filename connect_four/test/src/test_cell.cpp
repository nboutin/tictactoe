
#include <catch.hpp>

#include "cell.h"

using namespace connect4;

TEST_CASE("operator==", "[cell]")
{
    REQUIRE(Cell() == Cell());
    REQUIRE(Cell(color_e::red) == Cell(color_e::red));
    REQUIRE(Cell(color_e::yellow) == Cell(color_e::yellow));

    REQUIRE_FALSE(Cell(color_e::yellow) == Cell(color_e::red));
    REQUIRE_FALSE(Cell(color_e::yellow) == Cell());
}
