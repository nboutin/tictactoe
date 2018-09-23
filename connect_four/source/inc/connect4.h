
#pragma once

#include <vector>

#include "board.h"
#include "player.h"

namespace connect4
{
enum class player_e { p1, p2 };

class Connect4
{
public:
    static constexpr auto LIGNE = 4;
    using move_t                = uint8_t;
    using moves_t               = std::vector<std::optional<move_t>>;

    Connect4();
    bool play(move_t x);
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
    void compute_next_player();
    bool compute_ending();

    Board::cell_t is_winner_vertical(const Board::grid_t& b) const;
    Board::cell_t is_winner_horizontal(const Board::grid_t& b) const;
    Board::cell_t is_winner_diagonal(const Board::grid_t& b) const;
    Board::cell_t is_winner_diagonal1(const Board::grid_t& b) const;
    Board::cell_t is_winner_diagonal2(const Board::grid_t& b) const;

    Player p1;
    Player p2;
    Player* current_player = nullptr;
    Player* winner_player  = nullptr;

    Board board;
    bool finished = false;
    moves_t moves;
};
}
