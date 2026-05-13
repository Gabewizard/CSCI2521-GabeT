#include "Utility.h"

// This function is declared static
string Utility::toLowerCase(string word)
{
    string result = "";
    for (int index = 0; index < word.length(); index++)
    {
        result += tolower(word.at(index));
    }

    return result;
}