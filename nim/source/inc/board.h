#pragma once

#include <cstdint>

namespace nim
{
class Board
{
public:
    using move_t = uint8_t;
    using grid_t = int8_t;

    static constexpr grid_t TOKEN_COUNT = 15;
    static constexpr grid_t TOKEN_MIN = 0;
    static constexpr move_t MOVE_MIN = 1;
    static constexpr move_t MOVE_MAX = 3;

    const grid_t& get_tokens() const { return tokens; }

    bool play(move_t m);
    void unplay(move_t m);

private:
    grid_t tokens = TOKEN_COUNT;
};
}
