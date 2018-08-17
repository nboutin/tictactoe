
#pragma once

#include <array>
#include <memory>
#include <optional>

#include "cell.h"
#include "token.h"

namespace p4
{
class Board
{
public:
    static const auto N_COLUMN = 7;
    static const auto N_ROW    = 6;

    typedef std::array<std::array<Cell, N_COLUMN>, N_ROW> board_t;

    const board_t& get_board() const { return board; }

    bool play(uint8_t column, std::unique_ptr<p4::Token> token);

private:

    std::optional<uint8_t> find_free_row(uint8_t column);

    //   0 1 2 3 4 5 6
    // 0 - - - - - - -
    // 1 - - - - - - -
    //...
    // 5 - - - - - - -
    board_t board;
};
}
