// BMI Calculator built in C++.

#include <string>
#include <iostream>
#include <fstream>
#include "bmi.h"


int main() {
    int selection;
    std::string units[2];
    std::ifstream file("units.txt");
    if (file.is_open()) {
        // Gets previously saved units.
        file >> units[0];
        file >> units[1];
    } else {
        file.close();
        // Sets default units.
        std::ofstream new_file("units.txt");
        new_file << "m kg";
        units[0] = "m";
        units[1] = "kg";
    }

    // Main menu.
    while (true) {
        std::cout << "\n----- BMI Calculator -----\n";
        std::cout << "0. Quit\n";
        std::cout << "1. Set units\n";
        std::cout << "2. Get units\n";
        std::cout << "3. Calculate BMI\n";
        std::cout << "4. About BMI\n";
        std::cout << "\nEnter your selection (0-4): ";
        
        std::cin >> selection;

        switch (selection) {
            case 0:
                std::cout << "\nProgram terminated successfully.\n";
                return 0;
            case 1:
                set_units(units);
                break;
            case 2:
                std::cout << "\nHeight unit: " << units[0] << "\n";
                std::cout << "Weight unit: " << units[1] << "\n";
                break;
            case 3:
                calculator(units);
                break;
            case 4:
                about_bmi();
                break;
            default:
                std::cout << "\nInvalid input, please try again.\n";
                break;
        }
    }
}