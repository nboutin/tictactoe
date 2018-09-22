
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
    using move = uint8_t;

    Connect4();
    bool play(move x);
    void undo();

    bool is_finished() const { return finished; };

    const Board& get_board() const { return board; }
    const Player& get_current_player() const { return *current_player; }

    const Player& get_player(player_e p);
    void set_ai(player_e p);
    void set_name(player_e p, const std::string& name);

    std::vector<std::optional<move>> get_history() const { return moves_history; }

private:
    void compute_next_player();
    bool compute_ending();

    bool is_winner_vertically(const Board::grid_t& b) const;
    bool is_winner_horizontally(const Board::grid_t& b) const;
    bool is_winner_diagonal(const Board::grid_t& b) const;

    Player p1;
    Player p2;
    Player* current_player = nullptr;

    Board board;
    bool finished = false;
    std::vector<std::optional<uint8_t>> moves_history;
};
}
