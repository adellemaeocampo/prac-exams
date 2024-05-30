#ifndef GAME_H
#define GAME_H
#include <vector>
#include <iostream>
#include "Cell.h"
#include "Character.h"
#include "Trap.h"
#include "Utils.h"

class Game {
public:
    Game();
    std::vector<Cell*>& getGrid();
    void initGame(int numCharacters, int numTraps, int gridWidth, int gridHeight);
    void gameLoop(int maxIterations, double trapActivationDistance);

private:
    std::vector<Cell*> grid;
    int gridWidth;
    int gridHeight;
    bool isWithinBounds(int x, int y);
};

Game::Game() : gridWidth(0), gridHeight(0) {}
std::vector<Cell*>& Game::getGrid() {
    return grid;
}

void Game::initGame(int numCharacters, int numTraps, int gridWidth, int gridHeight) {
    this->gridWidth = gridWidth;
    this->gridHeight = gridHeight;
    grid.clear();

    for (int i = 0; i < numCharacters; ++i) {
        auto pos = Utils::generateRandomPos(gridWidth, gridHeight);
        Character* character = new Character(std::get<0>(pos), std::get<1>(pos));
        grid.push_back(character);
    }

    for (int i = 0; i < numTraps; ++i) {
        auto pos = Utils::generateRandomPos(gridWidth, gridHeight);
        Trap* trap = new Trap(std::get<0>(pos), std::get<1>(pos));
        grid.push_back(trap);
    }
}

void Game::gameLoop(int maxIterations, double trapActivationDistance) {
    for (int iteration = 0; iteration < maxIterations; ++iteration) {
        for (auto cell : grid) {
            Character* character = dynamic_cast<Character*>(cell);
            if (character) {
                character->move(1, 0);

                auto [x, y] = character->getPos();
                if (!isWithinBounds(x, y)) {
                    std::cout << "Character has won the game!" << std::endl;
                    return;
                }

                for (auto otherCell : grid) {
                    Trap* trap = dynamic_cast<Trap*>(otherCell);
                    if (trap && trap->isActive()) {
                        double distance = Utils::calculateDistance(character->getPos(), trap->getPos());
                        if (distance <= trapActivationDistance) {
                            trap->apply(*character);
                        }
                    }
                }
            }
        }
    }
    std::cout << "Maximum number of iterations reached. Game over." << std::endl;
}

bool Game::isWithinBounds(int x, int y) {
    return x >= 0 && x < gridWidth && y >= 0 && y < gridHeight;
}

#endif 
