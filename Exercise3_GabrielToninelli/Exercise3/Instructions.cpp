#include "Instructions.h"

// this function is declared static
// If you would like to print your own instructions to the came,
// overwrite the cout statements inside this function.
void Instructions::print()
{
	cout << "Welcome to Cats and Cougars, the fun word guessing game. Your goal is to guess the correct word." << endl;
	cout << "Each word is an isogram 4 letters in length. If you guess the correct letter in the correct position, you earn a cat." << endl;
	cout << "If you guess a correct letter in the wrong position, you get a cougar. If you guess the word corretly, you win!" << endl;
	cout << "Don't worry about words being case-sensitive, I've taken care of that for you." << endl;
	cout << "You have 10 tries, let's get goin'!\n" << endl;
}