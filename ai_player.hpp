#pragma once

#include <string>
#include <memory>
#include <random>
#include "player.hpp"
#include "stone.hpp"

class GameIO;
class Position;

class AIPlayer final: public Player {
public:
    AIPlayer(const std::string& name, StoneColor color, std::shared_ptr<GameIO> gameIO, unsigned boardSize);

    Position getPosition() const override;
private:
    const std::unique_ptr<std::random_device> rd;
};
