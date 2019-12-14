#include "board_displayer.hpp"
#include <iostream>
#include <algorithm>
#include <iterator>

namespace {

void showColumnNames(unsigned boardSize) {
    int c = 'a';
    std::cout << ' ';
    for(auto i = 0U; i < boardSize; ++i) {
        std::cout.put(' ');
        std::cout.put(static_cast<char>(c++));
    }
    std::cout.put('\n');
}

void showRowSeparator(unsigned boardSize) {
    std::cout << "  ";
    std::fill_n(std::ostream_iterator<char>(std::cout, " "), boardSize, '|');
    std::cout << '\n';
}

void showRow(const BoardDisplayer::fields_t::value_type& row, std::size_t rowNumber) {
    std::cout << rowNumber + 1 << ' ';
    for(auto it = row.cbegin(); it != std::prev(row.cend()); ++it) {
        std::cout << "+XO"[*it] << '-';
    }
    std::cout << "+XO"[*(row.crbegin())] << ' ' << rowNumber + 1 << '\n';
}

} // anonymous namespace

BoardDisplayer::BoardDisplayer(unsigned boardSize_)
    : boardSize{boardSize_} {}

void BoardDisplayer::updateBoard(fields_t&& table) {
    fields = std::move(table);
}

void BoardDisplayer::showBoard() const {
    showColumnNames(boardSize);
    auto rowNumber = boardSize;
    while(rowNumber-- > 1) {
        showRow(fields[rowNumber], rowNumber);
        showRowSeparator(boardSize);
    }
    showRow(fields[0], 0);
    showColumnNames(boardSize);
}
