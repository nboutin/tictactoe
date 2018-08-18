
#pragma once

#include <string>
#include <vector>

#include "board.h"

namespace view
{
class View_ASCII
{
public:
    View_ASCII(const p4::Board& board);

    void display();

    void message(const std::string& msg);

private:
    std::string cell_to_print(const p4::Cell& cell) const;

    const p4::Board& board;
    std::vector<std::string> msgs;
};
}
