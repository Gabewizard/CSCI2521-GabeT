#include "Engine.h"

Engine::Engine()
{
    catsAndCougars = new CatsAndCougars();
    validation = new Validator();
    wordGenerator = new WordGenerator(IS_DEBUG);
}

Engine::~Engine()
{
    delete catsAndCougars;
    delete validation;
    delete wordGenerator;
}

void Engine::play()
{
    Instructions::print();

    do
    {
        bool winner = false;
        int currentRound = 1;
        string hiddenWord = wordGenerator->getRandomizedWord();

        while (currentRound <= NUM_LIVES)
        {
            string playerGuess = getPlayerGuess(currentRound);

            if (didPlayerWin(hiddenWord, playerGuess))
            {
                playerWins();
                winner = true;
                break;
            }
            else
            {
                incorrectGuess(hiddenWord, playerGuess);
                currentRound++;
            }
        }

        if (!winner)
        {
            playerLoses();
        }

    } while (playAgain());
}

bool Engine::playAgain()
{
    char again = 'n';
    cout << "Do you wish to play again? (y or n): ";
    cin >> again;

    return toupper(again) == 'Y';
}

void Engine::invalidPlayerGuess()
{
    cout << "Each guess must be an isogram " << WORD_LEN << " letters in length. Please try again." << endl;
}

string Engine::getPlayerGuess(int currentRound)
{
    string word = "";

    do
    {
        cout << "Round: " << currentRound << ". Please make your guess. " << NUM_LIVES - currentRound + 1 << " guesses remain: ";
        cin >> word;

        if (!validation->isPlayerGuessValid(word, WORD_LEN))
        {
            invalidPlayerGuess();
        }
    } while (!validation->isPlayerGuessValid(word, WORD_LEN));

    return Utility::toLowerCase(word);
}

void Engine::playerWins()
{
    cout << "Congratulations! You guessed correctly!" << endl;
}

bool Engine::didPlayerWin(string hiddenWord, string playerGuess)
{
    return hiddenWord == playerGuess;
}

void Engine::playerLoses()
{
    cout << "You lost but don't get discouraged!" << endl;
}

void Engine::incorrectGuess(string hiddenWord, string playerGuess)
{
    catsAndCougars->count(hiddenWord, playerGuess);
    cout << "Sorry, " << playerGuess << " is not the hidden word. You have " <<
        catsAndCougars->getCats() << " Cats and " << catsAndCougars->getCougars() <<
        " Cougars." << endl;
}
