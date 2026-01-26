/**
 * @file Lab1_gabet.cpp
 * @author Gabriel Toninelli
 * @date 2026S-01-25
 * @brief A simple program to greet the user by name.
 */

#include <iostream>
#include <string>

int main() {
    // Declare variables
    std::string firstName;
    std::string lastName;
    
    // Prompt and read first name
    std::cout << "Enter your first name: ";
    std::cin >> firstName;
    
    // Prompt and read last name
    std::cout << "Enter your last name: ";
    std::cin >> lastName;
    
    // Output greeting
    std::cout << "Welcome to C++ Programming, " << firstName << " " << lastName << "!" << std::endl;
    
    return 0;
}