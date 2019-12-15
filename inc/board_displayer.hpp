#pragma once

#include <vector>
#include <string_view>

class BoardDisplayer {
public:
    BoardDisplayer(unsigned boardSize);
    using fields_t = std::vector<std::vector<int>>;
    void updateBoard(fields_t&& table);
    void showBoard() const;
protected:
    fields_t fields;
    const unsigned boardSize;
};
