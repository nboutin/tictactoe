
#include "minmax.h"

#include <limits>

using namespace ai;
using namespace p4;
using namespace std;

#include <iostream>
#include <view_ascii.h>

Minmax::Minmax(const p4::Player& p, uint8_t depth) : depth(depth), player(p) {}

uint8_t Minmax::compute(p4::Game_P4& game)
{
    int16_t max       = std::numeric_limits<int16_t>::min();
    uint8_t best_move = 0;

    for(int m = 0; m < Board::N_COLUMN; ++m)
    {
        game.play(m);
        //        view::View_ASCII v(game.get_board());
        //        v.display(false);

        int16_t val = min(game, depth);

        if(val > max)
        {
            max       = val;
            best_move = m;
        }

        game.unplay(m);
    }

    return best_move;
}

int16_t Minmax::min(p4::Game_P4& game, uint8_t _depth)
{
    if(_depth == 0 || game.is_finished())
        return evaluate(game);

    int16_t min = std::numeric_limits<int16_t>::max();

    for(int m = 0; m < Board::N_COLUMN; ++m)
    {
        game.play(m);

        int16_t val = max(game, _depth - 1);
        if(val < min)
            min = val;

        game.unplay(m);
    }
    return min;
}

int16_t Minmax::max(p4::Game_P4& game, uint8_t _depth)
{
    if(_depth == 0 || game.is_finished())
        return evaluate(game);

    int16_t max = std::numeric_limits<int16_t>::min();

    for(int m = 0; m < Board::N_COLUMN; ++m)
    {
        game.play(m);

        int16_t val = min(game, _depth - 1);
        if(val > max)
            max = val;

        game.unplay(m);
    }
    return max;
}

int16_t Minmax::evaluate(const p4::Game_P4& game)
{
    int16_t score          = 0;
    const color_e ai_color = player.get_color();
    const auto& b          = game.get_board().get_board();

    for(auto c : vector<color_e>{color_e::red, color_e::yellow})
    {
        const array<Cell, 4> v3{Cell(), {c}, {c}, {c}};
        const array<Cell, 4> v2{Cell(), Cell(), {c}, {c}};

        for(int x = 0; x < Board::N_COLUMN; ++x)
        {
            // Start from bottom
            // for(int y = 0; y < Board::N_ROW - 3; ++y)
            for(int y = Board::N_ROW - 4; y <= 0; --y)
            {
                array<Cell, 4> test;
                std::copy(b[x].begin() + y, b[x].begin() + y + 4, test.begin());

                cout << "test:";
                for(auto i : test)
                	cout << i;
                cout << endl;

                if(v3 == test)
                {
                    if(c == ai_color)
                        score += ALIGN3;
                    else
                        score -= ALIGN3;
                    break;
                }
                else if(v2 == test)
                {
                    if(c == ai_color)
                        score += ALIGN2;
                    else
                        score -= ALIGN2;
                    break;
                }
            }
        }
    }
    return score;
}
