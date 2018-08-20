
#pragma once

#include "game_p4.h"

namespace ai
{
static const auto MAX    = 1000;
static const auto MIN    = -MAX;
static const auto ALIGN3 = 3;    // -xxx
static const auto ALIGN2 = 2;    // --xx
static const auto ALIGN1 = 1;    // ---x

class Minmax
{
public:
    Minmax(const p4::Player& p, uint8_t depth);

    uint8_t compute(p4::Game_P4& game);

private:
    int16_t min(p4::Game_P4& game, uint8_t depth);
    int16_t max(p4::Game_P4& game, uint8_t depth);
    int16_t evaluate(const p4::Game_P4& game);
    int16_t evaluate_horizontal(const p4::Game_P4& game);
    int16_t evaluate_vertical(const p4::Game_P4& game);

    uint8_t depth;
    const p4::Player& player;
};
}
