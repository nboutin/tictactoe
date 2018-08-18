
#include "player.h"

using namespace p4;
using namespace std;

Player::Player(const string& name, Token::color_e color) : name(name), color(color) {}

Player::Player(const Player& p)
{
    name  = p.name;
    color = p.color;
}

Player& Player::operator=(const Player& p)
{
    name  = p.name;
    color = p.color;
    return *this;
}
