
#include "tictactoe.h"

using namespace tictactoe;

TicTacToe::TicTacToe()
    : p1("Player 1", token_e::cross), p2("Player 2", token_e::circle), current_player(&p1)
{}

bool TicTacToe::play(const Board::Point p)
{
    if(finished)
    {
        moves.push_back({});    // bad move
        return false;
    }

    if(!board.play(p, current_player->get_token()))
    {
        moves.push_back({});    // bad move
        return false;
    }

    compute_ending();

    compute_next_player();

    moves.push_back({p});

    return true;
}

void TicTacToe::undo()
{
    auto last_move = moves.back();
    moves.pop_back();

    if(last_move)
    {
        board.undo(last_move.value());
        compute_next_player();
    }
    winner_player = nullptr;
    finished      = false;
}

/// \brief Decide if a game is finished
/// \return true if finished otherwise false
///
/// A game is finished, if someone win, if no more token can be added to the board (draw)
bool TicTacToe::compute_ending()
{
    // Look for free cell in the highest row
    auto space_available = (moves.size() < Board::N_COLUMN * Board::N_ROW);

    const auto& g = board.get_grid();

    auto is_winner = is_winner_horizontal(g);
    if(is_winner)
    {
        winner_player = (is_winner.value() == p1.get_token()) ? &p1 : &p2;
    }
    else if((is_winner = is_winner_vertical(g)))
    {
        winner_player = (is_winner.value() == p1.get_token()) ? &p1 : &p2;
    }
//    else if((is_winner = is_winner_diagonal(g)))
//    {
//        winner_player = (is_winner.value() == p1.get_token()) ? &p1 : &p2;
//    }

    finished = !space_available || is_winner;
    return finished;
}

void TicTacToe::compute_next_player()
{
    if(*current_player == p1)
        current_player = &p2;
    else
        current_player = &p1;
}

std::optional<token_e> TicTacToe::is_winner_diagonal(const Board::grid_t& g) const
{
    // Diag '\'
    for(int x = 0; x <= Board::N_COLUMN - LIGNE; ++x)
    {
        for(int y = 0; y <= Board::N_ROW - LIGNE; ++y)
        {
            for(const auto t : {token_e::cross, token_e::circle})
            {
                const std::vector<Board::cell_t> line(LIGNE, t);
                std::vector<Board::cell_t> test;

                for(int i = 0; i < LIGNE; ++i)
                    test.push_back(g[x + i][y + i]);

                if(test == line)
                    return {t};
            }
        }
    }

    // Diag '/'
    for(int x = LIGNE - 1; x < Board::N_COLUMN; ++x)
    {
        for(int y = 0; y <= Board::N_ROW - LIGNE; ++y)
        {
            for(const auto t : {token_e::cross, token_e::circle})
            {
                const std::vector<Board::cell_t> line(LIGNE, t);
                std::vector<Board::cell_t> test;

                for(int i = 0; i < LIGNE; ++i)
                    test.push_back(g[x - i][y + i]);

                if(test == line)
                    return {t};
            }
        }
    }
    return {};
}
std::optional<token_e> TicTacToe::is_winner_vertical(const Board::grid_t& g) const
{
    for(int x = 0; x < Board::N_COLUMN; ++x)
    {
        std::vector<Board::cell_t> test;
        std::copy(g[x].begin(), g[x].end(), test.begin());

        for(auto t : {token_e::cross, token_e::circle})
        {
            const std::vector<Board::cell_t> line(LIGNE, {t});

            if(test == line)
                return {t};
        }
    }
    return {};
}

std::optional<token_e> TicTacToe::is_winner_horizontal(const Board::grid_t& g) const
{
    for(int y = 0; y < Board::N_ROW; ++y)
    {
        std::vector<Board::cell_t> test;
        for(int x = 0; x < Board::N_COLUMN; ++x)
            test.push_back(g[x][y]);

        for(auto t : {token_e::cross, token_e::circle})
        {
            const std::vector<Board::cell_t> line(LIGNE, {t});

            if(test == line)
                return {t};
        }
    }
    return {};
}
