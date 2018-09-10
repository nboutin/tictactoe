
#pragma once

#include "board.h"
#include "player.h"

#include <vector>

namespace tictactoe
{
class TicTacToe
{
public:
    using move = std::optional<Board::Point>;

    TicTacToe();

    bool play(Board::Point p);
    void undo();

    bool is_finished() const { return finished; }

    const Board& get_board() const { return board; }
    const Player& get_current_player() const { return *current_player; }
    const std::vector<move>& get_history() const { return moves; }

private:
    bool compute_ending();
    void compute_next_player();

    bool is_winner_horizontally(const Board::grid_t& g) const;

    bool finished = false;
    Board board;

    Player p1;
    Player p2;
    Player* current_player = nullptr;

    std::vector<move> moves;
};
}
