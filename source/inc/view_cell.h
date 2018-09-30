
#pragma once

#include "board.h"
#include "token.h"

#include <iostream>

inline std::ostream& operator<<(std::ostream& os, const tictactoe::Board::cell_t& cell)
{
    if(!cell)
        return os << "-";
    else
    {
        if(cell.value() == tictactoe::token_e::cross)
            return os << "X";
        else
            return os << "O";
    }
    return os;
}
