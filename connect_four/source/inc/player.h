
#pragma once

#include "color.h"

#include <string>

namespace connect4
{
class Player
{
    friend bool operator==(const Player& lhs, const Player& rhs);

public:
    Player(const std::string& name, color_e color) : name(name), color(color) {}

    color_e get_color() const { return color; }

    void set_name(const std::string& _name) { name = _name; }
    std::string get_name() const { return name; }

    void set_ai() { ai = true; }
    bool is_ai() const { return ai; }

private:
    std::string name;
    color_e color;
    bool ai = false;
};

inline bool operator==(const Player& lhs, const Player& rhs)
{
    return ((lhs.name == rhs.name) && (lhs.color == rhs.color));
}
}
