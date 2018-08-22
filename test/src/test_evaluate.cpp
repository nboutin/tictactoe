
#include <catch.hpp>
#include <vector>

#include "evaluate.h"
#include "view_ascii.h"

using namespace p4;
using namespace ai;
using namespace std;

//   0 1 2 3 4 5 6
// 0
// 1
// 2
// 3
// 4
// 5

TEST_CASE("eval_v", "[minmax]")
{
    SECTION("empty board")
    {
        REQUIRE(evaluate(Board::grid_t{}, color_e::red) == 0);
        REQUIRE(evaluate(Board::grid_t{}, color_e::yellow) == 0);
    }

    SECTION("first column")
    {
        Board::grid_t grid;
        for(int y = 2; y < Board::N_ROW; ++y)
            grid[0][y] = color_e::red;

        REQUIRE(evaluate(grid, color_e::red) == MAX);
    }

    //    SECTION("y4")
    //    {
    //        Minmax minmax(game.get_player(1), 0);
    //
    //        for(auto m : vector<int>{1, 0, 1, 0, 3, 1, 0, 1, 0, 1, 3, 1})
    //            game.play(m);
    //
    //        REQUIRE(minmax.evaluate(game) == MIN);
    //    }
    //
    //    SECTION("zero")
    //    {
    //        Minmax minmax(game.get_player(1), 0);
    //
    //        for(auto m : vector<int>{0, 3, 0, 3, 0, 0, 1, 3, 3})
    //            game.play(m);
    //
    //        REQUIRE(minmax.evaluate(game) == 0);
    //    }

    //    SECTION("x0 r3")
    //    {
    //        // r
    //        // r
    //        // ry y
    //        Minmax minmax(game.get_player(1), 0);
    //
    //        for(auto m : vector<int>{0, 1, 0, 3, 0})
    //            game.play(m);
    //
    //        REQUIRE(minmax.evaluate(game) == ALIGN3);
    //    }
    //
    //    SECTION("x2 r3")
    //    {
    //        Minmax minmax(game.get_player(1), 0);
    //
    //        for(auto m : vector<int>{2, 1, 2, 3, 2})
    //            game.play(m);
    //
    //        REQUIRE(minmax.evaluate(game) == ALIGN3);
    //    }
    //
    //    SECTION("x2y4 r3")
    //    {
    //        Minmax minmax(game.get_player(1), 0);
    //
    //        for(auto m : vector<int>{0, 2, 2, 4, 2, 6, 2})
    //            game.play(m);
    //
    //        REQUIRE(minmax.evaluate(game) == ALIGN3);
    //    }
    //
    //    SECTION("x2y4 r3")
    //    {
    //        Minmax minmax(game.get_player(1), 0);
    //
    //        for(auto m : vector<int>{0, 1, 2, 1, 4, 1})
    //            game.play(m);
    //
    //        REQUIRE(minmax.evaluate(game) == -ALIGN3);
    //    }
}

// TEST_CASE("evaluate horizontal", "[minmax][eval_h]")
//{
//    Game_P4 game;
//    game.set_ai(1);
//
//    SECTION("r4 x0y5")
//    {
//        Minmax minmax(game.get_player(1), 0);
//
//        for(auto m : vector<int>{0, 0, 1, 1, 2, 2, 3})
//            game.play(m);
//
//        REQUIRE(minmax.evaluate(game) == MAX);
//    }
//
//    SECTION("r4 x3y5")
//    {
//        Minmax minmax(game.get_player(1), 0);
//
//        for(auto m : vector<int>{3, 3, 4, 4, 5, 5, 6})
//            game.play(m);
//
//        REQUIRE(minmax.evaluate(game) == MAX);
//    }
//
//    SECTION("y4 x2y0")
//    {
//        Minmax minmax(game.get_player(1), 0);
//
//        for(auto m : vector<int>{2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 4,
//                                 4, 4, 4, 4, 4, 6, 5, 5, 5, 5, 5, 0, 5})
//            game.play(m);
//
//        REQUIRE(minmax.evaluate(game) == MIN);
//    }
//}
