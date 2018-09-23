
#include "connect4.h"
#include "minmax.h"

#include <catch.hpp>

#include <chrono>
#include <numeric>

using namespace connect4;
using namespace ai;
using namespace std;

constexpr auto C0 = 3000;
constexpr auto C1 = 1000;
constexpr auto C2 = 100;
constexpr auto E1 = 0.03;

TEST_CASE("perf", "[!hide]")
{
#if 0
    SECTION("depth 0")
    {
        Connect4 game;
        Minmax minmax(game.get_player(player_e::p1), 0);
        vector<uint32_t> durations;
        for(int i = 0; i < C0; ++i)
        {
            auto start = std::chrono::high_resolution_clock::now();
            minmax.compute(game, Minmax::algo::minmax);
            auto stop = std::chrono::high_resolution_clock::now();

            auto d = chrono::duration_cast<chrono::nanoseconds>(stop - start).count();
            durations.push_back(d);
        }
        auto average = std::accumulate(durations.begin(), durations.end(), 0) / durations.size();
        REQUIRE(average == Approx(chrono::nanoseconds(8500).count()).epsilon(E1));
    }
#endif

    SECTION("depth 1")
    {
        Connect4 game;
        Minmax minmax(game.get_player(player_e::p1), 1);
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
        REQUIRE(average == Approx(chrono::microseconds(61).count()).epsilon(E1));
    }

    SECTION("depth 2")
    {
        Connect4 game;
        Minmax minmax(game.get_player(player_e::p1), 2);
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
        REQUIRE(average == Approx(chrono::microseconds(421).count()).epsilon(E1));
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
        REQUIRE(average == Approx(chrono::microseconds(3070).count()).epsilon(E1));
    }

    SECTION("depth 4")
    {
        Connect4 game;
        Minmax minmax(game.get_player(player_e::p1), 4);
        vector<uint32_t> durations;
        for(int i = 0; i < 100; ++i)
        {
            auto start = std::chrono::high_resolution_clock::now();
            minmax.compute(game, Minmax::algo::minmax);
            auto stop = std::chrono::high_resolution_clock::now();

            auto d = chrono::duration_cast<chrono::milliseconds>(stop - start).count();
            durations.push_back(d);
        }
        auto average = std::accumulate(durations.begin(), durations.end(), 0) / durations.size();
        REQUIRE(average == Approx(chrono::milliseconds(20).count()).epsilon(E1));
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

            auto d = chrono::duration_cast<chrono::milliseconds>(stop - start).count();
            durations.push_back(d);
        }
        auto average = std::accumulate(durations.begin(), durations.end(), 0) / durations.size();
        REQUIRE(average == Approx(chrono::milliseconds(150).count()).epsilon(E1));
    }

    SECTION("depth 6")
    {
        Connect4 game;
        Minmax minmax(game.get_player(player_e::p1), 6);
        vector<uint32_t> durations;
        for(int i = 0; i < 10; ++i)
        {
            auto start = std::chrono::high_resolution_clock::now();
            minmax.compute(game, Minmax::algo::minmax);
            auto stop = std::chrono::high_resolution_clock::now();

            auto d = chrono::duration_cast<chrono::milliseconds>(stop - start).count();
            durations.push_back(d);
        }
        auto average = std::accumulate(durations.begin(), durations.end(), 0) / durations.size();
        REQUIRE(average == Approx(chrono::milliseconds(1040).count()).epsilon(E1));
    }
}
