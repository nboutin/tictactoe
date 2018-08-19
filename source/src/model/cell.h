
#pragma once

#include <memory>

#include "token.h"

namespace p4
{
class Cell
{
    friend bool operator==(const Cell& lhs, const Cell& rhs);

public:
    Cell() = default;
    Cell(std::unique_ptr<Token> token);
    Cell(const Cell& c);
    Cell& operator=(const Cell& c);

    bool is_empty() const { return empty; }

    void add_token(std::unique_ptr<Token> token);
    void remove_token();

    // TODO use optional ?
    Token get_token() const { return *token; }

private:
    bool empty = true;
    std::unique_ptr<Token> token;
};

inline bool operator==(const Cell& lhs, const Cell& rhs)
{
    return ((lhs.empty == rhs.empty) && (!lhs.empty) ?
                (lhs.token->get_color() == rhs.token->get_color()) :
                true);
}
}
