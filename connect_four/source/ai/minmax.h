
#pragma once

#include "color.h"
#include <chrono>
#include "../inc/connect4.h"

namespace ai
{
class Minmax
{
public:
    static constexpr auto DURATION_MIN = std::chrono::seconds(10);
    enum class algo { minmax, minmax_parallel, alphabeta, negamax };

    Minmax(const connect4::Player& p, uint8_t depth);

    uint8_t
    compute(connect4::Connect4 game, algo algo, std::chrono::seconds duration_min = DURATION_MIN) const;

private:
    bool is_leaf(const connect4::Connect4& game, int8_t depth) const;

    int16_t min_copy(connect4::Connect4 game, int8_t depth) const;
    int16_t min(connect4::Connect4& game, int8_t depth) const;
    int16_t max(connect4::Connect4& game, int8_t depth) const;

    int16_t
    alphabeta(connect4::Connect4& game, int8_t _depth, int16_t alpha, int16_t beta, bool is_max) const;

    int16_t negamax(connect4::Connect4& game, int16_t alpha, int16_t beta, int16_t depth) const;

    uint8_t depth;
    mutable std::chrono::time_point<std::chrono::high_resolution_clock> start;
    mutable std::chrono::seconds duration_min;
    const connect4::Player& player;
};
}
