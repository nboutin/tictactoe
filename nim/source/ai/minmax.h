
#pragma once

#include "nim.h"

#include <chrono>

namespace ai
{
class Minmax
{
public:
    static constexpr auto DURATION_MIN = std::chrono::seconds(0);
    enum class algo { minmax, minmax_parallel, alphabeta, negamax, negascout };

    using depth_t = int16_t;

    Minmax(const nim::Player& p, depth_t depth);

    nim::Board::move_t
    compute(nim::Nim game, algo algo, std::chrono::seconds duration_min = DURATION_MIN) const;

private:
    bool is_leaf(const nim::Nim& game, depth_t depth) const;

    int16_t minmax_copy(nim::Nim game, depth_t depth, bool is_max) const;
    int16_t minmax(nim::Nim& game, depth_t depth, bool is_max) const;

    int16_t negamax(nim::Nim& game, depth_t depth, bool is_max) const;

    int16_t
    alphabeta(nim::Nim& game, depth_t _depth, int16_t alpha, int16_t beta, bool is_max) const;

    int16_t negascout(nim::Nim& game, int16_t alpha, int16_t beta, depth_t depth) const;

    depth_t depth;
    mutable std::chrono::time_point<std::chrono::high_resolution_clock> start;
    mutable std::chrono::seconds duration_min;
    const nim::Player& player;
};
}
