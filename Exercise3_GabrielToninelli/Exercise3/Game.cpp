#include "StandardIncludes.h"
#include "Engine.h"

int main()
{
    Engine* engine = new Engine();
    try
    {
        engine->play();
    }
    catch (exception e)
    {
        cout << "A gameplay error occurred: " << e.what() << endl;
    }

    delete engine;
    return 0;
}