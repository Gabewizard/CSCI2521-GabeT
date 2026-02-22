/**
 * @file Lab5_gabet.cpp
 * @author Gabriel Toninelli
 * @date 2026-02-21
 * @brief A modular program to generate a multiplication table using functions.
 */

#include <iostream>
using namespace std;

/**
 * @brief Outputs an error message for invalid input.
 * @param None.
 * @return None.
 */
void printInputValidationError();

/**
 * @brief Validates the user's input against the acceptable range.
 * @param input The user-provided integer to validate.
 * @return true if input is greater than 4 and less than 10; false otherwise.
 */
bool isMaxDigitInputValid(int input);

/**
 * @brief Prompts the user for input and ensures it is valid.
 * @param None.
 * @return A validated int representing the maximum digit.
 */
int getMaxDigitInput();

/**
 * @brief Prints the formatted multiplication table.
 * @param maxDigit The highest digit to include in the table.
 * @return None.
 */
void printMultiplicationTable(int maxDigit);

/**
 * @brief Outputs an error message for invalid input.
 * @param None.
 * @return None.
 */
void printInputValidationError() {
    cout << "Error: The max digit must be greater than 4 and less than 10. Please try again." << endl;
}

/**
 * @brief Validates the user's input against the acceptable range.
 * @param input The user-provided integer to validate.
 * @return true if input is greater than 4 and less than 10; false otherwise.
 */
bool isMaxDigitInputValid(int input) {
    return (input > 4 && input < 10);
}

/**
 * @brief Prompts the user for input and ensures it is valid.
 * @param None.
 * @return A validated int representing the maximum digit.
 */
int getMaxDigitInput() {
    int maxDigit;

    cout << "Please enter the maximum digit for the multiplication table." << endl;
    cout << "The digit must be greater than 4 and less than 10." << endl;

    do {
        cout << "Max Digit: ";
        cin >> maxDigit;

        if (!isMaxDigitInputValid(maxDigit)) {
            printInputValidationError();
        }
    } while (!isMaxDigitInputValid(maxDigit));

    return maxDigit;
}

/**
 * @brief Prints the formatted multiplication table.
 * @param maxDigit The highest digit to include in the table.
 * @return None.
 */
void printMultiplicationTable(int maxDigit) {
    for (int r = 1; r <= maxDigit; r++) {
        for (int c = 1; c <= maxDigit; c++) {
            cout << r * c;
            if (c < maxDigit) cout << "\t";
        }
        cout << endl;
    }
}

/**
 * @brief Entry point of the program.
 * @param None.
 * @return 0 to indicate success.
 */
int main() {
    int maxDigit = getMaxDigitInput();
    printMultiplicationTable(maxDigit);
    return 0;
}