
#pragma once

#include "board.h"

#include "rang.h"

#include <iostream>

namespace connect4
{
inline std::ostream& operator<<(std::ostream& os, const Board::cell_t& cell)
{
    if(!cell)
    {
        return os << rang::bg::blue << " " << rang::style::reset;
    }
    else
    {
        if(cell.value() == color_e::red)
        {
            return os << rang::bg::red << rang::fg::black << "O" << rang::style::reset;
        }
        else
        {
            return os << rang::bg::yellow << rang::fg::black << "O" << rang::style::reset;
        }
    }

    return os;
}
