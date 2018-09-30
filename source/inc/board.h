#pragma once

#include "token.h"

#include <array>
#include <optional>

namespace tictactoe
{
class Board
{
public:
    static constexpr auto N_COLUMN = 3;    // X
    static constexpr auto N_ROW    = 3;    // Y

    using cell_t = std::optional<token_e>;
    using grid_t = std::array<std::array<cell_t, N_ROW>, N_COLUMN>;

    struct Point
    {
        uint16_t x;
        uint16_t y;
    };

    const grid_t& get_grid() const { return grid; }

    bool play(Point p, token_e token);
    void undo(Point p);

private:
    //   0 1 2
    // 0 - - -
    // 1 - - -
    // 2 - - -
    grid_t grid;
};
}
