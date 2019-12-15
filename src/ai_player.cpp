#include "ai_player.hpp"
#include "game_io.hpp"
#include "position.hpp"
#include <string_view>
#include <iostream>
#include <limits>
#include <random>
#include <chrono>
#include <thread>

AIPlayer::AIPlayer(const std::string& name_, StoneColor color_, std::shared_ptr<GameIO> gameIO_, unsigned boardSize_)
    : Player{name_, color_, gameIO_, boardSize_}, rd{std::make_unique<std::random_device>()} {}

Position AIPlayer::getPosition() const {
    static std::mt19937_64 gen((*rd)());
    static std::uniform_int_distribution<char> colDistribution('a', static_cast<char>('a' + boardSize - 1));
    static std::uniform_int_distribution<unsigned> rowDistribution(1, boardSize);
    for(;;) {
        gameIO->showString("AI Player " + name + ", plays " + (color == StoneColor::Black ? "Black": "White") + ".\n");

        // Dumb sleep :)
        gameIO->showString("Think");
        for(auto i = 0U; i < 5; ++i) {
            //std::this_thread::sleep_for(std::chrono::milliseconds(100));
            gameIO->showString(".");
            std::cout.flush();
        }
        gameIO->showString("\n");

        auto position = Position::make(colDistribution(gen), rowDistribution(gen), boardSize);
        if(position) {
            return *position;
        }
    }
}

