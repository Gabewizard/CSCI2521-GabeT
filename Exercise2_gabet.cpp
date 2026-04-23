/**
 * @file Exercise2_gtoninelli.cpp
 * @author Gabriel Toninelli
 * @date 2026-04-22
 * @brief This program translates English sentences into Morse Code.
 */

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

/**
 * @class SentenceHelper
 * @brief Handles sentence cleanup tasks.
 */
class SentenceHelper
{
public:
    /**
     * @brief Converts a string to lowercase.
     * @param str The string to convert.
     * @return The lowercase version of the string.
     */
    string toLowerCase(string str)
    {
        for (int i = 0; i < str.length(); i++)
        {
            str[i] = tolower(str[i]);
        }

        return str;
    }

    /**
     * @brief Cuts the string down to 50 characters if needed.
     * @param str The user's sentence.
     * @return A sentence with at most 50 characters.
     */
    string limitSentence(string str)
    {
        if (str.length() > 50)
        {
            str = str.substr(0, 50);
        }

        return str;
    }
};

/**
 * @class MorseCode
 * @brief Translates letters into Morse Code.
 */
class MorseCode
{
public:
    /**
     * @brief Returns the Morse Code for one letter.
     * @param ch A lowercase letter.
     * @return The Morse Code string for that letter.
     */
    string getCode(char ch)
    {
        switch (ch)
        {
        case 'a': return ".-";
        case 'b': return "-...";
        case 'c': return "-.-.";
        case 'd': return "-..";
        case 'e': return ".";
        case 'f': return "..-.";
        case 'g': return "--.";
        case 'h': return "....";
        case 'i': return "..";
        case 'j': return ".---";
        case 'k': return "-.-";
        case 'l': return ".-..";
        case 'm': return "--";
        case 'n': return "-.";
        case 'o': return "---";
        case 'p': return ".--.";
        case 'q': return "--.-";
        case 'r': return ".-.";
        case 's': return "...";
        case 't': return "-";
        case 'u': return "..-";
        case 'v': return "...-";
        case 'w': return ".--";
        case 'x': return "-..-";
        case 'y': return "-.--";
        case 'z': return "--..";
        default: return "";
        }
    }

    /**
     * @brief Translates a sentence into Morse Code.
     * @param sentence The sentence to translate.
     */
    void translateSentence(string sentence)
    {
        for (int i = 0; i < sentence.length(); i++)
        {
            if (isalpha(sentence[i]))
            {
                cout << getCode(sentence[i]) << " ";
            }
        }

        cout << endl;
    }
};

/**
 * @brief Main function that runs the program.
 * @return int Returns 0 when program finishes.
 */
int main()
{
    SentenceHelper helper;
    MorseCode translator;

    string sentence;
    string again = "y";

    while (again == "y" || again == "Y")
    {
        cout << "Enter a sentence: ";
        getline(cin, sentence);

        sentence = helper.limitSentence(sentence);
        sentence = helper.toLowerCase(sentence);

        cout << "Morse Code: ";
        translator.translateSentence(sentence);

        cout << "Translate another sentence? (y/n): ";
        getline(cin, again);
    }

    return 0;
}