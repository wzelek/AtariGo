#include "game.hpp"
#include "player.hpp"
#include "player_creator.hpp"
#include "board_displayer.hpp"
#include "game_io.hpp"
#include "settings.hpp"
#include <memory>

int main() {
    auto displayer = std::make_shared<BoardDisplayer>(BoardSize);
    auto console = std::make_shared<GameIO>();
    PlayerCreator creator{console};
    auto player_pair = creator.create(BoardSize);
    Game game{std::move(player_pair), displayer, console, BoardSize};
    game.run();
}
