
#pragma once

#include "color.h"
#include "game_p4.h"

#include <chrono>

namespace ai
{
class Minmax
{
public:
    Minmax(const p4::Player& p, uint8_t depth);

    uint8_t compute(p4::Game_P4 game) const;

private:
    int16_t min_copy(p4::Game_P4 game, int8_t depth) const;
    int16_t min(p4::Game_P4& game, int8_t depth) const;
    int16_t max(p4::Game_P4& game, int8_t depth) const;

    int16_t negamax(p4::Game_P4& game, int16_t alpha, int16_t beta, int16_t depth) const;

    uint8_t depth;
    mutable std::chrono::time_point<std::chrono::high_resolution_clock> start;
    const p4::Player& player;
};
}
