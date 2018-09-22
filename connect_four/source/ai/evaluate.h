
#pragma once

#include "board.h"
#include "color.h"

namespace ai
{
constexpr auto WIN_POINT = 100;
constexpr auto LOOSE_POINT = -WIN_POINT;

int16_t evaluate(const connect4::Board::grid_t& grid, connect4::color_e win_color);
int16_t evaluate_horizontal(const connect4::Board::grid_t& grid, connect4::color_e win_color);
int16_t evaluate_vertical(const connect4::Board::grid_t& grid, connect4::color_e win_color);
int16_t evaluate_diagonal(const connect4::Board::grid_t& grid, connect4::color_e win_color);
}
