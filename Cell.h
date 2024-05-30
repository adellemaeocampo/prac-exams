#ifndef CELL_H
#define CELL_H

#include <tuple>

class Cell {
public:
    Cell(int x, int y, char type);

    std::tuple<int, int> getPos() const;
    char getType() const;

    void setPos(int x, int y);
    void setType(char type);

protected:
    std::tuple<int, int> position;
    char type;
};

#endif 