#ifndef EFFECT_H
#define EFFECT_H
#include "Cell.h"

class Effect {
public:
    virtual ~Effect() = default;
    virtual void apply(Cell& cell) = 0;
};

#endif 
