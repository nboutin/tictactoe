
#pragma once

#include "game_p4.h"

namespace ai
{
class Minmax
{
public:
    uint8_t compute(p4::Game_P4& game, uint8_t profondeur);

private:
    int16_t min(p4::Game_P4& game, uint8_t profondeur);
    int16_t max(p4::Game_P4& game, uint8_t profondeur);
    int16_t evaluate(const p4::Game_P4& game);
};
}
