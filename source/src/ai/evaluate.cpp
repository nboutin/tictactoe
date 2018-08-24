
#include "evaluate.h"
#include "game_p4.h"

using namespace p4;
using namespace std;

namespace ai
{
int16_t evaluate(const p4::Board::grid_t& grid, const color_e win_color)
{
    return evaluate_vertical(grid, win_color) + evaluate_horizontal(grid, win_color)
           + evaluate_diagonal(grid, win_color);
}

int16_t evaluate_vertical(const p4::Board::grid_t& grid, const color_e win_color)
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
                    return (c == win_color) ? WIN_POINT : LOOSE_POINT;

                // TODO use break;
                //                else if(v3 == test)
                //                    score += (c == win_color) ? ALIGN3 : -ALIGN3;
                //                else if(v2 == test)
                //                    score += (c == win_color) ? ALIGN2 : -ALIGN2;
            }
        }
    }
    return score;
}

int16_t evaluate_horizontal(const p4::Board::grid_t& grid, const color_e win_color)
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

                if(test == v4)
                    return (c == win_color) ? WIN_POINT : LOOSE_POINT;
            }
        }
    }
    return score;
}

// TODO search should start at the bottom of the grid y = 6;
int16_t evaluate_diagonal(const p4::Board::grid_t& grid, const p4::color_e win_color)
{
    int16_t score = 0;

    // Diag '\'
    for(int y = 0; y <= Board::N_ROW - LIGNE; ++y)
    {
        for(int x = 0; x <= Board::N_COLUMN - LIGNE; ++x)
        {
            for(const auto c : array<color_e, 2>{color_e::red, color_e::yellow})
            {
                const array<Cell, 4> v4{c, c, c, c};
                array<Cell, 4> test;

                for(int i = 0; i < LIGNE; ++i)
                    test[i] = grid[x + i][y + i];

                if(test == v4)
                    return (c == win_color) ? WIN_POINT : LOOSE_POINT;
            }
        }
    }

    // Diag '/'
    for(int y = 0; y <= Board::N_ROW - LIGNE; ++y)
    {
        for(int x = 3; x < Board::N_ROW; ++x)
        {
            for(const auto c : array<color_e, 2>{color_e::red, color_e::yellow})
            {
                const array<Cell, 4> v4{c, c, c, c};
                array<Cell, 4> test;

                for(int i = 0; i < LIGNE; ++i)
                    test[i] = grid[x - i][y + i];

                if(test == v4)
                    return (c == win_color) ? WIN_POINT : LOOSE_POINT;
            }
        }
    }

    return score;
}
}
