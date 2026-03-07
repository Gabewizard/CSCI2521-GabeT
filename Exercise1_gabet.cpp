/**
 * @file Exercise1_gabet.cpp
 * @author Gabriel Toninelli
 * @date 2026-03-06
 * @brief This program validates UPC-A barcodes by performing the UPC-A check digit algorithm.
 */

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

/**
 * @brief Checks if the UPC string is exactly 12 digits.
 * @param upc The UPC code entered by the user.
 * @return true if the UPC is 12 digits only, otherwise false.
 */
bool isValidFormat(const string& upc)
{
    if (upc.length() != 12)
    {
        return false;
    }

    for (int i = 0; i < upc.length(); i++)
    {
        if (!isdigit(static_cast<unsigned char>(upc[i])))
        {
            return false;
        }
    }

    return true;
}

/**
 * @brief Calculates the UPC-A check digit using the first 11 digits.
 * @param upc The full 12-digit UPC code.
 * @return The calculated check digit.
 */
int calculateCheckDigit(const string& upc)
{
    int oddSum = 0;
    int evenSum = 0;

    for (int i = 0; i < 11; i++)
    {
        int digit = upc[i] - '0';

        if ((i + 1) % 2 == 1)
        {
            oddSum += digit;
        }
        else
        {
            evenSum += digit;
        }
    }

    int total = (oddSum * 3) + evenSum;
    int remainder = total % 10;

    if (remainder == 0)
    {
        return 0;
    }

    return 10 - remainder;
}

/**
 * @brief Determines whether the UPC is valid.
 * @param upc The full 12-digit UPC code.
 * @return true if the UPC is valid, otherwise false.
 */
bool isValidUPC(const string& upc)
{
    int actualCheckDigit = upc[11] - '0';
    int calculatedCheckDigit = calculateCheckDigit(upc);

    return actualCheckDigit == calculatedCheckDigit;
}

/**
 * @brief Asks the user if they want to test another UPC.
 * @return true if the user wants to continue, otherwise false.
 */
bool testAnotherUPC()
{
    char choice;

    cout << "\nDo you have another UPC number to test? (y/n): ";
    cin >> choice;

    choice = tolower(static_cast<unsigned char>(choice));

    return choice == 'y';
}

/**
 * @brief Runs the UPC validator program.
 * @return 0 when the program ends successfully.
 */
int main()
{
    string upc;
    bool keepGoing = true;

    cout << "UPC-A Barcode Validator\n";

    while (keepGoing)
    {
        cout << "\nEnter a 12-digit UPC code: ";
        cin >> upc;

        if (!isValidFormat(upc))
        {
            cout << "Invalid input. UPC must be exactly 12 digits.\n";
        }
        else if (isValidUPC(upc))
        {
            cout << "The UPC code is valid.\n";
        }
        else
        {
            cout << "The UPC code is invalid.\n";
        }

        keepGoing = testAnotherUPC();
    }

    cout << "\nProgram ended.\n";

    return 0;
}