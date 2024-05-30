#include <iostream>
#include "Cell.h"
#include "Effect.h"
#include "Trap.h"
#include "Character.h"
#include "Utils.h"


Cell::Cell(int x, int y, char type) : position(x, y), type(type) {}

std::tuple<int, int> Cell::getPos() const {
    return position;
}

char Cell::getType() const {
    return type;
}

void Cell::setPos(int x, int y) {
    position = std::make_tuple(x, y);
}

void Cell::setType(char type) {
    this->type = type;
}
std::tuple<int, int> Utils::generateRandomPos(int gridWidth, int gridHeight) {
    srand(static_cast<unsigned>(time(0)));
    int x = rand() % gridWidth;
    int y = rand() % gridHeight;
    return std::make_tuple(x, y);
}

double Utils::calculateDistance(std::tuple<int, int> pos1, std::tuple<int, int> pos2) {
    int x1, y1, x2, y2;
    std::tie(x1, y1) = pos1;
    std::tie(x2, y2) = pos2;
    return std::sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

Trap::Trap(int x, int y) : Cell(x, y, 'T'), active(true) {}
bool Trap::isActive() const {
    return active;
}

void Trap::apply(Cell& cell) {
    if (active) {
        cell.setType('T');
        active = false;
    }
}


Character::Character(int x, int y) : Cell(x, y, 'C') {}
void Character::move(int dx, int dy) {
    int x, y;
    std::tie(x, y) = getPos();
    setPos(x + dx, y + dy);
}

int main() {
    Character character(1, 1);
    Trap trap(2, 2);

    auto charPos = character.getPos();
    std::cout << "Initial Character Position: (" << std::get<0>(charPos) << ", " << std::get<1>(charPos) << ")\n";
    std::cout << "Initial Character Type: " << character.getType() << "\n";
    auto trapPos = trap.getPos();
    std::cout << "Trap Position: (" << std::get<0>(trapPos) << ", " << std::get<1>(trapPos) << ")\n";
    std::cout << "Trap Type: " << trap.getType() << ", Active: " << trap.isActive() << "\n";

    character.move(1, 1);
    charPos = character.getPos();
    std::cout << "Character Position after moving: (" << std::get<0>(charPos) << ", " << std::get<1>(charPos) << ")\n";

    trap.apply(character);
    std::cout << "Character Position after trap: (" << std::get<0>(charPos) << ", " << std::get<1>(charPos) << ")\n";
    std::cout << "Character Type after trap: " << character.getType() << "\n";
    std::cout << "Trap Active after applying: " << trap.isActive() << "\n";

    return 0;
};
