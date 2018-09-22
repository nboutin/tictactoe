
#include "minmax.h"
#include "evaluate.h"
#include "helper_ostream.h"

#include <algorithm>
#include <future>
#include <iostream>
#include <limits>
#include <utility>

using namespace ai;
using namespace connect4;
using namespace std;

Minmax::Minmax(const connect4::Player& p, const uint8_t depth) : depth(depth), player(p) {}

uint8_t
Minmax::compute(connect4::Connect4 game, algo algo, const std::chrono::seconds _duration_min) const
{
    uint8_t best_move = 0;
    auto max          = std::numeric_limits<int16_t>::min();
    start             = chrono::high_resolution_clock::now();
    duration_min      = _duration_min;

    switch(algo)
    {
    case algo::minmax:
    {
        for(int m = 0; m < Board::N_COLUMN; ++m)
        {
            if(game.play(m))
            {
                auto val = minmax(game, depth, false);
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
    case algo::minmax_parallel:
    {
        using f_min = std::pair<int, std::future<int16_t>>;
        std::vector<f_min> vf_mins;

        for(int m = 0; m < Board::N_COLUMN; ++m)
        {
            if(game.play(m))
            {
                vf_mins.push_back(make_pair(
                    m,
                    std::async(
                        std::launch::async, &Minmax::minmax_copy, this, game, depth, false)));
            }
            game.undo();
        }

        for(auto&& mr : vf_mins)
        {
            auto val = mr.second.get();
            if(val > max)
            {
                max       = val;
                best_move = mr.first;
            }
        }
        return best_move;
    }
    case algo::alphabeta:
    {
        auto beta  = std::numeric_limits<int16_t>::max();
        auto alpha = std::numeric_limits<int16_t>::min();
        for(int m = 0; m < Board::N_COLUMN; ++m)
        {
            if(game.play(m))
            {
                auto val = alphabeta(game, depth, alpha, beta, true);

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
    case algo::negamax:
    {
        auto beta  = std::numeric_limits<int16_t>::max();
        auto alpha = std::numeric_limits<int16_t>::min();

        for(int m = 0; m < Board::N_COLUMN; ++m)
        {
            if(game.play(m))
            {
                auto val = negamax(game, alpha, beta, depth);
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
    }

    return best_move;
}

bool Minmax::is_leaf(const connect4::Connect4& game, int8_t _depth) const
{
    auto d = chrono::duration_cast<chrono::seconds>(chrono::high_resolution_clock::now() - start);
    return (game.is_finished() || (_depth <= 0 && d >= duration_min));
}

int16_t Minmax::minmax_copy(connect4::Connect4 game, int8_t depth, bool is_max) const
{
    return minmax(game, depth, is_max);
}

int16_t Minmax::minmax(connect4::Connect4& game, const int8_t _depth, bool is_max) const
{
    if(is_leaf(game, _depth))
        return evaluate(game, player.get_color());

    if(!is_max)    // min
    {
        int16_t min = std::numeric_limits<int16_t>::max();

        for(int m = 0; m < Board::N_COLUMN; ++m)
        {
            int16_t val = 0;
            if(game.play(m))
            {
                val = minmax(game, _depth - 1, true);
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

        for(int m = 0; m < Board::N_COLUMN; ++m)
        {
            int16_t val = 0;
            if(game.play(m))
            {
                val = minmax(game, _depth - 1, true);
                if(val > max)
                    max = val;
            }
            game.undo();
        }
        return max;
    }
}

// function alphabeta(node, depth, α, β, maximizingPlayer) is
//    if depth = 0 or node is a terminal node then
//        return the heuristic value of node
//    if maximizingPlayer then
//        value := −∞
//        for each child of node do
//            value := max(value, alphabeta(child, depth − 1, α, β, FALSE))
//            α := max(α, value)
//            if α ≥ β then
//                break (* β cut-off *)
//        return value
//    else
//        value := +∞
//        for each child of node do
//            value := min(value, alphabeta(child, depth − 1, α, β, TRUE))
//            β := min(β, value)
//            if α ≥ β then
//                break (* α cut-off *)
//        return value
//
//(* Initial call *)
// alphabeta(origin, depth, −∞, +∞, TRUE)
int16_t Minmax::alphabeta(connect4::Connect4& game,
                          const int8_t _depth,
                          const int16_t _alpha,
                          const int16_t _beta,
                          bool is_max) const
{
    if(is_leaf(game, _depth))
        return evaluate(game, player.get_color());

    auto alpha = _alpha;
    auto beta  = _beta;

    if(is_max)
    {
        for(int m = 0; m < Board::N_COLUMN; ++m)
        {
            if(game.play(m))
            {
                alpha = std::max(alpha, alphabeta(game, _depth - 1, alpha, beta, false));
                if(alpha >= beta)
                {
                    game.undo();
                    return beta;
                }
            }
            game.undo();
        }
        return alpha;
    }
    else
    {
        for(int m = 0; m < Board::N_COLUMN; ++m)
        {
            if(game.play(m))
            {
                beta = std::min(beta, alphabeta(game, _depth - 1, alpha, beta, true));
                if(alpha >= beta)
                {
                    game.undo();
                    return alpha;
                }
            }
            game.undo();
        }
        return beta;
    }
}

// fonction alphabeta(nœud, A, B) /* A < B */
//   si nœud est une feuille alors
//       retourner la valeur de nœud
//   sinon
//       meilleur = –∞
//       pour tout fils de nœud faire
//           v = -alphabeta(fils,-B,-A)
//           si v > meilleur alors
//               meilleur = v
//               si meilleur > A alors
//                   A = meilleur
//                   si A ≥ B alors
//                       retourner meilleur
//       retourner meilleur
int16_t Minmax::negamax(connect4::Connect4& game,
                        int16_t alpha,
                        const int16_t beta,
                        const int16_t _depth) const
{
    if(_depth == 0 || game.is_finished())
        return evaluate(game, player.get_color());

    int16_t best = std::numeric_limits<int16_t>::min();

    for(int m = 0; m < Board::N_COLUMN; ++m)
    {
        if(game.play(m))
        {
            int16_t val = -negamax(game, -beta, -alpha, _depth - 1);
            if(val > best)
            {
                best = val;
                if(best > alpha)
                {
                    alpha = best;
                    if(alpha >= beta)
                    {
                        game.undo();
                        return best;
                    }
                }
            }
        }
        game.undo();
    }
    return best;
    }
