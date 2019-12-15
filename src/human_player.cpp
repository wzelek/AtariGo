#include "human_player.hpp"
#include "game_io.hpp"
#include "position.hpp"
#include <sstream>
#include <string_view>
#include <iostream>
#include <limits>

namespace
{
    void clearStringStream(std::stringstream &ss)
    {
        ss.str("");
        ss.clear();
    }
}

HumanPlayer::HumanPlayer(const std::string& name_, StoneColor color_, std::shared_ptr<GameIO> gameIO_, unsigned boardSize_)
    : Player{name_, color_, gameIO_, boardSize_} {}

Position HumanPlayer::getPosition() const 
{
    std::stringstream ss;
    char col;
    unsigned int row;

    for(;;) {
        auto moveStr = gameIO->getLine("Player " + name + ", plays " + (color == StoneColor::Black ? "Black": "White") + ": ");
        ss.str(moveStr);
        ss >> col >> row;

        if (!ss) {
            gameIO->showError("Incorrect move format! Try again!\n");
            clearStringStream(ss);
            continue;
        }

        auto position = Position::make(col, row, boardSize);
        if(position) {
            return *position;
        }
        else {
            gameIO->showError("Incorrect position! Try again!\n");
            clearStringStream(ss);
            continue;
        }
    }
}

