#include "Validator.h"

bool Validator::isPlayerGuessValid(string word, int expectedLength)
{
	return isWordValidLength(word, expectedLength) && isIsogram(word);
}

bool Validator::isIsogram(string word)
{
	// for each character in the word, check the next characters to see if there is a duplicate letter.
	// if so, return false. Using a unordered_set to store each letter. If the letter is found in the
	// vector we know the word is not an isogram.

	unordered_set<char> uniqueWordChars; 

	for (int index = 0; index < word.length(); index++)
	{
		// case insensitive comparison is needed
		char letter = tolower(word.at(index));

		// did we find the letter?
		if (uniqueWordChars.find(letter) != uniqueWordChars.end())
		{
			return false;
		}

		uniqueWordChars.insert(letter);
	}

	// if we're the word is an isogram
	return true;
}

bool Validator::isWordValidLength(string word, int expectedLength)
{
	return word.length() == expectedLength;
}