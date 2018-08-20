
#include "cell.h"

#include <memory>

using namespace p4;
using namespace std;

Cell::Cell(color_e color) { add_token(color); }

// Cell::Cell(unique_ptr<Token> token) { add_token(move(token)); }

// Cell::Cell(const Cell& c) : empty(c.empty), token(new Token(*c.token)) {}

// Cell& Cell::operator=(const Cell& c)
//{
//    empty = c.empty;
//    token = move(c.token);
//    return *this;
//}

void Cell::add_token(color_e _color)
{
    empty = false;
    color = _color;
}

void Cell::remove_token() { empty = true; }
