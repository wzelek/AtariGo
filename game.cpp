#include "game.hpp"
#include "stone.hpp"
#include "player.hpp"
#include "board.hpp"
#include "game_io.hpp"
#include "board_displayer.hpp"
#include "position.hpp"
#include <cassert>

Game::Game(PlayerCreator::player_pair_t&& player_pair, std::shared_ptr<BoardDisplayer> displayer_, std::shared_ptr<GameIO> gameIO_, unsigned boardSize)
    : board{std::make_unique<Board>(boardSize)}, displayer{displayer_}, gameIO{gameIO_}
{
    assert((player_pair.first->getColor() != player_pair.second->getColor()) && (player_pair.first->getColor() == StoneColor::Black));

    std::tie(current_player, next_player) = std::move(player_pair);
}

Game::~Game() = default;

void Game::run() {
    board->accept(*displayer);
    displayer->showBoard();
    while(! board->is_full()) {
        auto position = current_player->getPosition();
        auto stone = Stone(current_player->getColor());
        if(board->dropStone(std::move(stone), position)) {
            board->accept(*displayer);
            displayer->showBoard();
            current_player.swap(next_player);
            continue;
        }
        gameIO->showError("Illegal move! Try again!\n");
    }
}
