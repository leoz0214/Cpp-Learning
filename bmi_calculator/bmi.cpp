#include <iostream>
#include <cmath>
#include <fstream>
#include "bmi.h"


// Checks if user input for height/weight unit is valid.
bool valid_unit(std::string value, std::string value_type) {
    if (value_type == "height") {
        for (std::string val : VALID_HEIGHT_UNITS) {
            if (value == val) {
                return true;
            }
        }
    } else {
        for (std::string val : VALID_WEIGHT_UNITS) {
            if (value == val) {
                return true;
            }
        }
    }
    return false;
}


// Allows user to change units for height/weight.
void set_units(std::string current[2]) {
    std::string height_unit, weight_unit;
    bool first = true;

    std::cout << "\nEnter -1 at any time to return to the menu.\n";

    while (true) {
        std::cout << "Enter height unit (m/cm/ft/in/ftin): ";
        std::getline(std::cin, height_unit);
        
        // Get rid of first unknown line input.
        if (first) {
            std::getline(std::cin, height_unit);
            first = false;
        }

        if (height_unit == "-1") {
            return;
        } else if (!valid_unit(height_unit, "height")) {
            std::cout << "Invalid height unit, please try again.\n";
            continue;
        }
        break;
    }

    while (true) {
        std::cout << "\nEnter weight unit (kg/st/lb): ";
        std::getline(std::cin, weight_unit);

        if (weight_unit == "-1") {
            return;
        } else if (!valid_unit(weight_unit, "weight")) {
            std::cout << "Invalid weight unit, please try again.\n";
            continue;
        }
        break;
    }

    // Sets new units and saves them to file.

    current[0] = height_unit;
    current[1] = weight_unit;

    std::ofstream file("units.txt");
    file << current[0] << " " << current[1];

    std::cout << "\nSuccessfully changed units.\n";
}


// Function containing the calculator loop.
void calculator(std::string units[2]) {
    double height, weight, bmi;

    while (true) {
        std::cout << "\nEnter -1 at any time to return to the menu.\n";

        if (units[0] == "ftin") {
            // Two inputs needed for feet and inches.
            double feet, inches;
            std::cout << "Enter your height in feet and inches.\n";
            std::cout << "Feet: ";
            std::cin >> feet;
            if (feet == -1) {
                return;
            }
            std::cout << "Inches: ";
            std::cin >> inches;
            if (inches == -1) {
                return;
            }

            height = feet / 3.28084 + inches * 0.0254;
        } else {
            std::cout << "Enter your height in '" << units[0] << "': ";
            double value;
            std::cin >> value;

            if (value == -1) {
                return;
            }
            
            if (units[0] == "m") {
                height = value;
            } else if (units[0] == "cm") {
                height = value / 100;
            } else if (units[0] == "ft") {
                height = value / 3.28084;
            } else {
                height = value * 0.0254;
            }
        }

        std::cout << "Enter your weight in '" << units[1] << "': ";
        double value;
        std::cin >> value;

        if (value == -1) {
            return;
        }

        if (units[1] == "kg") {
            weight = value;
        } else if (units[1] == "st") {
            weight = value * 6.35029;
        } else if (units[1] == "lb") {
            weight = value * 0.453592;
        }

        bmi = round((weight / pow(height, 2)) * 100) / 100.;
        std::cout << "\nYour BMI is " << bmi << '\n';
        if (bmi < 18.5) {
            std::cout << "Unfortunately, you are underweight.";
        } else if (bmi < 25) {
            std::cout << "Your weight is healthy for your height! Keep it up!";
        } else if (bmi < 30) {
            std::cout << "Unfortunately, you are overweight.";
        } else {
            std::cout << "Unfortunately, you are obese.";
        }
        std::cout << "\n\n";
    }
}


// Displays info about the concept of BMI.
void about_bmi() {
    std::cout << "\n----- About BMI -----\n\n";
    std::cout << "BMI (Body Mass Index) is an indicator of ";
    std::cout << "how healthy your weight is based on your height.\n\n";
    std::cout << "It is calculated using the formula:\n";
    std::cout << "BMI = weight (kg) / height (m) ^ 2\n\n";
    std::cout << "BMI categories:\n";
    std::cout << "< 18.5: Underweight\n";
    std::cout << "18.5 <= BMI < 25: Healthy Weight\n";
    std::cout << "25 <= BMI < 30: Overweight\n";
    std::cout << ">= 30: Obese\n\n";
}