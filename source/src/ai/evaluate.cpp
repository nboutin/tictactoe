
#include "evaluate.h"

using namespace p4;
using namespace std;

namespace ai
{
int16_t evaluate(const p4::Board::grid_t& grid, color_e win_color)
{
    auto v = evaluate_vertical(grid, win_color);
    auto h = evaluate_horizontal(grid, win_color);

    cout << "eval v+h:" << v << "+" << h << endl;

    return v + h;
    //    return evaluate_vertical(game) + evaluate_horizontal(game);
}

int16_t evaluate_vertical(const p4::Board::grid_t& grid, color_e win_color)
{
    int16_t score = 0;

    for(const auto c : array<color_e, 2>{color_e::red, color_e::yellow})
    {
        const array<Cell, 4> v4{c, c, c, c};
        //        const array<Cell, 4> v3{Cell(), {c}, {c}, {c}};
        //        const array<Cell, 4> v2{Cell(), Cell(), {c}, {c}};

        for(int x = 0; x < Board::N_COLUMN; ++x)
        {
            // Start from bottom
            for(int y = Board::N_ROW - 4; y >= 0; --y)
            {
                array<Cell, 4> test;
                std::copy(grid[x].begin() + y, grid[x].begin() + y + 4, test.begin());

                if(v4 == test)
                {
                    if(c == win_color)
                        return MAX;
                    else
                        return MIN;
                }
                //                else if(v3 == test)
                //                {
                //                    if(c == ai_color)
                //                        score += ALIGN3;
                //                    else
                //                        score -= ALIGN3;
                //                    break;
                //                }
                //                else if(v2 == test)
                //                {
                //                    if(c == ai_color)
                //                        score += ALIGN2;
                //                    else
                //                        score -= ALIGN2;
                //                    break;
                //                }
            }
        }
    }
    return score;
}

int16_t evaluate_horizontal(const p4::Board::grid_t& grid, color_e win_color)
{
    int16_t score = 0;

    for(const auto c : array<color_e, 2>{color_e::red, color_e::yellow})
    {
        const array<Cell, 4> v4{c, c, c, c};

        // Start from bottom
        for(int y = Board::N_ROW - 1; y >= 0; --y)
        {
            for(int x = 0; x <= Board::N_COLUMN - 4; ++x)
            {
                array<Cell, 4> test;
                for(int xp = 0; xp < 4; ++xp)
                    test[xp] = grid[xp + x][y];

                //                cout << "xy:" << x << y << endl;
                //                for(auto i : test)
                //                    cout << i;
                //                cout << endl;

                if(test == v4)
                {
                    if(c == win_color)
                        return MAX;
                    else
                        return MIN;
                }
            }
        }
    }
    return score;
}
}
