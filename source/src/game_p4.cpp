
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

    auto is_winner = is_winner_vertically(b) || is_winner_horizontally(b);

    return !space_available || is_winner;
}

void Game_P4::compute_next_player()
{
    if(current_player == p1)
        current_player = p2;
    else
        current_player = p1;
}

bool Game_P4::is_winner_vertically(const Board::board_t& b) const
{
    // Vertically
    for(int x = 0; x < Board::N_COLUMN; ++x)
    {
        int red    = 0;
        int yellow = 0;
        for(int y = 0; y < Board::N_ROW; ++y)
        {
            const auto& cell = b[x][y];
            if(cell.is_empty())
            {
                red    = 0;
                yellow = 0;
                continue;
            }

            if(cell.get_token().get_color() == Token::color_e::red)
            {
                red++;
                yellow = 0;
            }
            else
            {
                yellow++;
                red = 0;
            }

            if(red >= 4 || yellow >= 4)
                return true;
        }
    }
    return false;
}

bool Game_P4::is_winner_horizontally(const Board::board_t& b) const { return false; }
