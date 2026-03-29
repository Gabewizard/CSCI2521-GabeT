/**
 * @file Lab8_gtoninelli.cpp
 * @author Gabriel Toninelli
 * @date 03-29-2026
 * @brief Demonstrates stack vs heap memory and the use of pointers and references.
 */

#include <iostream>

using namespace std;

/**
 * @brief Entry point for the memory demonstration program.
 * @return 0 to indicate successful program execution.
 */
int main()
{
    // STACK ALLOCATION
    int stackInt = 10;

    // HEAP ALLOCATION
    int* heapInt = new int(20);

    // POINTER TO STACK VARIABLE
    int* ptrToStack = &stackInt;

    // REFERENCE TO STACK VARIABLE
    int& refToStack = stackInt;

    // OUTPUT STACK VARIABLE
    cout << "Stack Variable (stackInt):" << endl;
    cout << "  Value: " << stackInt << endl;
    cout << "  Address: " << &stackInt << endl;
    cout << endl;

    // OUTPUT HEAP VARIABLE
    cout << "Heap Variable (heapInt):" << endl;
    cout << "  Value: " << *heapInt << endl;
    cout << "  Address: " << heapInt << endl;
    cout << endl;

    // OUTPUT POINTER TO STACK
    cout << "Pointer to Stack (ptrToStack):" << endl;
    cout << "  Value Pointed To: " << *ptrToStack << endl;
    cout << "  Address Stored: " << ptrToStack << endl;
    cout << endl;

    // OUTPUT REFERENCE TO STACK
    cout << "Reference to Stack (refToStack):" << endl;
    cout << "  Value Referred To: " << refToStack << endl;
    cout << "  Address: " << &refToStack << endl;
    cout << endl;

    // CLEAN UP HEAP MEMORY
    delete heapInt;
    heapInt = nullptr;

    return 0;
}