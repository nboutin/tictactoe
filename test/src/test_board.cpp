
#include <catch.hpp>

#include "board.h"

using namespace p4;

TEST_CASE("play two token", "[board]")
{
    Board b;

    auto piece = std::make_unique<Token>(Token::color_e::red);
    REQUIRE(b.play(0, std::move(piece)));

    piece = std::make_unique<Token>(Token::color_e::yellow);
    REQUIRE(b.play(0, std::move(piece)));

    const auto& bn = b.get_board();

    REQUIRE(bn[0][5].get_token().get_color() == Token::color_e::red);
    REQUIRE(bn[0][4].get_token().get_color() == Token::color_e::yellow);
    REQUIRE(bn[0][3].is_empty());
}

TEST_CASE("full column", "[board]")
{
    Board b;

    for(int i = 0; i < Board::N_ROW; ++i)
    {
        auto piece = std::make_unique<Token>(Token::color_e::red);
        REQUIRE(b.play(0, std::move(piece)));
    }
    const auto& bn = b.get_board();
    REQUIRE(bn[0][0].get_token().get_color() == Token::color_e::red);

    auto piece = std::make_unique<Token>(Token::color_e::red);
    REQUIRE_FALSE(b.play(0, std::move(piece)));
}
