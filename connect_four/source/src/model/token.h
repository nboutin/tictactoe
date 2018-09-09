
#pragma once

namespace p4
{
class Token
{
public:
    enum class color_e { red, yellow };

    Token(color_e color) : color(color) {}

    color_e get_color() const { return color; }

private:
    color_e color;
};
}
