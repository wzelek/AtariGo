#include "board.hpp"
#include "position.hpp"
#include "board_displayer.hpp"

Board::Board(unsigned boardSize_)
    : fields{}, boardSize{boardSize_}
{
    fields.reserve(boardSize);
    for(auto row = 0U; row < boardSize; ++row) {
        fields.emplace_back(boardSize);
    }
}

bool Board::dropStone(Stone&& stone, const Position& position) {
    // C++11 >= C++17
    /*
    unsigned row;
    unsigned col;
    std::tie(row, col) = position.indexes();
    */
    auto [row, col] = position.indexes();
    auto& field = fields[row][col];
    return field.has_value() ? false: (static_cast<void>(field.emplace(stone.color())), true);
}

void Board::accept(BoardDisplayer& displayer) const {
    typename BoardDisplayer::fields_t table;
    table.resize(boardSize, BoardDisplayer::fields_t::value_type(boardSize));
    for(auto row = 0U; row < boardSize; ++row) {
        for(auto col = 0U; col < boardSize; ++col) {
            auto& field = fields[row][col];
            if(field) {
                table[row][col] = field->color() == StoneColor::Black ? 1: 2;
            } else {
                table[row][col] = 0;
            }
        }
    }
    displayer.updateBoard(std::move(table));
}

bool Board::is_full() const {
    static const unsigned FieldsCount = boardSize * boardSize;
    unsigned counter = 0;
    for(auto& row: fields) {
        counter += std::count_if(row.cbegin(), row.cend(), [](auto& field) {
            return field.has_value();
        });
    }
    return counter == FieldsCount;
}
