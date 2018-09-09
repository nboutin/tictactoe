
#pragma once

#include "color.h"
#include "game_p4.h"

#include <chrono>

namespace ai
{
class Minmax
{
public:
    static constexpr auto DURATION_MIN = std::chrono::seconds(10);
    enum class algo { minmax, minmax_parallel, alphabeta, negamax };

    Minmax(const p4::Player& p, uint8_t depth);

    uint8_t
    compute(p4::Game_P4 game, algo algo, std::chrono::seconds duration_min = DURATION_MIN) const;

private:
    bool is_leaf(const p4::Game_P4& game, int8_t depth) const;

    int16_t min_copy(p4::Game_P4 game, int8_t depth) const;
    int16_t min(p4::Game_P4& game, int8_t depth) const;
    int16_t max(p4::Game_P4& game, int8_t depth) const;

    int16_t
    alphabeta(p4::Game_P4& game, int8_t _depth, int16_t alpha, int16_t beta, bool is_max) const;

    int16_t negamax(p4::Game_P4& game, int16_t alpha, int16_t beta, int16_t depth) const;

    uint8_t depth;
    mutable std::chrono::time_point<std::chrono::high_resolution_clock> start;
    mutable std::chrono::seconds duration_min;
    const p4::Player& player;
};
}
