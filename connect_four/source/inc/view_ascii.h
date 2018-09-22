
#pragma once

#include <string>
#include <vector>

#include "player.h"
#include "board.h"

namespace view
{
class View_ASCII
{
public:
    View_ASCII(const connect4::Board& board);

    void display(bool clear = true);
    void message(const std::string& msg);

    void set_history(const std::vector<std::optional<uint8_t>>& h) { history = h; }
    void set_current_player(const connect4::Player& p) { current_player = p; }

private:
    void print_grid(const connect4::Board::grid_t& g) const;
    void print_history() const;

    const connect4::Board& board;
    std::vector<std::string> msgs;
    std::vector<std::optional<uint8_t>> history;

    connect4::Player current_player;
};
}
