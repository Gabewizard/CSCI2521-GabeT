#ifndef CATS_AND_COUGARS_H
#define CATS_AND_COUGARS_H

#include "StandardIncludes.h"

class CatsAndCougars
{
private:
    int cats;
    int cougars;

    void reset();

public:
    CatsAndCougars();
    int getCats();
    int getCougars();
    void count(string lword, string rword);
};

#endif