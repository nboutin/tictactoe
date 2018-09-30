
#include "connect4.h"
using namespace connect4;
using namespace std;

Connect4::Connect4()
    : p1("Player 1", color_e::red), p2("Player 2", color_e::yellow), current_player(&p1)
{}

bool Connect4::play(const move_t x)
{
    if(finished)
    {
        moves.push_back({});    // bad move
        return false;
    }

    if(!board.play(x, current_player->get_color()))
    {
        moves.push_back({});    // bad move
        return false;
    }

    moves.push_back({x});
    compute_ending();
    compute_next_player();

    return true;
}

void Connect4::undo()
{
    auto last_move = moves.back();
    moves.pop_back();

    if(last_move)
    {
        board.unplay(last_move.value());
        compute_next_player();
    }
    finished = false;
}

/// \brief Decide if a game is finished
/// \return true if finished otherwise false
///
/// A game is finished, if someone win, if no more token can be added to the board (draw)
bool Connect4::compute_ending()
{
    // Look for free cell
    auto space_available = (moves.size() < Board::N_COLUMN * Board::N_ROW);

    const auto& g  = board.get_grid();
    auto is_winner = is_winner_horizontal(g);
    if(is_winner)
    {
        winner_player = (is_winner.value() == p1.get_color()) ? &p1 : &p2;
    }
    else if((is_winner = is_winner_vertical(g)))
    {
        winner_player = (is_winner.value() == p1.get_color()) ? &p1 : &p2;
    }
    else if((is_winner = is_winner_diagonal(g)))
    {
        winner_player = (is_winner.value() == p1.get_color()) ? &p1 : &p2;
    }

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

const Player& Connect4::get_player(const player_e p)
{
    switch(p)
    {
    case player_e::p1: return p1;
    case player_e::p2: return p2;
    }
    return p1;
}

void Connect4::set_ai(const player_e p)
{
    switch(p)
    {
    case player_e::p1: p1.set_ai(); break;
    case player_e::p2: p2.set_ai(); break;
    }
}

void Connect4::set_name(const player_e p, const std::string& name)
{
    switch(p)
    {
    case player_e::p1: p1.set_name(name); break;
    case player_e::p2: p2.set_name(name); break;
    }
}

Board::cell_t Connect4::is_winner_vertical(const Board::grid_t& g) const
{
    for(int y = Board::N_ROW - LIGNE; y >= 0; --y)
    {
        for(int x = 0; x < Board::N_COLUMN; ++x)
        {
            for(const auto c : {color_e::red, color_e::yellow})
            {
                std::array<Board::cell_t, LIGNE> line;
                line.fill(c);

                if(std::equal(g[x].begin() + y, g[x].begin() + y + LIGNE, line.begin(), line.end()))
                    return {c};
            }
        }
    }
    return {};
}

Board::cell_t Connect4::is_winner_horizontal(const Board::grid_t& g) const
{
    for(int y = Board::N_ROW - 1; y >= 0; --y)
    {
        for(int x = 0; x <= Board::N_COLUMN - LIGNE; ++x)
        {
            std::array<Board::cell_t, LIGNE> test;
            for(int xp = 0; xp < LIGNE; ++xp)
            {
                test[xp] = g[xp + x][y];

                for(const auto c : {color_e::red, color_e::yellow})
                {
                    std::array<Board::cell_t, LIGNE> line;
                    line.fill(c);

                    if(std::equal(test.begin(), test.end(), line.begin(), line.end()))
                        return {c};
                }
            }
        }
    }
    return {};
}

Board::cell_t Connect4::is_winner_diagonal(const Board::grid_t& g) const
{
    auto win = is_winner_diagonal1(g);

    if(win)
        return win;

    return is_winner_diagonal2(g);
}

Board::cell_t Connect4::is_winner_diagonal1(const Board::grid_t& g) const
{
    // Diag '\'
    for(int y = 0; y <= Board::N_ROW - LIGNE; ++y)
    {
        for(int x = 0; x <= Board::N_COLUMN - LIGNE; ++x)
        {
            std::array<Board::cell_t, LIGNE> test;
            for(int i = 0; i < Connect4::LIGNE; ++i)
            {
                test[i] = g[x + i][y + i];

                for(const auto c : {color_e::red, color_e::yellow})
                {
                    std::array<Board::cell_t, LIGNE> line;
                    line.fill(c);

                    if(std::equal(test.begin(), test.end(), line.begin(), line.end()))
                        return {c};
                }
            }
        }
    }
    return {};
}

Board::cell_t Connect4::is_winner_diagonal2(const Board::grid_t& g) const
{
    for(int y = 0; y <= Board::N_ROW - LIGNE; ++y)
    {
        for(int x = 3; x < Board::N_COLUMN; ++x)
        {
            std::array<Board::cell_t, LIGNE> test;
            for(int i = 0; i < LIGNE; ++i)
            {
                test[i] = g[x - i][y + i];
                for(const auto c : {color_e::red, color_e::yellow})
                {
                    std::array<Board::cell_t, LIGNE> line;
                    line.fill(c);

                    if(std::equal(test.begin(), test.end(), line.begin(), line.end()))
                        return {c};
                }
            }
        }
    }

    return {};
}
