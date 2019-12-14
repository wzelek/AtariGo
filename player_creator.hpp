#pragma once

#include <utility>
#include <memory>

class Player;
class GameIO;

class PlayerCreator {
public:
    using player_pair_t = std::pair<std::unique_ptr<Player>, std::unique_ptr<Player>>;
    PlayerCreator(std::shared_ptr<GameIO> displayer);

    // non copyable
    PlayerCreator(const PlayerCreator&) = delete;
    PlayerCreator& operator=(const PlayerCreator&) = delete;

    player_pair_t create(unsigned boardSize);
private:
    std::shared_ptr<GameIO> gameIO;
};
