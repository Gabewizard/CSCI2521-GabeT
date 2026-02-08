/**
 * @file Lab2_gabet.cpp
 * @author Gabriel Toninelli
 * @date 2026-01-22
 * @brief A program to calculate the perimeter of a rectangle from user input.
 */

#include <iostream>

using namespace std;

int main()
{
    // Declare floating-point variables
    double length = 0.0;
    double width = 0.0;
    double perimeter = 0.0;

    // Introductory message
    cout << "This application will calculate the perimeter of a rectangle." << endl << endl;

    // Get user input
    cout << "Please enter the length of the rectangle: ";
    cin >> length;

    cout << "Please enter the width of the rectangle: ";
    cin >> width;

    // Calculate perimeter
    perimeter = 2 * (length + width);

    // Output result
    cout << "The perimeter of the rectangle is: " << perimeter << endl;

    return 0;
}
