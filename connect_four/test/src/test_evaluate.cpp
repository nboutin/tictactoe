
#include <catch.hpp>
#include <vector>

#include "evaluate.h"
#include "view_ascii.h"

using namespace p4;
using namespace ai;
using namespace std;

TEST_CASE("eval_h", "[evaluate]")
{
    SECTION("first row")
    {
        constexpr array<color_e, 2> c{color_e::red, color_e::yellow};
        constexpr array<int16_t, 2> r{WIN_POINT, LOOSE_POINT};
        for(int i = 0; i < 2; i++)
        {
            Board::grid_t grid;
            grid[0][5] = c[i];
            grid[1][5] = c[i];
            grid[2][5] = c[i];
            grid[3][5] = c[i];

            CAPTURE(i);
            REQUIRE(evaluate(grid, color_e::red) == r[i]);
        }
    }

    SECTION("first row at the top")
    {
        constexpr array<color_e, 2> c{color_e::red, color_e::yellow};
        constexpr array<int16_t, 2> r{WIN_POINT, LOOSE_POINT};
        for(int i = 0; i < 2; i++)
        {
            Board::grid_t grid;
            grid[0][0] = c[i];
            grid[1][0] = c[i];
            grid[2][0] = c[i];
            grid[3][0] = c[i];

            CAPTURE(i);
            REQUIRE(evaluate(grid, color_e::red) == r[i]);
        }
    }

    SECTION("left row")
    {
        constexpr array<color_e, 2> c{color_e::red, color_e::yellow};
        constexpr array<int16_t, 2> r{WIN_POINT, LOOSE_POINT};
        for(int i = 0; i < 2; i++)
        {
            Board::grid_t grid;
            grid[3][1] = c[i];
            grid[4][1] = c[i];
            grid[5][1] = c[i];
            grid[6][1] = c[i];

            CAPTURE(i);
            REQUIRE(evaluate(grid, color_e::red) == r[i]);
        }
    }

    SECTION("middle")
    {
        constexpr array<color_e, 2> c{color_e::red, color_e::yellow};
        constexpr array<int16_t, 2> r{WIN_POINT, LOOSE_POINT};
        for(int i = 0; i < 2; i++)
        {
            Board::grid_t grid;
            grid[2][3] = c[i];
            grid[3][3] = c[i];
            grid[4][3] = c[i];
            grid[5][3] = c[i];

            CAPTURE(i);
            REQUIRE(evaluate(grid, color_e::red) == r[i]);
        }
    }
}

TEST_CASE("eval_v", "[evaluate]")
{
    SECTION("empty board")
    {
        REQUIRE(evaluate(Board::grid_t{}, color_e::red) == 0);
        REQUIRE(evaluate(Board::grid_t{}, color_e::yellow) == 0);
    }

    SECTION("first column")
    {
        constexpr array<color_e, 2> c{color_e::red, color_e::yellow};
        constexpr array<int16_t, 2> r{WIN_POINT, LOOSE_POINT};
        for(int i = 0; i < 2; i++)
        {
            Board::grid_t grid;
            grid[0][2] = c[i];
            grid[0][3] = c[i];
            grid[0][4] = c[i];
            grid[0][5] = c[i];

            CAPTURE(i);
            REQUIRE(evaluate(grid, color_e::red) == r[i]);
        }
    }

    SECTION("first column at the top")
    {
        constexpr array<color_e, 2> c{color_e::red, color_e::yellow};
        constexpr array<int16_t, 2> r{WIN_POINT, LOOSE_POINT};
        for(int i = 0; i < 2; i++)
        {
            Board::grid_t grid;
            grid[0][0] = c[i];
            grid[0][1] = c[i];
            grid[0][2] = c[i];
            grid[0][3] = c[i];

            REQUIRE(evaluate(grid, color_e::red) == r[i]);
        }
    }

    SECTION("last column")
    {
        constexpr array<color_e, 2> c{color_e::red, color_e::yellow};
        constexpr array<int16_t, 2> r{WIN_POINT, LOOSE_POINT};
        for(int i = 0; i < 2; i++)
        {
            Board::grid_t grid;
            grid[6][0] = c[i];
            grid[6][1] = c[i];
            grid[6][2] = c[i];
            grid[6][3] = c[i];

            REQUIRE(evaluate(grid, color_e::red) == r[i]);
        }
    }

    SECTION("in the middle")
    {
        constexpr array<color_e, 2> c{color_e::red, color_e::yellow};
        constexpr array<int16_t, 2> r{WIN_POINT, LOOSE_POINT};
        for(int i = 0; i < 2; i++)
        {
            Board::grid_t grid;
            grid[3][1] = c[i];
            grid[3][2] = c[i];
            grid[3][3] = c[i];
            grid[3][4] = c[i];

            REQUIRE(evaluate(grid, color_e::red) == r[i]);
        }
    }
}

TEST_CASE("eval_d_down", "[evaluate]")
{
    // 2---r
    // 3--r
    // 4-r
    // 5r-
    // 0123456
    SECTION("bottom left")
    {
        constexpr array<color_e, 2> c{color_e::red, color_e::yellow};
        constexpr array<int16_t, 2> r{WIN_POINT, LOOSE_POINT};
        for(int i = 0; i < 2; i++)
        {
            Board::grid_t grid;
            grid[0][5] = c[i];
            grid[1][4] = c[i];
            grid[2][3] = c[i];
            grid[3][2] = c[i];

            CAPTURE(i);
            REQUIRE(evaluate(grid, color_e::red) == r[i]);
        }
    }

    //  0123
    // 0---r
    // 1--r
    // 2-r
    // 3r
    SECTION("top left")
    {
        constexpr array<color_e, 2> c{color_e::red, color_e::yellow};
        constexpr array<int16_t, 2> r{WIN_POINT, LOOSE_POINT};
        for(int i = 0; i < 2; i++)
        {
            Board::grid_t grid;
            grid[3][0] = c[i];
            grid[2][1] = c[i];
            grid[1][2] = c[i];
            grid[0][3] = c[i];

            CAPTURE(i);
            REQUIRE(evaluate(grid, color_e::red) == r[i]);
        }
    }

    //  01234
    // 0-----
    // 1----r
    // 2---r
    // 3--r
    // 4-r
    // 5-
    SECTION("middle")
    {
        constexpr array<color_e, 2> c{color_e::red, color_e::yellow};
        constexpr array<int16_t, 2> r{WIN_POINT, LOOSE_POINT};
        for(int i = 0; i < 2; i++)
        {
            Board::grid_t grid;
            grid[4][1] = c[i];
            grid[3][2] = c[i];
            grid[2][3] = c[i];
            grid[1][4] = c[i];

            CAPTURE(i);
            REQUIRE(evaluate(grid, color_e::red) == r[i]);
        }
    }

    //  0123456
    // 0------r
    // 1-----r
    // 2----r
    // 3---r
    SECTION("top right")
    {
        constexpr array<color_e, 2> c{color_e::red, color_e::yellow};
        constexpr array<int16_t, 2> r{WIN_POINT, LOOSE_POINT};
        for(int i = 0; i < 2; i++)
        {
            Board::grid_t grid;
            grid[6][0] = c[i];
            grid[5][1] = c[i];
            grid[4][2] = c[i];
            grid[3][3] = c[i];

            CAPTURE(i);
            REQUIRE(evaluate(grid, color_e::red) == r[i]);
        }
    }

    //  0123456
    // 2------r
    // 3-----r
    // 4----r
    // 5---r
    SECTION("bottom right")
    {
        constexpr array<color_e, 2> c{color_e::red, color_e::yellow};
        constexpr array<int16_t, 2> r{WIN_POINT, LOOSE_POINT};
        for(int i = 0; i < 2; i++)
        {
            Board::grid_t grid;
            grid[6][2] = c[i];
            grid[5][3] = c[i];
            grid[4][4] = c[i];
            grid[3][5] = c[i];

            CAPTURE(i);
            REQUIRE(evaluate(grid, color_e::red) == r[i]);
        }
    }
}

TEST_CASE("eval_d_up", "[evaluate]")
{
    //  0123456
    // 0r
    // 1-r
    // 2--r
    // 3---r
    SECTION("top left")
    {
        constexpr array<color_e, 2> c{color_e::red, color_e::yellow};
        constexpr array<int16_t, 2> r{WIN_POINT, LOOSE_POINT};
        for(int i = 0; i < 2; i++)
        {
            Board::grid_t grid;
            grid[0][0] = c[i];
            grid[1][1] = c[i];
            grid[2][2] = c[i];
            grid[3][3] = c[i];

            CAPTURE(i);
            REQUIRE(evaluate(grid, color_e::red) == r[i]);
        }
    }

    //  0123456
    // 2r
    // 3-r
    // 4--r
    // 5---r
    SECTION("bottom left")
    {
        constexpr array<color_e, 2> c{color_e::red, color_e::yellow};
        constexpr array<int16_t, 2> r{WIN_POINT, LOOSE_POINT};
        for(int i = 0; i < 2; i++)
        {
            Board::grid_t grid;
            grid[0][2] = c[i];
            grid[1][3] = c[i];
            grid[2][4] = c[i];
            grid[3][5] = c[i];

            CAPTURE(i);
            REQUIRE(evaluate(grid, color_e::red) == r[i]);
        }
    }

    //  0123456
    // 0---r---
    // 1----r--
    // 2-----r-
    // 3------r
    SECTION("top right")
    {
        constexpr array<color_e, 2> c{color_e::red, color_e::yellow};
        constexpr array<int16_t, 2> r{WIN_POINT, LOOSE_POINT};
        for(int i = 0; i < 2; i++)
        {
            Board::grid_t grid;
            grid[3][0] = c[i];
            grid[4][1] = c[i];
            grid[5][2] = c[i];
            grid[6][3] = c[i];

            CAPTURE(i);
            REQUIRE(evaluate(grid, color_e::red) == r[i]);
        }
    }

    //  0123456
    // 2---r---
    // 3----r--
    // 4-----r-
    // 5------r
    SECTION("bottom right")
    {
        constexpr array<color_e, 2> c{color_e::red, color_e::yellow};
        constexpr array<int16_t, 2> r{WIN_POINT, LOOSE_POINT};
        for(int i = 0; i < 2; i++)
        {
            Board::grid_t grid;
            grid[3][2] = c[i];
            grid[4][3] = c[i];
            grid[5][4] = c[i];
            grid[6][5] = c[i];

            CAPTURE(i);
            REQUIRE(evaluate(grid, color_e::red) == r[i]);
        }
    }

    //  0123456
    // 0
    // 1--r
    // 2---r
    // 3----r
    // 4-----r
    SECTION("middle")
    {
        constexpr array<color_e, 2> c{color_e::red, color_e::yellow};
        constexpr array<int16_t, 2> r{WIN_POINT, LOOSE_POINT};
        for(int i = 0; i < 2; i++)
        {
            Board::grid_t grid;
            grid[2][1] = c[i];
            grid[3][2] = c[i];
            grid[4][3] = c[i];
            grid[5][4] = c[i];

            CAPTURE(i);
            REQUIRE(evaluate(grid, color_e::red) == r[i]);
        }
    }
}
