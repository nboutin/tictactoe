
#pragma once

#include "board.h"
#include "player.h"
#include "tictactoe.h"
#include "view_cell.h"

#include <string>
#include <vector>

namespace view
{
class View_ASCII
{
public:
    View_ASCII(const tictactoe::Board::grid_t& g);

    void display(bool clear = true);
    void message(const std::string& msg) { msgs.push_back(msg); }

    void set_history(const std::vector<tictactoe::TicTacToe::move>& _moves) { moves = _moves; }
    void set_current_player(const tictactoe::Player& p) { current_player = p; }

private:
    void print_grid(const tictactoe::Board::grid_t& g) const;
    void print_history() const;
    void print_messages();

    const tictactoe::Board::grid_t& grid;
    tictactoe::Player current_player;
    std::vector<std::string> msgs;
    std::vector<tictactoe::TicTacToe::move> moves;
};
}
