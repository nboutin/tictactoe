
#include "game_p4.h"
#include "minmax.h"

#include <catch.hpp>

#include <chrono>
#include <numeric>

using namespace p4;
using namespace ai;
using namespace std;

constexpr auto C1   = 1000;
constexpr auto C2   = 100;
constexpr auto E1   = 0.05;

TEST_CASE("perf")
{
    SECTION("depth 0")
    {
        Game_P4 game;
        Minmax minmax(game.get_player(1), 0);
        vector<uint32_t> durations;
        for(int i = 0; i < C1; ++i)
        {
            auto start = std::chrono::high_resolution_clock::now();
            minmax.compute(game);
            auto stop = std::chrono::high_resolution_clock::now();

            auto d = chrono::duration_cast<chrono::microseconds>(stop - start).count();
            durations.push_back(d);
        }
        auto average = std::accumulate(durations.begin(), durations.end(), 0) / durations.size();
        REQUIRE(average == Approx(chrono::microseconds(180).count()).epsilon(E1));
    }

    SECTION("depth 1")
    {
        Game_P4 game;
        Minmax minmax(game.get_player(1), 1);
        vector<uint32_t> durations;
        for(int i = 0; i < C1; ++i)
        {
            auto start = std::chrono::high_resolution_clock::now();
            minmax.compute(game);
            auto stop = std::chrono::high_resolution_clock::now();

            auto d = chrono::duration_cast<chrono::microseconds>(stop - start).count();
            durations.push_back(d);
        }
        auto average = std::accumulate(durations.begin(), durations.end(), 0) / durations.size();
        REQUIRE(average == Approx(chrono::microseconds(1285).count()).epsilon(E1));
    }

    SECTION("depth 2")
    {
        Game_P4 game;
        Minmax minmax(game.get_player(1), 2);
        vector<uint32_t> durations;
        for(int i = 0; i < C1; ++i)
        {
            auto start = std::chrono::high_resolution_clock::now();
            minmax.compute(game);
            auto stop = std::chrono::high_resolution_clock::now();

            auto d = chrono::duration_cast<chrono::microseconds>(stop - start).count();
            durations.push_back(d);
        }
        auto average = std::accumulate(durations.begin(), durations.end(), 0) / durations.size();
        REQUIRE(average == Approx(chrono::microseconds(9060).count()).epsilon(E1));
    }

    SECTION("depth 3")
    {
        Game_P4 game;
        Minmax minmax(game.get_player(1), 3);
        vector<uint32_t> durations;
        for(int i = 0; i < C2; ++i)
        {
            auto start = std::chrono::high_resolution_clock::now();
            minmax.compute(game);
            auto stop = std::chrono::high_resolution_clock::now();

            auto d = chrono::duration_cast<chrono::microseconds>(stop - start).count();
            durations.push_back(d);
        }
        auto average = std::accumulate(durations.begin(), durations.end(), 0) / durations.size();
        REQUIRE(average == Approx(chrono::microseconds(63700).count()).epsilon(E1));
    }

    SECTION("depth 4")
    {
        Game_P4 game;
        Minmax minmax(game.get_player(1), 3);
        vector<uint32_t> durations;
        for(int i = 0; i < C2; ++i)
        {
            auto start = std::chrono::high_resolution_clock::now();
            minmax.compute(game);
            auto stop = std::chrono::high_resolution_clock::now();

            auto d = chrono::duration_cast<chrono::microseconds>(stop - start).count();
            durations.push_back(d);
        }
        auto average = std::accumulate(durations.begin(), durations.end(), 0) / durations.size();
        REQUIRE(average == Approx(chrono::milliseconds(64350).count()).epsilon(E1));
    }
}
