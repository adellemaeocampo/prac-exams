#include <iostream>
#include "Game.h"
#include "Cell.h"
#include "Effect.h"
#include "Trap.h"
#include "Character.h"
#include "Utils.h"

int main() {
    Game game;
    game.initGame(3, 2, 10, 10);

    std::cout << "Initial game state:" << std::endl;
    for (auto cell : game.getGrid()) {
        auto[x, y] = cell->getPos();
        std::cout << "Cell at (" << x << ", " << y << ") of type " << cell->getType() << std::endl;
    }

    game.gameLoop(20, 1.5);

    std::cout << "Final game state:" << std::endl;
    for (auto cell : game.getGrid()) {
        auto [x, y] = cell->getPos();
        std::cout << "Cell at (" << x << ", " << y << ") of type " << cell->getType() << std::endl;
    }

    return 0;
}
