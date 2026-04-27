/**
 * @file Lab11_gtoninelli.cpp
 * @author Gabriel Toninelli
 * @date 2026-04-26
 * @brief Demonstrates exception handling with vectors using try and catch blocks.
 */

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

/**
 * @brief Entry point for the city lookup program.
 * @return 0 to indicate successful completion.
 */
int main()
{
    std::vector<std::string> cities = {
        "Columbus",
        "Cleveland",
        "Cincinnati",
        "Toledo",
        "Akron",
        "Dayton",
        "Youngstown"
    };

    int index;

    std::cout << "Enter an index to look up a city: ";
    std::cin >> index;

    try
    {
        std::cout << "City at index " << index << " is: " << cities.at(index) << std::endl;
    }
    catch (const std::out_of_range& e)
    {
        if (index < 0)
        {
            std::cout << "Invalid index. Here's the first city instead: "
                      << cities.front() << std::endl;
        }
        else if (index >= static_cast<int>(cities.size()))
        {
            std::cout << "Invalid index. Here's the last city instead: "
                      << cities.back() << std::endl;
        }
    }

    return 0;
}