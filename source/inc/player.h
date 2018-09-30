
#pragma once

#include "token.h"

#include <string>

namespace tictactoe
{
class Player
{
    friend bool operator==(const Player& lhs, const Player& rhs);

public:
    Player(const std::string& name, token_e token) : name(name), token(token) {}

    token_e get_token() const { return token; }

    void set_name(const std::string& _name) { name = _name; }
    std::string get_name() const { return name; }
    void set_ai() { ai = true; }
    bool is_ai() const { return ai; }

private:
    std::string name;
    token_e token;
    bool ai = false;
};

inline bool operator==(const Player& lhs, const Player& rhs)
{
    return ((lhs.name == rhs.name) && (lhs.token == rhs.token));
}
}
