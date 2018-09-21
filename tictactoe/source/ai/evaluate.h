
#pragma once

#include "tictactoe.h"
#include "token.h"

#include <cstdint>

constexpr auto WIN_POINT   = 100;
constexpr auto LOOSE_POINT = -WIN_POINT;

int16_t evaluate(const tictactoe::TicTacToe& g, tictactoe::token_e win_token);
