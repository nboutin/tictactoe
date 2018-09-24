
#pragma once

#include "color.h"
#include "connect4.h"

#include <chrono>

namespace ai
{
class Minmax
{
public:
    static constexpr auto DURATION_MIN = std::chrono::seconds(0);
    enum class algo { minmax, minmax_parallel, alphabeta, negamax, negascout };

    using depth_t = int16_t;

    Minmax(const connect4::Player& p, depth_t depth);

    connect4::Connect4::move_t compute(connect4::Connect4 game,
                                       algo algo,
                                       std::chrono::seconds duration_min = DURATION_MIN) const;

private:
    bool is_leaf(const connect4::Connect4& game, depth_t depth) const;

    int16_t minmax_copy(connect4::Connect4 game, depth_t depth, bool is_max) const;
    int16_t minmax(connect4::Connect4& game, depth_t depth, bool is_max) const;

    int16_t negamax(connect4::Connect4& game, depth_t depth, bool is_max) const;

    int16_t alphabeta(connect4::Connect4& game,
                      depth_t _depth,
                      int16_t alpha,
                      int16_t beta,
                      bool is_max) const;

    int16_t negascout(connect4::Connect4& game, int16_t alpha, int16_t beta, depth_t depth) const;

    depth_t depth;
    mutable std::chrono::time_point<std::chrono::high_resolution_clock> start;
    mutable std::chrono::seconds duration_min;
    const connect4::Player& player;
};
}
