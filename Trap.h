#ifndef TRAP_H
#define TRAP_H

#include "Cell.h"
#include "Effect.h"

class Trap : public Cell, public Effect {
public:
    Trap(int x, int y);

    bool isActive() const;
    void apply(Cell& cell) override;

protected:
    bool active;
};

#endif 
