
#include "nim.h"

using namespace nim;
using namespace std;

Nim::Nim() : p1("Player 1"), p2("Player 2"), current_player(&p1) {}

bool Nim::play(const Board::move_t m)
{
    if(finished)
    {
        moves.push_back({});    // bad move
        return false;
    }

    if(!board.play(m))
    {
        moves.push_back({});    // bad move
        return false;
    }

    moves.push_back({m});
    compute_ending();
    compute_next_player();

    return true;
}

void Nim::undo()
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

bool Nim::compute_ending()
{
    // The player who takes the last token loose
    finished = (board.get_tokens() == Board::TOKEN_MIN);
    return finished;
}

void Nim::compute_next_player()
{
    if(*current_player == p1)
        current_player = &p2;
    else
        current_player = &p1;
}

const Player& Nim::get_player(const player_e p)
{
    switch(p)
    {
    case player_e::p1: return p1;
    case player_e::p2: return p2;
    }
    return p1;
}

void Nim::set_ai(const player_e p)
{
    switch(p)
    {
    case player_e::p1: p1.set_ai(); break;
    case player_e::p2: p2.set_ai(); break;
    }
}

void Nim::set_name(const player_e p, const std::string& name)
{
    switch(p)
    {
    case player_e::p1: p1.set_name(name); break;
    case player_e::p2: p2.set_name(name); break;
    }
}
