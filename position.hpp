#pragma once

#include <utility>
#include <optional>

class Position {
public:
    static std::optional<const Position>  make(char col, unsigned row, unsigned boardSize);
    std::pair<unsigned, unsigned> indexes() const;
private:
    Position(char col, unsigned row);
    const unsigned row;
    const unsigned col;
};
