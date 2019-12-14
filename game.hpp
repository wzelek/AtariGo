#pragma once

#include <memory>
#include "player_creator.hpp"

class Player;
class Board;
class BoardDisplayer;
class GameIO;

class Game {
public:
    Game(PlayerCreator::player_pair_t&& player_pair, std::shared_ptr<BoardDisplayer> displayer, std::shared_ptr<GameIO> gameIO, unsigned boardSize);
    ~Game();

    // non copyable
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;

    void run();
private:
    std::unique_ptr<Player> current_player;
    std::unique_ptr<Player> next_player;
    const std::unique_ptr<Board> board;
    const std::shared_ptr<BoardDisplayer> displayer;
    const std::shared_ptr<GameIO> gameIO;
};
