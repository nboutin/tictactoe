
#pragma once

#include "board.h"
#include "player.h"

#include <optional>
#include <vector>

namespace nim
{
enum class player_e { p1, p2 };

class Nim
{
public:
    using moves_t = std::vector<std::optional<Board::move_t>>;

    Nim();
    bool play(Board::move_t m);
    void undo();

    bool is_finished() const { return finished; };

    const Board& get_board() const { return board; }

    const Player& get_current_player() const { return *current_player; }
    const Player& get_player(player_e p);
    const Player* get_winner_player() const { return winner_player; }
    void set_ai(player_e p);
    void set_name(player_e p, const std::string& name);

    moves_t get_history() const { return moves; }

private:
    void next_player();
    bool compute_ending();

    //    Board::cell_t is_winner_vertical(const Board::grid_t& b) const;

    Player p1;
    Player p2;
    Player* current_player = nullptr;
    Player* winner_player  = nullptr;

    Board board;
    bool finished = false;
    moves_t moves;
};
}
