
#include "connect4.h"
using namespace connect4;
using namespace std;

Connect4::Connect4()
    : p1("Player 1", color_e::red), p2("Player 2", color_e::yellow), current_player(&p1)
{}

bool Connect4::play(const uint8_t x)
{
    if(finished)
    {
        moves_history.push_back({});    // bad move
        return false;
    }

    if(!board.play(x, current_player->get_color()))
    {
        moves_history.push_back({});    // bad move
        return false;
    }

    compute_ending();

    compute_next_player();

    moves_history.push_back({x});

    return true;
}

void Connect4::undo()
{
    auto last_move = moves_history.back();
    moves_history.pop_back();

    if(last_move)
    {
        board.unplay(last_move.value());
        compute_next_player();
    }
    finished = false;
}

// TODO add check
const Player& Connect4::get_player(const uint8_t i) { return (i == 1) ? p1 : p2; }

// TODO add check
void Connect4::set_ai(const uint8_t i)
{
    if(i == 1)
        p1.set_ai();
    else
        p2.set_ai();
}

void Connect4::set_name(const uint8_t i, const std::string& name)
{
    if(i == 1)
        p1.set_name(name);
    else
        p2.set_name(name);
}

/// \brief Decide if a game is finished
/// \return true if finished otherwise false
///
/// A game is finished, if someone win, if no more token can be added to the board (draw)
bool Connect4::compute_ending()
{
    const auto& b        = board.get_grid();
    auto space_available = false;

    // Look for free cell in the highest row
    for(int x = 0; x < Board::N_COLUMN; ++x)
    {
        space_available |= b[x][0].is_empty();
    }

    auto is_winner = is_winner_vertically(b) || is_winner_horizontally(b) || is_winner_diagonal(b);

    finished = !space_available || is_winner;
    return finished;
}

void Connect4::compute_next_player()
{
    if(*current_player == p1)
        current_player = &p2;
    else
        current_player = &p1;
}

// TODO search should start at the bottom of the grid y = 6;
bool Connect4::is_winner_vertically(const Board::grid_t& b) const
{
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

            if(cell.get_color() == color_e::red)
            {
                red++;
                yellow = 0;
            }
            else
            {
                yellow++;
                red = 0;
            }

            if(red >= LIGNE || yellow >= LIGNE)
                return true;
        }
    }
    return false;
}

// TODO search should start at the bottom of the grid y = 6;
bool Connect4::is_winner_horizontally(const Board::grid_t& b) const
{
    for(int y = 0; y < Board::N_ROW; ++y)
    {
        int red    = 0;
        int yellow = 0;
        for(int x = 0; x < Board::N_COLUMN; ++x)
        {
            const auto& cell = b[x][y];
            if(cell.is_empty())
            {
                red    = 0;
                yellow = 0;
                continue;
            }

            if(cell.get_color() == color_e::red)
            {
                red++;
                yellow = 0;
            }
            else
            {
                yellow++;
                red = 0;
            }

            if(red >= LIGNE || yellow >= LIGNE)
                return true;
        }
    }
    return false;
}

// TODO search should start at the bottom of the grid y = 6;
bool Connect4::is_winner_diagonal(const Board::grid_t& b) const
{
    // Diag '\'
    for(int y = 0; y <= 2; ++y)
    {
        for(int x = 0; x <= 3; ++x)
        {
            int red    = 0;
            int yellow = 0;
            for(int i = 0; i < LIGNE; ++i)
            {
                const auto& cell = b[x + i][y + i];

                if(cell.is_empty())
                {
                    red    = 0;
                    yellow = 0;
                    continue;
                }

                if(cell.get_color() == color_e::red)
                {
                    red++;
                    yellow = 0;
                }
                else
                {
                    yellow++;
                    red = 0;
                }

                if(red >= LIGNE || yellow >= LIGNE)
                    return true;
            }
        }
    }

    // Diag '/'
    for(int y = 0; y <= 2; ++y)
    {
        for(int x = 3; x < Board::N_ROW; ++x)
        {
            int red    = 0;
            int yellow = 0;
            for(int i = 0; i < LIGNE; ++i)
            {
                const auto& cell = b[x - i][y + i];

                if(cell.is_empty())
                {
                    red    = 0;
                    yellow = 0;
                    continue;
                }

                if(cell.get_color() == color_e::red)
                {
                    red++;
                    yellow = 0;
                }
                else
                {
                    yellow++;
                    red = 0;
                }

                if(red >= LIGNE || yellow >= LIGNE)
                    return true;
            }
        }
    }
    return false;
}
