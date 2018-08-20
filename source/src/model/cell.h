
#pragma once

#include <memory>

#include "color.h"

namespace p4
{
class Cell
{
    friend bool operator==(const Cell& lhs, const Cell& rhs);

public:
    Cell() = default;
    Cell(color_e color);
    //    Cell(std::unique_ptr<Token> token);
    //    Cell(const Cell& c);
    //    Cell& operator=(const Cell& c);

    bool is_empty() const { return empty; }

    void add_token(color_e color);
    void remove_token();

    color_e get_color() const { return color; }

    // TODO use optional ?
    //    Token get_token() const { return *token; }

private:
    // TODO use optionnal for empty & color
    bool empty    = true;
    color_e color = color_e::red;
    //    std::unique_ptr<Token> token;
};

inline bool operator==(const Cell& lhs, const Cell& rhs)
{
    return ((lhs.empty == rhs.empty) && (!lhs.empty) ? (lhs.color == rhs.color) : true);
}
}    // namespace p4
