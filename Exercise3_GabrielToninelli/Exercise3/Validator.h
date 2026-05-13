#ifndef VALIDATOR_H
#define VALIDATOR_H

#include "StandardIncludes.h"
#include<unordered_set>

class Validator
{
private:
    bool isIsogram(string word);
    bool isWordValidLength(string word, int expectedLength);

public:
    bool isPlayerGuessValid(string word, int expectedLength);
};

#endif
