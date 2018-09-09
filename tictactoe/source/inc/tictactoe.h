
#include "board.h"
#include "player.h"

#include <vector>

namespace tictactoe
{
class TicTacToe
{
public:
    TicTacToe();

    bool play(Board::Point p);
    void undo();

    bool is_finished() const { return finished; }

private:
    bool compute_ending();
    void compute_next_player();

    bool is_winner_horizontally(const Board::grid_t& g) const;

    bool finished = false;
    Board board;

    Player p1;
    Player p2;
    Player* current_player = nullptr;

    using move = std::optional<Board::Point>;
    std::vector<move> moves;
};
}
