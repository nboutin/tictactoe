
#include "minmax.h"
#include "evaluate.h"
//#include "view_ascii.h"

#include <iostream>
#include <limits>
#include <utility>

using namespace ai;
using namespace p4;
using namespace std;

Minmax::Minmax(const p4::Player& p, const uint8_t depth) : depth(depth), player(p) {}

uint8_t Minmax::compute(p4::Game_P4 game) const
{
    int16_t max       = std::numeric_limits<int16_t>::min();
    uint8_t best_move = 0;

    //    vector<pair<int, int>> v_min;
    //    int16_t val = 0;

    for(int m = 0; m < Board::N_COLUMN; ++m)
    {
        if(game.play(m))
        {
            auto val = min(game, depth);

            if(val > max)
            {
                max       = val;
                best_move = m;
            }
        }
        game.undo();
        //        v_min.push_back(make_pair(m, val));
    }

    //    cout << "compute";
    //    for(auto t : v_min)
    //        cout << "(" << t.first << ',' << t.second << ')';
    //    cout << endl;

    return best_move;
}

int16_t Minmax::min(p4::Game_P4& game, const uint8_t _depth) const
{
    if(_depth == 0 || game.is_finished())
        return evaluate(game.get_board().get_grid(), player.get_color());

    int16_t min = std::numeric_limits<int16_t>::max();
    //    vector<pair<int, int>> v_max;
    //    int16_t val = 0;

    for(int m = 0; m < Board::N_COLUMN; ++m)
    {
        //    	cout << "m:" << m;
        if(game.play(m))
        {
            auto val = max(game, _depth - 1);
            if(val < min)
                min = val;
        }
        game.undo();
        //        v_max.push_back(make_pair(m, val));
    }

    //    cout << "min";
    //    for(auto t : v_max)
    //        cout << "(" << t.first << ',' << t.second << ')';
    //    cout << endl;

    return min;
}

int16_t Minmax::max(p4::Game_P4& game, const uint8_t _depth) const
{
    if(_depth == 0 || game.is_finished())
        return evaluate(game.get_board().get_grid(), player.get_color());

    int16_t max = std::numeric_limits<int16_t>::min();
    //    vector<pair<int, int>> v_min;
    //    int16_t val = 0;

    for(int m = 0; m < Board::N_COLUMN; ++m)
    {
        if(game.play(m))
        {
            auto val = min(game, _depth - 1);
            if(val > max)
                max = val;
        }
        game.undo();
        //        v_min.push_back(make_pair(m, val));
    }

    //    cout << "max";
    //    for(auto t : v_min)
    //        cout << "(" << t.first << ',' << t.second << ')';
    //    cout << endl;

    return max;
}
