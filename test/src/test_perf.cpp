
#include "game_p4.h"
#include "minmax.h"

#include <catch.hpp>

#include <chrono>
#include <numeric>

using namespace p4;
using namespace ai;
using namespace std;

TEST_CASE("perf")
{
    SECTION("depth 0")
    {
        Game_P4 game;
        Minmax minmax(game.get_player(1), 0);
        vector<uint32_t> durations;
        for(int i = 0; i < 100; ++i)
        {
            auto start = std::chrono::high_resolution_clock::now();
            minmax.compute(game);
            auto stop = std::chrono::high_resolution_clock::now();

            auto d = chrono::duration_cast<chrono::microseconds>(stop - start).count();
            durations.push_back(d);
        }
        auto average = std::accumulate(durations.begin(), durations.end(), 0) / durations.size();
        REQUIRE(average == Approx(chrono::microseconds(200).count()).epsilon(0.10));
    }

    SECTION("depth 1")
    {
        Game_P4 game;
        Minmax minmax(game.get_player(1), 1);
        vector<uint32_t> durations;
        for(int i = 0; i < 100; ++i)
        {
            auto start = std::chrono::high_resolution_clock::now();
            minmax.compute(game);
            auto stop = std::chrono::high_resolution_clock::now();

            auto d = chrono::duration_cast<chrono::microseconds>(stop - start).count();
            durations.push_back(d);
        }
        auto average = std::accumulate(durations.begin(), durations.end(), 0) / durations.size();
        REQUIRE(average == Approx(chrono::microseconds(1300).count()).epsilon(0.10));
    }

    SECTION("depth 2")
    {
        Game_P4 game;
        Minmax minmax(game.get_player(1), 2);
        vector<uint32_t> durations;
        for(int i = 0; i < 100; ++i)
        {
            auto start = std::chrono::high_resolution_clock::now();
            minmax.compute(game);
            auto stop = std::chrono::high_resolution_clock::now();

            auto d = chrono::duration_cast<chrono::microseconds>(stop - start).count();
            durations.push_back(d);
        }
        auto average = std::accumulate(durations.begin(), durations.end(), 0) / durations.size();
        REQUIRE(average == Approx(chrono::microseconds(9000).count()).epsilon(0.10));
    }

    SECTION("depth 3")
    {
        Game_P4 game;
        Minmax minmax(game.get_player(1), 3);
        vector<uint32_t> durations;
        for(int i = 0; i < 100; ++i)
        {
            auto start = std::chrono::high_resolution_clock::now();
            minmax.compute(game);
            auto stop = std::chrono::high_resolution_clock::now();

            auto d = chrono::duration_cast<chrono::microseconds>(stop - start).count();
            durations.push_back(d);
        }
        auto average = std::accumulate(durations.begin(), durations.end(), 0) / durations.size();
        REQUIRE(average == Approx(chrono::microseconds(65000).count()).epsilon(0.10));
    }

    SECTION("depth 4")
    {
        Game_P4 game;
        Minmax minmax(game.get_player(1), 3);
        vector<uint32_t> durations;
        for(int i = 0; i < 100; ++i)
        {
            auto start = std::chrono::high_resolution_clock::now();
            minmax.compute(game);
            auto stop = std::chrono::high_resolution_clock::now();

            auto d = chrono::duration_cast<chrono::microseconds>(stop - start).count();
            durations.push_back(d);
        }
        auto average = std::accumulate(durations.begin(), durations.end(), 0) / durations.size();
        REQUIRE(average == Approx(chrono::milliseconds(63500).count()).epsilon(0.10));
    }
}
