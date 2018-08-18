
#pragma once

#include "board.h"
#include "player.h"

namespace p4
{
class Game_P4
{
public:
    Game_P4();

    bool play(uint8_t x, std::unique_ptr<Token> token);

    bool is_finished() const;

    const Board& get_board() const { return board; }
    const Player& get_current_player() const { return current_player; }

private:
    void compute_next_player();

    Player p1;
    Player p2;
    Player current_player;

    Board board;
};
}
