#pragma once

#include <vector>
#include <string_view>

class GameIO {
public:
    using fields_t = std::vector<std::vector<int>>;
    void showError(std::string_view msg) const;
    void showString(std::string_view msg) const;
    std::string getLine(std::string_view prompt);
};
