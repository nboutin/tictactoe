
#pragma once

#include "board.h"
#include "color.h"

namespace ai
{
static const auto MAX    = 1000;
static const auto MIN    = -MAX;
static const auto ALIGN3 = 3;    // -xxx
static const auto ALIGN2 = 2;    // --xx
static const auto ALIGN1 = 1;    // ---x

int16_t evaluate(const p4::Board::grid_t& grid, p4::color_e win_color);
int16_t evaluate_horizontal(const p4::Board::grid_t& grid, p4::color_e win_color);
int16_t evaluate_vertical(const p4::Board::grid_t& grid, p4::color_e win_color);
}
