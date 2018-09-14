
#pragma once

#include <cstdint>
#include <limits>
#include <vector>

namespace ai
{
class MinMax
{
public:
    using move = struct
    {
        int x;
        int y;
    };

    class Game
    {
    public:
        virtual bool play(const move& move) = 0;
        virtual void undo()                 = 0;
        virtual bool is_finished() const    = 0;
        virtual int16_t evaluate() const    = 0;
    };

    enum class algo_e { minmax, minmax_parallel, alphabeta, negamax };

    MinMax(algo_e algo, int8_t depth) : algo(algo), depth(depth) {}

    move compute(Game& game, const std::vector<move>& moves);

private:
    bool is_leaf(const Game& game, int8_t _depth) { return (game.is_finished() || _depth <= 0); }
    int16_t minmax(Game& game, const std::vector<move>& moves, int8_t _depth, bool is_max);

    algo_e algo;
    int8_t depth;
};

MinMax::move MinMax::compute(Game& game, const std::vector<move>& moves)
{
    auto best_move = move{};
    auto max       = std::numeric_limits<int16_t>::min();

    switch(algo)
    {
    case algo_e::minmax:
    {
        for(auto m : moves)
        {
            if(game.play(m))
            {
                //                auto val = min(game, depth);
                auto val = minmax(game, moves, depth, false);
                if(val > max)
                {
                    max       = val;
                    best_move = m;
                }
            }
            game.undo();
        }
        return best_move;
    }
    case algo_e::minmax_parallel: break;
    case algo_e::alphabeta: break;
    case algo_e::negamax: break;
    }
    return best_move;
}

int16_t MinMax::minmax(Game& game, const std::vector<move>& moves, int8_t _depth, bool is_max)
{
    if(is_leaf(game, _depth))
        return game.evaluate();

    if(!is_max)
    {
        int16_t min = std::numeric_limits<int16_t>::max();

        for(auto m : moves)
        {
            int16_t val = 0;
            if(game.play(m))
            {
                val = minmax(game, moves, _depth - 1, true);
                if(val < min)
                    min = val;
            }
            game.undo();
        }
        return min;
    }
    else
    {
        int16_t max = std::numeric_limits<int16_t>::min();

        for(auto m : moves)
        {
            int16_t val = 0;
            if(game.play(m))
            {
                val = minmax(game, moves, _depth - 1, false);
                if(val > max)
                    max = val;
            }
            game.undo();
        }
        return max;
    }
}
}
