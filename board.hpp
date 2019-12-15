#pragma once

#include <vector>
#include <cstddef>
#include <optional>
#include "stone.hpp"
#include <algorithm>

class Position;
class BoardDisplayer;

class Board {
public:
    Board(unsigned boardSize);

    // non copyable
    Board(const Board&) = delete;
    Board& operator=(const Board&) = delete;

    bool dropStone(Stone&& stone, const Position& position);
    void accept(BoardDisplayer& displayer) const;
    bool is_full() const;
private:
    using fields_t = std::vector<std::vector<std::optional<Stone>>>;
    fields_t fields;
    const unsigned boardSize;
};
