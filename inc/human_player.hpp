#pragma once

#include <string>
#include <memory>
#include "player.hpp"
#include "stone.hpp"

class GameIO;
class Position;

class HumanPlayer final: public Player {
public:
    HumanPlayer(const std::string& name, StoneColor color, std::shared_ptr<GameIO> gameIO, unsigned boardSize);

    Position getPosition() const override;
};
