
#include "game_p4.h"

using namespace p4;
using namespace std;

Game_P4::Game_P4()
    : p1("p1", Token::color_e::red), p2("p2", Token::color_e::yellow), current_player(p1)
{}

bool Game_P4::play(uint8_t x, std::unique_ptr<Token> token)
{
    if(!board.play(x, move(token)))
        return false;

    compute_next_player();

    return true;
}

/// \brief Decide if a game is finished
/// \return true if finished otherwise false
///
/// A game is finished, if someone win, if no more token can be added to the board (draw)
bool Game_P4::is_finished() const
{
    const auto& b        = board.get_board();
    auto space_available = false;

    // Look for free cell in the highest row
    for(int x = 0; x < Board::N_COLUMN; ++x)
    {
        space_available |= b[x][0].is_empty();
    }

    return !space_available;
}

void Game_P4::compute_next_player()
{
    if(current_player == p1)
        current_player = p2;
    else
        current_player = p1;
}
