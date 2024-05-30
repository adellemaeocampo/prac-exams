#include <iostream>
#include "Cell.h"
#include "Effect.h"
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

class SampleEffect : public Effect {
public:
    void apply(Cell& cell) override {
        cell.setType('E'); 
    }
};

int main() {
    Cell cell(0, 0, 'A');
    

    auto pos = cell.getPos();
    std::cout << "Intial Position: (" << std::get<0>(pos) << ", " << std::get<1>(pos) << ")\n";
    std::cout << "Type: " << cell.getType() << "\n";


    SampleEffect effect;
    effect.apply(cell);

    pos = cell.getPos();
    std::cout << "Effect Cell Position: (" << std::get<0>(pos) << ", " << std::get<1>(pos) << ")\n";
    std::cout << "Effect Cell Type: " << cell.getType() << "\n";

    auto randomPos = Utils::generateRandomPos(10, 10);
    std::cout << "Random Position: (" << std::get<0>(randomPos) << ", " << std::get<1>(randomPos) << ")\n";

    double distance = Utils::calculateDistance(cell.getPos(), randomPos);
    std::cout << "Distance from cell & random position: " << distance << "\n";

    return 0;
};
