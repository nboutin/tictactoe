
#include "connect4.h"
#include "minmax.h"

#include <catch.hpp>

#include <chrono>
#include <numeric>

using namespace connect4;
using namespace ai;
using namespace std;

constexpr auto C1 = 1000;
constexpr auto C2 = 100;
constexpr auto E1 = 0.02;

TEST_CASE("perf", "[!hide]")
{
    SECTION("depth 0")
    {
        Connect4 game;
        Minmax minmax(game.get_player(player_e::p1), 0);
        vector<uint32_t> durations;
        for(int i = 0; i < C1; ++i)
        {
            auto start = std::chrono::high_resolution_clock::now();
            minmax.compute(game, Minmax::algo::minmax);
            auto stop = std::chrono::high_resolution_clock::now();

            auto d = chrono::duration_cast<chrono::microseconds>(stop - start).count();
            durations.push_back(d);
        }
        auto average = std::accumulate(durations.begin(), durations.end(), 0) / durations.size();
        REQUIRE(average == Approx(chrono::microseconds(180).count()).epsilon(E1));
    }
#if 0
    SECTION("depth 1")
    {
        Connect4 game;
        Minmax minmax(game.get_player(player_e::p1), 1);
        vector<uint32_t> durations;
        for(int i = 0; i < C1; ++i)
        {
            auto start = std::chrono::high_resolution_clock::now();
            minmax.compute(game, Minmax::algo::minmax_parallel);
            auto stop = std::chrono::high_resolution_clock::now();

            auto d = chrono::duration_cast<chrono::microseconds>(stop - start).count();
            durations.push_back(d);
        }
        auto average = std::accumulate(durations.begin(), durations.end(), 0) / durations.size();
        REQUIRE(average == Approx(chrono::microseconds(1285).count()).epsilon(E1));
    }

    SECTION("depth 2")
    {
        Connect4 game;
        Minmax minmax(game.get_player(player_e::p1), 2);
        vector<uint32_t> durations;
        for(int i = 0; i < C1; ++i)
        {
            auto start = std::chrono::high_resolution_clock::now();
            minmax.compute(game, Minmax::algo::minmax_parallel);
            auto stop = std::chrono::high_resolution_clock::now();

            auto d = chrono::duration_cast<chrono::microseconds>(stop - start).count();
            durations.push_back(d);
        }
        auto average = std::accumulate(durations.begin(), durations.end(), 0) / durations.size();
        REQUIRE(average == Approx(chrono::microseconds(9060).count()).epsilon(E1));
    }

    SECTION("depth 3")
    {
        Connect4 game;
        Minmax minmax(game.get_player(player_e::p1), 3);
        vector<uint32_t> durations;
        for(int i = 0; i < C2; ++i)
        {
            auto start = std::chrono::high_resolution_clock::now();
            minmax.compute(game, Minmax::algo::minmax);
            auto stop = std::chrono::high_resolution_clock::now();

            auto d = chrono::duration_cast<chrono::microseconds>(stop - start).count();
            durations.push_back(d);
        }
        auto average = std::accumulate(durations.begin(), durations.end(), 0) / durations.size();
        REQUIRE(average == Approx(chrono::microseconds(63700).count()).epsilon(E1));
    }

    SECTION("depth 4")
    {
        Connect4 game;
        Minmax minmax(game.get_player(player_e::p1), 4);
        vector<uint32_t> durations;
        for(int i = 0; i < 50; ++i)
        {
            auto start = std::chrono::high_resolution_clock::now();
            minmax.compute(game, Minmax::algo::minmax);
            auto stop = std::chrono::high_resolution_clock::now();

            auto d = chrono::duration_cast<chrono::microseconds>(stop - start).count();
            durations.push_back(d);
        }
        auto average = std::accumulate(durations.begin(), durations.end(), 0) / durations.size();
        REQUIRE(average == Approx(chrono::milliseconds(452650).count()).epsilon(E1));
    }

    SECTION("depth 5")
    {
        Connect4 game;
        Minmax minmax(game.get_player(player_e::p1), 5);
        vector<uint32_t> durations;
        for(int i = 0; i < 10; ++i)
        {
            auto start = std::chrono::high_resolution_clock::now();
            minmax.compute(game, Minmax::algo::minmax);
            auto stop = std::chrono::high_resolution_clock::now();

            auto d = chrono::duration_cast<chrono::microseconds>(stop - start).count();
            durations.push_back(d);
        }
        auto average = std::accumulate(durations.begin(), durations.end(), 0) / durations.size();
        REQUIRE(average == Approx(chrono::milliseconds(3101100).count()).epsilon(E1));
    }

    //    SECTION("depth 6")
    //    {
    //        Connect4 game;
    //        Minmax minmax(game.get_player(player_e::p1), 6);
    //        vector<uint32_t> durations;
    //        for(int i = 0; i < 1; ++i)
    //        {
    //            auto start = std::chrono::high_resolution_clock::now();
    //            minmax.compute(game, Minmax::algo::minmax);
    //            auto stop = std::chrono::high_resolution_clock::now();
    //
    //            auto d = chrono::duration_cast<chrono::milliseconds>(stop - start).count();
    //            durations.push_back(d);
    //        }
    //        auto average = std::accumulate(durations.begin(), durations.end(), 0) /
    //        durations.size(); REQUIRE(average ==
    //        Approx(chrono::milliseconds(21000).count()).epsilon(E1));
    //    }
#endif
}
