#include "WordGenerator.h"

WordGenerator::WordGenerator()
{
	// seed random function
	srand((unsigned)time(NULL));
	isDebug = false;
}

WordGenerator::WordGenerator(bool isDebug) : WordGenerator()
{
	this->isDebug = isDebug;
}

/*
If you want to customize your list of isograms you may update
the words array below.
*/
string WordGenerator::getRandomizedWord()
{
	string words[] = {
		"acre",
		"bear",
		"cake",
		"dear",
		"easy",
		"fame",
		"grit",
		"home",
		"mute",
		"near"
	};

	string word = words[getRandomNumber()];
	if (isDebug)
	{
		cout << "Hidden word is " << word << endl;
	}

	return word;
}

int WordGenerator::getRandomNumber()
{
	return rand() % WORD_COUNT;
}