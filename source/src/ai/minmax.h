
#pragma once

#include "color.h"
#include "game_p4.h"

namespace ai
{
class Minmax
{
public:
    Minmax(const p4::Player& p, uint8_t depth);

    uint8_t compute(p4::Game_P4 game);

private:
    int16_t min(p4::Game_P4& game, uint8_t depth);
    int16_t max(p4::Game_P4& game, uint8_t depth);

    uint8_t depth;
    const p4::Player& player;
};
}
