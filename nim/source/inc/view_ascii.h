
#pragma once

#include "board.h"
#include "player.h"
#include "nim.h"

#include <optional>
#include <string>
#include <vector>

namespace nim
{
class View_ASCII
{
public:
    View_ASCII(const Board::grid_t& g);

    void display(bool clear = true);
    void message(const std::string& msg);

    void set_history(const Nim::moves_t& h) { history = h; }
    void set_current_player(const Player& p) { current_player = p; }

private:
    void print_grid(const Board::grid_t& g) const;
    void print_history() const;

    const Board::grid_t& grid;
    Player current_player;

    std::vector<std::string> msgs;
    Nim::moves_t history;
};
}
