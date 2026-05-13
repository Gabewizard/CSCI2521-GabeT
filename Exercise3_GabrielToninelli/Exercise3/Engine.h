#ifndef ENGINE_H
#define ENGINE_H

#include "StandardIncludes.h"
#include "CatsAndCougars.h"
#include "Instructions.h"
#include "Utility.h"
#include "Validator.h"
#include "WordGenerator.h"

class Engine
{
private:
    const bool IS_DEBUG = false;
    const int WORD_LEN = 4;
    const int NUM_LIVES = 10;

    WordGenerator* wordGenerator;
    Validator* validation;
    CatsAndCougars* catsAndCougars;

    bool playAgain();
    void invalidPlayerGuess();
    string getPlayerGuess(int currentRound);
    void playerWins();
    bool didPlayerWin(string hiddenWord, string playerGuess);
    void playerLoses();
    void incorrectGuess(string hiddenWord, string playerGuess);

public:
    Engine();
    ~Engine();
    void play();
};

#endif
