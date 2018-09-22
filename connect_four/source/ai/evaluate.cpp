
#include "evaluate.h"
#include "../inc/connect4.h"
#include <algorithm>

using namespace connect4;
using namespace std;

namespace ai
{
int16_t evaluate(const connect4::Board::grid_t& grid, const color_e win_color)
{
    auto evalv = evaluate_vertical(grid, win_color);
    auto evalh = evaluate_horizontal(grid, win_color);
    auto evald = evaluate_diagonal(grid, win_color);

    //    cout << "v:" << evalv << ", h:" << evalh << ", d:" << evald << endl;
    return evalv + evalh + evald;

    //    return evaluate_vertical(grid, win_color) + evaluate_horizontal(grid, win_color)
    //           + evaluate_diagonal(grid, win_color);
}

int16_t evaluate_vertical(const connect4::Board::grid_t& grid, const color_e win_color)
{
    int16_t score = 0;

    for(auto c : array<const color_e, 2>{color_e::red, color_e::yellow})
    {
        const array<Cell, 4> line{c, c, c, c};

        for(int x = 0; x < Board::N_COLUMN; ++x)
        {
            // Start from bottom
            // FIXME use constant
            for(int y = Board::N_ROW - 4; y >= 0; --y)
            {
                array<Cell, 4> test;
                std::copy(grid[x].begin() + y, grid[x].begin() + y + 4, test.begin());

                if(line == test)
                    return (c == win_color) ? WIN_POINT : LOOSE_POINT;
            }
        }
    }
    return score;
}

int16_t evaluate_horizontal(const connect4::Board::grid_t& grid, const color_e win_color)
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
int16_t evaluate_diagonal(const connect4::Board::grid_t& grid, const connect4::color_e win_color)
{
    int16_t score = 0;

    // Diag '\'
    for(int y = 0; y <= Board::N_ROW - Connect4::LIGNE; ++y)
    {
        for(int x = 0; x <= Board::N_COLUMN - Connect4::LIGNE; ++x)
        {
            for(const auto c : array<color_e, 2>{color_e::red, color_e::yellow})
            {
                const array<Cell, 4> v4{c, c, c, c};
                array<Cell, 4> test;

                for(int i = 0; i < Connect4::LIGNE; ++i)
                    test[i] = grid[x + i][y + i];

                if(test == v4)
                    return (c == win_color) ? WIN_POINT : LOOSE_POINT;
            }
        }
    }

    // Diag '/'
    //  0123456
    // 0---r--r
    // 1--r--r-
    // 2-r-rr-r
    // 3r-rr-r-
    // 4-r--r--
    // 5r--r---
    for(int y = 0; y <= Board::N_ROW - Connect4::LIGNE; ++y)
    {
        for(int x = 3; x < Board::N_COLUMN; ++x)
        {
            for(const auto c : array<color_e, 2>{color_e::red, color_e::yellow})
            {
                const array<Cell, 4> v4{c, c, c, c};
                array<Cell, 4> test;

                for(int i = 0; i < Connect4::LIGNE; ++i)
                    test[i] = grid[x - i][y + i];

                if(test == v4)
                    return (c == win_color) ? WIN_POINT : LOOSE_POINT;
            }
        }
    }

    return score;
}
}
