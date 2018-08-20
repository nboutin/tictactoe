
#pragma once

#include <iostream>

#include "color.h"

namespace p4
{
class Cell
{
    friend bool operator==(const Cell& lhs, const Cell& rhs);
    friend std::ostream& operator<<(std::ostream& oss, const Cell& c);

public:
    Cell() = default;
    Cell(color_e color);

    bool is_empty() const { return empty; }

    void add_token(color_e color);
    void remove_token();

    color_e get_color() const { return color; }

private:
    // TODO use optionnal for empty & color
    bool empty    = true;
    color_e color = color_e::red;
};

inline bool operator==(const Cell& lhs, const Cell& rhs)
{
    return ((lhs.empty == rhs.empty) && (lhs.color == rhs.color));
}

inline std::ostream& operator<<(std::ostream& oss, const Cell& c)
{
    if(c.empty)
        oss << '-';
    else if(c.color == color_e::red)
        oss << 'r';
    else
        oss << 'y';
    return oss;
}
}
