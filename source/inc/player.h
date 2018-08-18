
#pragma once

#include <string>

#include "token.h"

namespace p4
{
class Player
{
    friend bool operator==(const Player& lhs, const Player& rhs);

public:
    Player(const std::string& name, Token::color_e color);
    Token::color_e get_color() const { return color; }

private:
    std::string name;
    bool is_human = true;
    Token::color_e color;
};

inline bool operator==(const Player& lhs, const Player& rhs)
{
    return (lhs.name == rhs.name && lhs.color == rhs.color);
}
}
