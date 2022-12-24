// Copyright (c) 2022 Chris Di Bert All rights reserved.
// .
// Created by: Chris Di Bert
// Date: Dec.23, 2022
// This program finds perfect squares in a list
// of numbers entered by the user/read from a file

#include <cmath>
#include <fstream>
#include <iostream>
#include <limits>
#include <list>

// Finds the perfect squares in a list of numbers
std::list<int> findPerfectSquares(std::list<int> numbers) {
    // Creates list to store perfect squares
    std::list<int> perfectSquares;
    for (int number : numbers) {
        /* Check if the number is a perfect square by
         incrementing i and checking if i^2 is equal to the number*/
        int i = 1;
        while (i * i <= number) {
            if (i * i == number) {
                perfectSquares.push_back(number);
                break;
            }
            i++;
        }
    }
    return perfectSquares;
}

int main() {
    while (true) {
        // Declaring variables
        std::string filePath, restart;
        int x;
        std::list<int> numbers;

        // Asks the user to enter the file path of the .txt file
        std::cout << "Enter the file path or leave ";
        std::cout << "blank to enter numbers manually:";
        std::getline(std::cin, filePath);

        // Checks if the filePath variable was not given a null value
        if (filePath.empty()) {
            // Read numbers from the terminal
            std::cout << "Enter a list of numbers (enter a";
            std::cout << " non-numeric character to stop): ";
            /* If the user enters a null value or other erroneous data, the input cache is
            cleared to prevent future input errors */
            while (true) {
                std::cin >> x;
                if (std::cin.fail()) {
                    std::cin.clear();
                    break;
                }
                numbers.push_back(x);
            }

            /*Clears input bugger to make sure any leftover characters
             in the input stream are ignored*/
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        } else {
            // Read numbers from the file
            std::ifstream file(filePath);
            while (file >> x) {
                numbers.push_back(x);
            }
        }

        // Find the perfect squares in the list of numbers
        std::list<int> perfect_squares = findPerfectSquares(numbers);

        // Print the perfect squares
        std::cout << "The following numbers are perfect squares: ";
        for (int number : perfect_squares) {
            std::cout << number << " ";
        }
        std::cout << std::endl;

        // Asks the user if they would like to restart
        std::cout << "Would you like to restart? (Y/N) ";
        std::cin >> restart;
        if (restart != "y" && restart != "Y") {
            break;
        }

        // Clears input buffer to prevent input errors after restart
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}
