/**
 * @file Lab4_gabet.cpp
 * @author Gabriel Toninelli
 * @date 2026-02-15
 * @brief A program that generates a formatted multiplication table with input validation.
 */

#include <iostream>
using namespace std;

int main() {

    int maxDigit;

    cout << "Please enter the maximum digit for the multiplication table." << endl;
    cout << "The digit must be greater than 4 and less than 10" << endl;

    // INPUT VALIDATION LOOP
    do {
        cout << "Max Digit: ";
        cin >> maxDigit;

        if (maxDigit <= 4 || maxDigit >= 10) {
            cout << "Error: The max digit must be greater than 4 and less than 10. Please try again." << endl;
        }

    } while (maxDigit <= 4 || maxDigit >= 10);

    // MULTIPLICATION TABLE GENERATION
    for (int row = 1; row <= maxDigit; row++) {
        for (int col = 1; col <= maxDigit; col++) {
            cout << row * col << "\t";
        }
        cout << endl;
    }

    return 0;
}
