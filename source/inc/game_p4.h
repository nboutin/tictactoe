
#pragma once

#include "board.h"
#include "player.h"

namespace p4
{
class Game_P4
{
public:
    Game_P4();

    bool play(uint8_t x);
    void unplay(uint8_t x);

    bool is_finished() const { return finished; };

    const Board& get_board() const { return board; }
    const Player& get_current_player() const { return current_player; }

    const Player& get_player(uint8_t i);
    void set_ai(uint8_t i);

private:
    void compute_next_player();
    bool compute_ending();

    bool is_winner_vertically(const Board::board_t& b) const;
    bool is_winner_horizontally(const Board::board_t& b) const;
    bool is_winner_diagonal(const Board::board_t& b) const;

    Player p1;
    Player p2;
    Player current_player;

    Board board;
    bool finished = false;
};
}
