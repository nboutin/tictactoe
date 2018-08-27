
#include <catch.hpp>
#include <vector>

#include "evaluate.h"
#include "game_p4.h"
#include "view_ascii.h"

/// \warning Nasty trick to access private methods when testing
/// DO NOT put header file below
#define private public
#include "minmax.h"

using namespace p4;
using namespace ai;
using namespace std;

TEST_CASE("min", "[minmax]")
{
    // -----
    // -----
    // r--Y-
    // r--y-
    // r--y-
    SECTION("depth 0")
    {
        const int depth = 0;
        const vector<int> moves{0, 3, 0, 3, 0, 3};
        const array<int16_t, Board::N_COLUMN> expected{WIN_POINT, 0, 0, 0, 0, 0, 0};

        Game_P4 game;
        Minmax minmax(game.get_player(1), depth);

        for(auto m : moves)
            game.play(m);

        for(int i = 0; i < Board::N_COLUMN; ++i)
        {
            REQUIRE(game.play(i));
            CAPTURE(i);
            REQUIRE(minmax.min(game, 0) == expected[i]);

            game.undo();
        }
    }

    // -----
    // -----
    // r--Y-
    // r--y-
    // r--y-
    // 0123456
    SECTION("depth 1")
    {
        const int depth = 0;
        const vector<int> moves{0, 3, 0, 3, 0, 3};
        const array<int16_t, Board::N_COLUMN> expected_min{WIN_POINT, 0, 0, 0, 0, 0, 0};
        const array<array<int16_t, Board::N_COLUMN>, Board::N_COLUMN> expected_max{{
            {{0, 0, 0, 0, 0, 0, 0}},    // no used
            {{0, 0, 0, LOOSE_POINT, 0, 0, 0}},
            {{0, 0, 0, LOOSE_POINT, 0, 0, 0}},
            {{0, 0, 0, 0, 0, 0, 0}},
            {{0, 0, 0, LOOSE_POINT, 0, 0, 0}},
            {{0, 0, 0, LOOSE_POINT, 0, 0, 0}},
            {{0, 0, 0, LOOSE_POINT, 0, 0, 0}},
        }};

        Game_P4 game;
        Minmax minmax(game.get_player(1), depth);

        for(auto m : moves)
            game.play(m);

        for(int i = 0; i < Board::N_COLUMN; ++i)
        {
            REQUIRE(game.get_current_player().get_color() == color_e::red);
            CAPTURE(i);
            REQUIRE(game.play(i));

            REQUIRE(minmax.min(game, depth) == expected_min[i]);

            for(int j = 0; j < Board::N_COLUMN; ++j)
            {
                if(i == 0)
                    continue;

                REQUIRE(game.get_current_player().get_color() == color_e::yellow);

                CAPTURE(j);
                REQUIRE(game.play(j));

                REQUIRE(minmax.max(game, depth) == expected_max[i][j]);
                game.undo();
            }
            game.undo();
        }
    }
}
