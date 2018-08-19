
#include "minmax.h"

using namespace ai;
using namespace p4;
using namespace std;

uint8_t Minmax::compute(p4::Game_P4& game, uint8_t profondeur)
{
    int16_t max       = std::numeric_limits<int16_t>::min();
    uint8_t best_move = 0;

    for(int m = 0; m < Board::N_COLUMN; ++m)
    {
        auto token = make_unique<Token>(game.get_current_player().get_color());
        game.play(m, move(token));

        int16_t val = min(game, profondeur);
        if(val > max)
        {
            max       = val;
            best_move = m;
        }

        game.unplay(m);
    }

    return best_move;
}

int16_t Minmax::min(p4::Game_P4& game, uint8_t profondeur)
{
    if(profondeur == 0 || game.is_finished())
        return evaluate(game);

    int16_t min = std::numeric_limits<int16_t>::max();

    for(int m = 0; m < Board::N_COLUMN; ++m)
    {
        auto token = make_unique<Token>(game.get_current_player().get_color());
        game.play(m, move(token));

        int16_t val = max(game, profondeur - 1);
        if(val < min)
            min = val;

        game.unplay(m);
    }
    return min;
}

int16_t Minmax::max(p4::Game_P4& game, uint8_t profondeur)
{
    if(profondeur == 0 || game.is_finished())
        return evaluate(game);

    int16_t max = std::numeric_limits<int16_t>::min();

    for(int m = 0; m < Board::N_COLUMN; ++m)
    {
        auto token = make_unique<Token>(game.get_current_player().get_color());
        game.play(m, move(token));

        int16_t val = min(game, profondeur - 1);
        if(val > max)
            max = val;

        game.unplay(m);
    }
    return max;
}

int16_t Minmax::evaluate(const p4::Game_P4& game) { return 0; }
