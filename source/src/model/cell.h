
#pragma once

#include <memory>

#include "token.h"

namespace p4
{
class Cell
{
public:
    bool is_empty() const { return empty; }

    void add_token(std::unique_ptr<Token> token);
    void remove_token();

    Token get_token() const { return *token; }

private:
    bool empty = true;
    std::unique_ptr<Token> token;
};
}
