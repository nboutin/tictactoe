
#pragma once

#include "board.h"

namespace view
{
class View_ASCII
{
public:
	View_ASCII(const p4::Board& board);

	void display();

private:

	std::string cell_to_print(const p4::Cell& cell);

	const p4::Board& board;
};
}
