#include "position.hpp"

Position::Position(char col_, unsigned row_)
    : row{row_ - 1}, col{static_cast<unsigned>(col_ - 'a')} {
}

std::pair<unsigned, unsigned> Position::indexes() const {
    return {row, col};
}

std::optional<const Position> Position::make(char col, unsigned row, unsigned boardSize) {
    if((col >= 'a') && (col < static_cast<char>('a' + boardSize)) && (row > 0) && (row <= boardSize)) {
        return {{col, row}};
    }
    return {};
}
