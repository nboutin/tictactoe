
#pragma once

#include "board.h"
#include "color.h"

namespace ai
{
constexpr auto WIN_POINT = 100;
constexpr auto LOOSE_POINT = -WIN_POINT;

int16_t evaluate(const p4::Board::grid_t& grid, p4::color_e win_color);
int16_t evaluate_horizontal(const p4::Board::grid_t& grid, p4::color_e win_color);
int16_t evaluate_vertical(const p4::Board::grid_t& grid, p4::color_e win_color);
int16_t evaluate_diagonal(const p4::Board::grid_t& grid, p4::color_e win_color);
}
