
#include "cell.h"

#include <memory>

using namespace p4;
using namespace std;

//Cell::Cell(const Cell& c) : empty(c.empty), token(make_unique<Token>(c.token)) {}

void Cell::add_token(std::unique_ptr<Token> _token)
{
    empty = false;
    token = std::move(_token);
}

void Cell::remove_token()
{
    empty = true;
    token.reset();
}
