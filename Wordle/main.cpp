#include <iostream>
#include <string>
#include "game.h"


int main() {
    std::string choice;
    int outcome;
    while (true) {
        // Main Menu
        std::cout << "\n-----Wordle-----\n"
            "1. Play\n"
            "2. How to Play\n"
            "3. Quit\n"
            "Please select an option (1-3): ";
        std::getline(std::cin, choice);
        // Allows leading/trailing whitespace for user friendliness.
        strip_string(choice);
        std::cout <<'\n';

        if (choice == "1") {
            Game game;
            outcome = game.play();
            // outcome = number of lives left.
            if (outcome) {
                switch (outcome) {
                    case 6:
                        std::cout << "First try! Wow!\n";
                        break;
                    case 5:
                        std::cout << "Second try! Excellent!\n";
                        break;
                    case 4:
                        std::cout << "Third time's the charm!\n";
                        break;
                    case 1:
                        std::cout << "Just about. Well done!\n";
                        break;
                    default:
                        std::cout << "You win! Congratulations.\n";
                        break;
                }
            }            
        } else if (choice == "2") {
            std::cout << "How to play Wordle\n"
                "A random 5 letter word from a given list is generated.\n"
                "You must try and guess this word in 6 tries.\n"
                "You guess an existing 5 letter word, and "
                "each letter of the word is checked.\n"
                "A letter in the correct position is capitalised. "
                "And a letter which exists but is in the wrong position is "
                "displayed in lower case.\n"
                "Once you successfully guess the word or run out of lives, "
                "the game ends.\n"
                "You win if you guess the word!\n"
                "Good luck!\n";
        } else if (choice == "3") {
            return 0;
        } else {
            std::cout << "Invalid input, please try again.\n";
        }
    }
}