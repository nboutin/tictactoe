
#pragma once

#include "color.h"
#include "connect4.h"

namespace ai
{
constexpr auto WIN_POINT   = 100;
constexpr auto LOOSE_POINT = -WIN_POINT;

int16_t evaluate(const connect4::Connect4& g, connect4::color_e win_color);

//int16_t evaluate(const connect4::Connect4& g, connect4::color_e win_color);

}
