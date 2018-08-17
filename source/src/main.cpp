
#include "board.h"
#include "view_ascii.h"

using namespace p4;
using namespace view;

// https://gist.github.com/application2000/73fd6f4bf1be6600a2cf9f56315a2d91

int main(int argc, char* argv[])
{
    Board board;

    View_ASCII view(board);

    view.display();

    auto piece = std::make_unique<Token>(Token::color_e::red);

    board.play(0, std::move(piece));
    view.display();

    piece = std::make_unique<Token>(Token::color_e::yellow);
    board.play(0, std::move(piece));
    view.display();
}
