
#include "cell.h"

using namespace p4;

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
