#include "game_io.hpp"
#include <iostream>

void GameIO::showError(std::string_view msg) const {
    std::cerr << msg;
}

void GameIO::showString(std::string_view msg) const {
    std::cout << msg;
}

std::string GameIO::getLine(std::string_view prompt) {
    std::string result;
    std::cout << prompt;
    getline(std::cin, result);
    return result;
}
