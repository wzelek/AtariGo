#include "human_player.hpp"
#include "game_io.hpp"
#include "position.hpp"
#include <sstream>
#include <string_view>
#include <iostream>
#include <limits>

HumanPlayer::HumanPlayer(const std::string& name_, StoneColor color_, std::shared_ptr<GameIO> gameIO_, unsigned boardSize_)
    : Player{name_, color_, gameIO_, boardSize_} {}

Position HumanPlayer::getPosition() const {
    char col;
    unsigned row;
    std::stringstream ss;
    for(;;) {
        auto moveStr = gameIO->getLine("Player " + name + ", plays " + (color == StoneColor::Black ? "Black": "White") + ": ");
        ss.str(moveStr);
        ss >> col >> row;
        if(!ss) {
            ss.clear();
            ss.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            gameIO->showError("Incorrect move format! Try again!\n");
            continue;
        }
        auto position = Position::make(col, row, boardSize);
        if(position) {
            return *position;
        }
        gameIO->showError("Incorrect position! Try again!\n");
    }
}

