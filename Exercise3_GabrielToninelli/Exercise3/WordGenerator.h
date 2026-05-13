#ifndef WORD_GENERATOR_H
#define WORD_GENERATOR_H

#include "StandardIncludes.h"

class WordGenerator
{
private:
    const int WORD_COUNT = 10;
    bool isDebug;

    int getRandomNumber();

public:
    WordGenerator();
    WordGenerator(bool isDebug);
    string getRandomizedWord();
};

#endif
