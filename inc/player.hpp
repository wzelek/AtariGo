#pragma once

#include <string>
#include <string_view>
#include <memory>
#include "stone.hpp"

class GameIO;
class Position;

class Player {
public:
    Player(const std::string& name, StoneColor color, std::shared_ptr<GameIO> displayer, unsigned boardSize);
    virtual ~Player();

    // noncopyable
    Player(const Player&) = delete;
    Player& operator=(const Player&) = delete;

    [[nodiscard]] virtual Position getPosition() const = 0;
    virtual StoneColor getColor() const;
    virtual std::string_view getName() const;
protected:
    const std::string name;
    StoneColor color;
    std::shared_ptr<GameIO> gameIO;
    const unsigned boardSize;
};
