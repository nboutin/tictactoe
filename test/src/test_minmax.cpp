
#include <catch.hpp>
#include <vector>

#include "game_p4.h"
#include "view_ascii.h"

/// \warning Nasty trick to access private methods when testing
/// DO NOT put header file below
#define private public
#include "minmax.h"

using namespace p4;
using namespace ai;
using namespace std;

// TEST_CASE("eval", "[minmax]")
//{
//    SECTION("")
//    {
//        Game_P4 game;
//        game.set_ai(1);
//
//        Minmax minmax(game.get_player(1), 0);
//
//        //    y---
//        //    r-y-
//        //    r-y-
//        //    rry-
//        for(auto m : vector<int>{0, 3, 0, 3, 0, 3, 1, 0})
//            game.play(m);
//
//        game.play(0);
//
//        game.play(0);
//        REQUIRE(minmax.evaluate(game) == -3);
//        game.unplay(0);
//
//        game.play(1);
//        REQUIRE(minmax.evaluate(game) == -3);
//        game.unplay(1);
//
//        game.play(2);
//        REQUIRE(minmax.evaluate(game) == -3);
//        game.unplay(2);
//
//        game.play(3);
//        REQUIRE(minmax.evaluate(game) == -1000);
//        REQUIRE(game.is_finished());
//        game.unplay(3);
//        REQUIRE_FALSE(game.is_finished());
//
//        game.play(4);
//        view::View_ASCII v(game.get_board());
//        v.display(false);
//        REQUIRE(minmax.evaluate(game) == -3);
//        game.unplay(4);
//
//        //        view::View_ASCII v(game.get_board());
//        //        v.display(false);
//    }
//}

TEST_CASE("min", "[minmax]")
{
    // ----
    // ----
    // r-Y-
    // r-y-
    // r-y-
    SECTION("depth 0")
    {
        const vector<int> moves{0, 3, 0, 3, 0, 3};
        const array<int16_t, Board::N_COLUMN> expected{1000, 0, 0, 0, 0, 0};

        Game_P4 game;
        Minmax minmax(game.get_player(1), 0);

        for(auto m : moves)
            game.play(m);

        view::View_ASCII v(game.get_board());
        v.display(false);

        for(int i = 0; i < Board::N_COLUMN; ++i)
        {
            if(i == 3)
            {
                view::View_ASCII v(game.get_board());
                v.display(false);
            }
            game.play(i);

            if(i == 3)
            {
                view::View_ASCII v(game.get_board());
                v.display(false);
            }

            CAPTURE(i);
            REQUIRE(minmax.min(game, 0) == expected[i]);

            game.undo();
        }
    }
}

// TEST_CASE("compute", "[minmax]")
//{
//    Game_P4 game;
//    game.set_ai(1);
//
//    //    y---
//    //    r-y-
//    //    r-y-
//    //    rry-
//    for(auto m : vector<int>{0, 3, 0, 3, 0, 0, 1, 3})
//        game.play(m);
//
//    //    SECTION("depth 0")
//    //    {
//    //        Minmax minmax(game.get_player(1), 0);
//    //        REQUIRE(minmax.compute(game) == 3);
//    //    }
//
//    SECTION("depth 1")
//    {
//        view::View_ASCII v(game.get_board());
//        v.display(false);
//        cout << "start position" << endl;
//
//        Minmax minmax(game.get_player(1), 1);
//        REQUIRE(minmax.compute(game) == 3);
//    }
//}

// TEST_CASE("debug", "")
//{
//    Game_P4 game;
//    game.set_ai(1);
//    Minmax minmax(game.get_player(1), 0);
//
//    for(auto m :
//        vector<int>{2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 6,
//        5, 5, 5, 5, 5, 0, 5}) game.play(m);
//
//    view::View_ASCII v(game.get_board());
//    v.display(false);
//
//    REQUIRE(minmax.evaluate(game) == MIN);
//}
