/**
 * @file Lab6_gabet.cpp
 * @author Gabriel Toninelli
 * @date 2026-02-27
 * @brief Compare static arrays and vectors for processing student scores.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <limits>

using namespace std;

/**
 * @brief Calculates the average of scores in a static array.
 * @param arr The integer array containing scores.
 * @param size The number of elements in the array.
 * @return The average score as a float. Returns 0.0f if size <= 0.
 */
float calculateAverage(const int arr[], int size);

/**
 * @brief Finds the maximum score in a static array.
 * @param arr The integer array containing scores.
 * @param size The number of elements in the array.
 * @return The highest score in the array. Returns 0 if size <= 0.
 */
int findMax(const int arr[], int size);

/**
 * @brief Finds the minimum score in a static array.
 * @param arr The integer array containing scores.
 * @param size The number of elements in the array.
 * @return The lowest score in the array. Returns 0 if size <= 0.
 */
int findMin(const int arr[], int size);

/**
 * @brief Calculates the average of scores in a vector.
 * @param vec The vector containing integer scores.
 * @return The average score as a float. Returns 0.0f if the vector is empty.
 */
float calculateAverage(const vector<int>& vec);

/**
 * @brief Finds the maximum score in a vector.
 * @param vec The vector containing integer scores.
 * @return The highest score in the vector. Returns 0 if the vector is empty.
 */
int findMax(const vector<int>& vec);

/**
 * @brief Finds the minimum score in a vector.
 * @param vec The vector containing integer scores.
 * @return The lowest score in the vector. Returns 0 if the vector is empty.
 */
int findMin(const vector<int>& vec);

/**
 * @brief Clears bad input from std::cin and discards the rest of the current line.
 * @param None.
 * @return None (void).
 */
void clearBadInput();

/**
 * @brief Calculates statistics using a fixed-size static array.
 * @param None.
 * @return None (void).
 */
void arraySolution();

/**
 * @brief Calculates statistics using a dynamic vector.
 * @param None.
 * @return None (void).
 */
void vectorSolution();

/**
 * @brief Entry point of the program.
 * @param None.
 * @return 0 to indicate success.
 */
int main()
{
    arraySolution();
    vectorSolution();
    return 0;
}

float calculateAverage(const int arr[], int size)
{
    if (size <= 0) return 0.0f;

    long long sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return static_cast<float>(sum) / static_cast<float>(size);
}

int findMax(const int arr[], int size)
{
    if (size <= 0) return 0;

    int maxVal = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > maxVal) maxVal = arr[i];
    }
    return maxVal;
}

int findMin(const int arr[], int size)
{
    if (size <= 0) return 0;

    int minVal = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < minVal) minVal = arr[i];
    }
    return minVal;
}

float calculateAverage(const vector<int>& vec)
{
    if (vec.empty()) return 0.0f;

    long long sum = 0;
    for (size_t i = 0; i < vec.size(); i++)
    {
        sum += vec[i];
    }
    return static_cast<float>(sum) / static_cast<float>(vec.size());
}

int findMax(const vector<int>& vec)
{
    if (vec.empty()) return 0;

    int maxVal = vec[0];
    for (size_t i = 1; i < vec.size(); i++)
    {
        if (vec[i] > maxVal) maxVal = vec[i];
    }
    return maxVal;
}

int findMin(const vector<int>& vec)
{
    if (vec.empty()) return 0;

    int minVal = vec[0];
    for (size_t i = 1; i < vec.size(); i++)
    {
        if (vec[i] < minVal) minVal = vec[i];
    }
    return minVal;
}

void clearBadInput()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void arraySolution()
{
    const int SIZE = 10;
    int scores[SIZE];

    cout << "\n=== Static Array Solution (Fixed Size: 10) ===\n";
    cout << "Enter 10 integer test scores (0 to 100).\n";

    for (int i = 0; i < SIZE; )
    {
        cout << "Score " << (i + 1) << ": ";

        int value;
        if (!(cin >> value))
        {
            cout << "Invalid input. Please enter an integer.\n";
            clearBadInput();
            continue;
        }

        if (value < 0 || value > 100)
        {
            cout << "Invalid score. Must be between 0 and 100.\n";
            continue;
        }

        scores[i] = value;
        i++;
    }

    float avg = calculateAverage(scores, SIZE);
    int highest = findMax(scores, SIZE);
    int lowest = findMin(scores, SIZE);

    cout << fixed << setprecision(2);
    cout << "\nArray Statistics:\n";
    cout << "Average: " << avg << "\n";
    cout << "Highest: " << highest << "\n";
    cout << "Lowest:  " << lowest << "\n";
}

void vectorSolution()
{
    vector<int> scores;

    cout << "\n=== Vector Solution (Dynamic Size) ===\n";
    cout << "Enter integer test scores (0 to 100). Enter -1 when finished.\n";

    while (true)
    {
        cout << "Score (or -1 to stop): ";

        int value;
        if (!(cin >> value))
        {
            cout << "Invalid input. Please enter an integer.\n";
            clearBadInput();
            continue;
        }

        if (value == -1)
        {
            break;
        }

        if (value < 0 || value > 100)
        {
            cout << "Invalid score. Must be between 0 and 100 (or -1 to stop).\n";
            continue;
        }

        scores.push_back(value);
    }

    if (scores.empty())
    {
        cout << "\nNo scores entered. Nothing to calculate.\n";
        return;
    }

    float avg = calculateAverage(scores);
    int highest = findMax(scores);
    int lowest = findMin(scores);

    cout << fixed << setprecision(2);
    cout << "\nVector Statistics:\n";
    cout << "Average: " << avg << "\n";
    cout << "Highest: " << highest << "\n";
    cout << "Lowest:  " << lowest << "\n";

    sort(scores.begin(), scores.end());

    cout << "\nSorted Scores (Ascending):\n";
    for (size_t i = 0; i < scores.size(); i++)
    {
        cout << scores[i];
        if (i + 1 < scores.size()) cout << " ";
    }
    cout << "\n";
}