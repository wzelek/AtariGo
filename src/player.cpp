#include "player.hpp"
#include "game_io.hpp"
#include <limits>
#include <string_view>

Player::Player(const std::string& name_, StoneColor color_, std::shared_ptr<GameIO> gameIO_, unsigned boardSize_)
    : name{name_}, color{color_}, gameIO{gameIO_}, boardSize{boardSize_} {}

Player::~Player() = default;

StoneColor Player::getColor() const {
    return color;
}

std::string_view Player::getName() const {
    return name;
}

