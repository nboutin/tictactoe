
#pragma once

#include "board.h"
#include "player.h"
#include "token.h"

#include <optional>
#include <vector>

namespace tictactoe
{
enum class player_e { p1, p2 };

class TicTacToe
{
public:
    static constexpr auto LIGNE = 3;
    using move                  = std::optional<Board::Point>;

    TicTacToe();

    bool play(Board::Point p);
    void undo();
    bool is_finished() const { return finished; }

    const Board& get_board() const { return board; }
    const Player& get_current_player() const { return *current_player; }
    const Player& get_player(player_e p) const;

    Player get_winner_player() const { return *winner_player; }
    const std::vector<move>& get_history() const { return moves; }

    void set_ai(player_e p);
    void set_name(player_e p, const std::string& name);

private:
    bool compute_ending();
    void compute_next_player();

    std::optional<token_e> is_winner_diagonal(const Board::grid_t& g) const;
    std::optional<token_e> is_winner_vertical(const Board::grid_t& g) const;
    std::optional<token_e> is_winner_horizontal(const Board::grid_t& g) const;

    bool finished = false;
    Board board;

    Player p1;
    Player p2;
    Player* current_player = nullptr;
    Player* winner_player  = nullptr;

    std::vector<move> moves;
};
}
