
#include "cell.h"

using namespace connect4;
using namespace std;

Cell::Cell(color_e color) { add_token(color); }

void Cell::add_token(color_e _color)
{
    empty = false;
    color = _color;
}

void Cell::remove_token() { empty = true; }
