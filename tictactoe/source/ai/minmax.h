
#pragma once

#include "tictactoe.h"

#include <chrono>

namespace ai
{
class Minmax
{
public:
    static constexpr auto DURATION_MIN = std::chrono::seconds(10);
    enum class algo { minmax, minmax_parallel, alphabeta, negamax };

    Minmax(const tictactoe::Player& p, uint8_t depth);

    tictactoe::Board::Point compute(tictactoe::TicTacToe game,
                                    algo algo,
                                    std::chrono::seconds duration_min = DURATION_MIN) const;

private:
    bool is_leaf(const tictactoe::TicTacToe& game, int8_t depth) const;

    int16_t min_copy(tictactoe::TicTacToe game, int8_t depth) const;
    int16_t min(tictactoe::TicTacToe& game, int8_t depth) const;
    int16_t max(tictactoe::TicTacToe& game, int8_t depth) const;
#if 0
    int16_t alphabeta(tictactoe::TicTacToe& game,
                      int8_t _depth,
                      int16_t alpha,
                      int16_t beta,
                      bool is_max) const;

    int16_t negamax(tictactoe::TicTacToe& game, int16_t alpha, int16_t beta, int16_t depth) const;
#endif
    uint8_t depth;
    mutable std::chrono::time_point<std::chrono::high_resolution_clock> start;
    mutable std::chrono::seconds duration_min;
    const tictactoe::Player& player;
};
}
