
#pragma once

#include <string>
#include <vector>

#include "board.h"
#include "player.h"

namespace view
{
class View_ASCII
{
public:
    View_ASCII(const p4::Board& board);

    void display(bool clear = true);
    void message(const std::string& msg);
    void set_history(const std::vector<std::optional<uint8_t>>& h) { history = h; }

    void set_current_player(const p4::Player& p) { current_player = p; }

private:
    std::string cell_to_print(const p4::Cell& cell) const;

    const p4::Board& board;
    std::vector<std::string> msgs;
    std::vector<std::optional<uint8_t>> history;

    p4::Player current_player;
};
}
