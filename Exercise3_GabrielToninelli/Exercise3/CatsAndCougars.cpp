#include "CatsAndCougars.h"
#include "Utility.h"

CatsAndCougars::CatsAndCougars()
{
    reset();
}

int CatsAndCougars::getCats()
{
    return cats;
}

int CatsAndCougars::getCougars()
{
    return cougars;
}

void CatsAndCougars::count(string lword, string rword)
{
    reset();

    lword = Utility::toLowerCase(lword);
    rword = Utility::toLowerCase(rword);

    for (int guessIndex = 0; guessIndex < rword.length(); guessIndex++)
    {
        if (rword.at(guessIndex) == lword.at(guessIndex))
        {
            cats++;
        }
        else
        {
            for (int hiddenIndex = 0; hiddenIndex < lword.length(); hiddenIndex++)
            {
                if (rword.at(guessIndex) == lword.at(hiddenIndex))
                {
                    cougars++;
                    break;
                }
            }
        }
    }
}

void CatsAndCougars::reset()
{
    cats = 0;
    cougars = 0;
}
