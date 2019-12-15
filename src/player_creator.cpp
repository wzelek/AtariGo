#include "player_creator.hpp"
#include "player.hpp"
#include "human_player.hpp"
#include "ai_player.hpp"
#include "stone.hpp"
#include "game_io.hpp"

PlayerCreator::PlayerCreator(std::shared_ptr<GameIO> gameIO_)
    : gameIO{gameIO_} {
}

PlayerCreator::player_pair_t PlayerCreator::create(unsigned boardSize) {
    std::string name1 = gameIO->getLine("Input first  player name: ");
    std::string color_name;
    for(;;) {
        color_name = gameIO->getLine("Input first  player color [Black|White]: ");
        if((color_name == "Black") || (color_name == "White")) {
            break;
        }
        gameIO->showError("Incorrect color name! Try again!\n");
    }
    StoneColor color1 = (color_name == "Black" ? StoneColor::Black: StoneColor::White);
    std::string name2 = gameIO->getLine("Input second player name: ");
    StoneColor color2 = (color1 == StoneColor::Black ? StoneColor::White: StoneColor::Black);
    if (color1 == StoneColor::Black) {
        return  {
        std::make_unique<HumanPlayer>(name1, color1, gameIO, boardSize),
        std::make_unique<AIPlayer>(name2, color2, gameIO, boardSize)
        };
    }
    return {
        std::make_unique<AIPlayer>(name2, color2, gameIO, boardSize),
        std::make_unique<HumanPlayer>(name1, color1, gameIO, boardSize)
    };
}
