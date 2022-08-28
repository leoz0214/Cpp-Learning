#include <iostream>
#include "collatz.h"


// The modes which only require a single number as input.
void single_number_mode(Modes mode) {
    int number, count;
    while (true) {
        std::cout << MENU_RETURN;
        std::cout << "Enter a number (1 to 1,000,000): ";

        std::cin >> number;
        if (number == -1) {
            return;
        }

        std::cout << '\n';
        if (number < 1) {
            std::cout << "Number must be positive.";
        } else if (number > 1000000) {
            std::cout << "Number must be 1 million or less.";
        } else {
            switch (mode) {
                case calculation_count:
                    count = collatz::count(number);

                    if (count == 1) {
                        // Guaranteed to be 2.
                        std::cout << "2 takes only 1 calculation to reach 1.";
                    } else {
                        std::cout << number << " takes " << count <<
                        " calculations to reach 1.";
                    }
                    break;
                case visual:
                    collatz::visualise_sequence(number);
                    break;
                case reverse_visual:
                    collatz::visualise_reverse_sequence(number);
                    break;           
            }
        }
        std::cout << '\n';
    }
}


// The modes which require two numbers as input.
void max_or_min_mode(Modes mode) {
    int first, last, number, count;
    while (true) {
        std::cout << MENU_RETURN;
        
        while (true) {
            std::cout << "Enter first number (1 to 999,999): ";
            std::cin >> first;
            if (first == -1) {
                return;
            }
            
            std::cout << '\n';
            if (first < 1) {
                std::cout << "Number must be positive\n\n";
            } else if (first > 999999) {
                std::cout << "Number must be less than 1 million.\n\n";
            } else {
                break;
            }
        }

        while (true) {
            std::cout <<
            "Enter last number (2 to 1,000,000, greater than first): ";
            std::cin >> last;
            if (last == -1) {
                return;
            } 
            
            std::cout << '\n';
            if (last < 2) {
                std::cout << "Number must be at least "
                << first + 1 << "\n\n";
            } else if (last > 1000000) {
                std::cout << "Number must be 1 million or less.\n\n";
            } else if (last <= first) {
                std::cout << "Last number must be greater than first.\n\n";
            } else {
                break;
            }
        }

        number = mode == max_count
        ? collatz::max_count(first, last) : collatz::min_count(first, last);

        count = collatz::count(number);

        if (mode == max_count) {
            if (count == 1) {
                // Guaranteed to be 2, out of 1 and 2.
                std::cout << "The number between 1 and 2 " <<
                "with the longest Collatz sequence is:\n" <<
                "2, requiring only 1 calculation to reach 1.";
            }
            else {
                std::cout << "The number between " << first << " and " <<
                last << " with the longest Collatz sequence is:\n"<< number <<
                ", requiring " << count << " calculations to reach 1.";
            }
        } else { // min_count
            if (count == 1) {
                // Guaranteed to start at 2.
                std::cout << "The number between 2 and " << last <<
                " with the shortest Collatz sequence is:\n" <<
                "2, requiring only 1 calculation to reach 1.";
            }
            else {
                std::cout << "The number between " << first << " and " <<
                last << " with the shortest Collatz sequence is:\n"<< number <<
                ", requiring " << count << " calculations to reach 1.";
            }            
        }
        std::cout << '\n';
    }  
}


// Runs one of the modes involving positive integers on the Collatz conjecture.
void run_mode(Modes mode) {
    (mode == max_count || mode == min_count)
    ? max_or_min_mode(mode) : single_number_mode(mode);
}


int main() {
    int selection;

    while (true) {
        std::cout << "\n----- Collatz Conjecture -----\n";
        std::cout << "0. Quit\n";
        std::cout << "1. Get calculation count to 1\n";
        std::cout << "2. Visualise sequence\n";
        std::cout << "3. Visualise reverse sequence\n";
        std::cout << "4. Get maximum count in a range\n";
        std::cout << "5. Get minimum count in a range\n";
        std::cout << "6. What is the Collatz Conjecture?\n";
        std::cout << "\nEnter your selection: ";

        std::cin >> selection;

        switch (selection) {
            case 0:
                std::cout << "\nProgram terminated.\n";
                return 0;
            case 1:
                run_mode(calculation_count);
                break;
            case 2:
                run_mode(visual);
                break;
            case 3:
                run_mode(reverse_visual);
                break;
            case 4:
                run_mode(max_count);
                break;
            case 5:
                run_mode(min_count);
                break;
            case 6:
                std::cout << ABOUT_COLLATZ_CONJECTURE;
                break;
            default:
                std::cout << "\nInvalid input, please try again.\n";
                break;
        }
    }
}