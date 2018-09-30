
#pragma once

#include <string>

namespace nim
{
class Player
{
    friend bool operator==(const Player& lhs, const Player& rhs);

public:
    Player(const std::string& name) : name(name) {}

    void set_name(const std::string& _name) { name = _name; }
    std::string get_name() const { return name; }

    void set_ai() { ai = true; }
    bool is_ai() const { return ai; }

private:
    std::string name;
    bool ai = false;
};

inline bool operator==(const Player& lhs, const Player& rhs) { return (lhs.name == rhs.name); }
}
