
#include "minmax.h"
#include "evaluate.h"
//#include "view_ascii.h"
#include "helper_ostream.h"

#include <algorithm>
#include <future>
#include <iostream>
#include <limits>
#include <utility>

using namespace ai;
using namespace p4;
using namespace std;

Minmax::Minmax(const p4::Player& p, const uint8_t depth) : depth(depth), player(p) {}

uint8_t Minmax::compute(p4::Game_P4 game)
{
    auto max = std::numeric_limits<int16_t>::min();
    //    auto alpha        = std::numeric_limits<int16_t>::min();
    //    auto beta         = std::numeric_limits<int16_t>::max();
    uint8_t best_move = 0;
    std::vector<int> vals;

    using f_min = std::pair<int, std::future<int16_t>>;
    std::vector<f_min> vf_mins;

    for(int m = 0; m < Board::N_COLUMN; ++m)
    {
        if(game.play(m))
        {
            vf_mins.push_back(
                make_pair(m, std::async(std::launch::async, &Minmax::min_copy, this, game, depth)));

            // auto val = negamax(game, alpha, beta, depth);
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
        vals.push_back(val);
    }

    cout << "compute:" << vals << '\n';

    return best_move;
}

int16_t Minmax::min_copy(p4::Game_P4 game, uint8_t depth) { return min(game, depth); }

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
int16_t
Minmax::negamax(p4::Game_P4& game, int16_t alpha, const int16_t beta, const int16_t _depth) const
{
    if(_depth == 0 || game.is_finished())
        return evaluate(game.get_board().get_grid(), player.get_color());

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

int16_t Minmax::min(p4::Game_P4& game, const uint8_t _depth)
{
    if(_depth == 0 || game.is_finished())
        return evaluate(game.get_board().get_grid(), player.get_color());

    int16_t min = std::numeric_limits<int16_t>::max();

    for(int m = 0; m < Board::N_COLUMN; ++m)
    {
        int16_t val = 0;
        if(game.play(m))
        {
            val = max(game, _depth - 1);
            if(val < min)
                min = val;
        }
        game.undo();
    }
    //    data[depth - _depth].push_back(val);
    return min;
}

int16_t Minmax::max(p4::Game_P4& game, const uint8_t _depth)
{
    if(_depth == 0 || game.is_finished())
        return evaluate(game.get_board().get_grid(), player.get_color());

    int16_t max = std::numeric_limits<int16_t>::min();

    for(int m = 0; m < Board::N_COLUMN; ++m)
    {
        int16_t val = 0;
        if(game.play(m))
        {
            val = min(game, _depth - 1);
            if(val > max)
                max = val;
        }
        game.undo();
        //        data[depth - _depth].push_back(val);
    }
    return max;
}
