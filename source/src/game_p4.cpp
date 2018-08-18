
#include "game_p4.h"

using namespace p4;
using namespace std;

Game_P4::Game_P4()
    : p1("p1", Token::color_e::red), p2("p2", Token::color_e::yellow), current_player(p1)
{}

bool Game_P4::play(uint8_t y, std::unique_ptr<Token> token)
{
    auto r = board.play(y, move(token));

    if(r)
    {
        compute_next_player();
    }

    return r;
}

void Game_P4::compute_next_player()
{
    if(current_player == p1)
        current_player = p2;
    else
        current_player = p1;
}
