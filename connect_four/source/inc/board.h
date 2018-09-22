#pragma once

#include "color.h"

#include <array>
#include <optional>

namespace connect4
{
class Board
{
public:
    static constexpr auto N_COLUMN = 7;    // X
    static constexpr auto N_ROW    = 6;    // Y

    using cell_t = std::optional<color_e>;
    using grid_t = std::array<std::array<cell_t, N_ROW>, N_COLUMN>;

    const grid_t& get_grid() const { return grid; }

    bool play(uint8_t x, color_e color);
    void unplay(uint8_t x);

private:
    std::optional<uint8_t> find_free_row(uint8_t x);

    //   0 1 2 3 4 5 6
    // 0 - - - - - - -
    // 1 - - - - - - -
    // 2 - - - - - - -
    // 3 - - - - - - -
    // 4 - - - - - - -
    // 5 - - - - - - -
    grid_t grid;
};
}
