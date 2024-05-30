
#ifndef CHARACTER_H
#define CHARACTER_H

#include "Cell.h"

class Character : public Cell {
public:
    Character(int x, int y);

    void move(int dx, int dy);
};

#endif
