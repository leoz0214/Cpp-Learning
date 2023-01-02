#include "game.h"
#include <iostream>
#include <fstream>
#include <algorithm>


const std::string WHITESPACE = " \t";


// Reads the words from a file.
std::vector<std::string> get_words(std::string file_path) {
    std::ifstream file(file_path);
    std::string word;
    std::vector<std::string> words;
    while (std::getline(file, word)) {
        words.push_back(word);
    }
    return words;
}


// Removes leading and trailing whitespace of a string.
void strip_string(std::string& str) {
    str.erase(0, str.find_first_not_of(WHITESPACE));
    str.erase(str.find_last_not_of(WHITESPACE) + 1);
}


// Constructor of Game object
Game::Game() {
    srand(time(0));
    generate_random_word();
}


// Method running the actual Wordle gameplay.
int Game::play() {
    std::string word;
    bool correct = false;
    while (lives) {
        word = enter_word();
        correct = check_word(word);
        std::cout << "\n\n";
        for (std::string line : lines) {
            std::cout << line << '\n';
        }
        if (non_existent_letters != "") {
            std::cout
                << "\nNon-existent letters: " << non_existent_letters << '\n';
        }
        std::cout << "\n\n";
        if (correct) {
            return lives;
        }
        lives--;
    }
    // Out of guesses.
    std::cout
        << "You lose. The correct word is: " << target_word << '\n';
    return 0;
}


// Method to take valid user input (an existing 5 letter world)
std::string Game::enter_word() {
    bool valid = false;
    std::string word;
    while (!valid) {
        std::cout << "Enter a 5 letter word as your guess: ";
        std::getline(std::cin, word);
        strip_string(word);

        if (word.length() < 5) {
            std::cout << "Word too short, please try again.\n";
            continue;
        } else if (word.length() > 5) {
            std::cout << "Word too long, please try again.\n";
            continue;
        }

        // Keep consistent uppercase.
        std::transform(
            word.begin(), word.end(), word.begin(), ::toupper);
        valid = true;
        for (char letter : word) {
            if (!(letter >= 65 && letter <= 90)) {
                std::cout <<
                    "Only characters in the English alphabet "
                    "are allowed. Please try again.\n";
                valid = false;
                break;
            }
        }
        if (valid && !word_exists(word)) {
            std::cout << "Word does not exist. Please try again.\n";
            valid = false;
        }
    }
    return word;
}


// Checks that a user's input is indeed a real 5 letter word using
// binary search for maximum efficiency.
bool Game::word_exists(std::string word) {
    int first = 0;
    int last = valid_words.size() - 1;
    int midpoint = (first + last) / 2;
    int new_midpoint;
    while (true) {
        if (word == valid_words[midpoint]) {
            return true;
        } else if (word < valid_words[midpoint]) {
            last = midpoint - 1;
        } else {
            first = midpoint + 1;
        }
        new_midpoint = (first + last) / 2;
        if (new_midpoint == midpoint) {
            return false;
        }
        midpoint = new_midpoint;
    }
}


// Performs and stores comparisons between the user's guess and the actual word.
bool Game::check_word(std::string word) {
    if (word == target_word) {
        // Correct!
        lines.push_back(word);
        return true;
    }
    // The indexes holding letters that have been recognised.
    std::vector<int> used_indexes;
    std::string result;
    for (int i = 0; i < 5; i++) {
        if (word[i] == target_word[i]) {
            // Letter in the correct position.
            result += word[i];
            used_indexes.push_back(i);
        } else {
            bool letter_exists = false;
            for (int j = 0; j < 5; j++) {
                if (
                    word[i] == target_word[j] && word[j] != target_word[j] &&
                    std::find(
                        used_indexes.begin(),
                        used_indexes.end(), j) == used_indexes.end()
                ) {
                    // Letter exists, but somewhere else in the target word.
                    // Therefore display in lowercase.
                    result += (word[i] + 32);
                    letter_exists = true;
                    used_indexes.push_back(j);
                    break;
                }
            }
            if (!letter_exists) {
                result += '_';
                if (
                    target_word.find(word[i]) == std::string::npos &&
                    non_existent_letters.find(word[i]) == std::string::npos
                ) {
                    non_existent_letters += word[i];
                }
            }
        }
        result += ' ';
    }
    lines.push_back(result);
    return false;
}


// Selects a random word from the word bank (past real Wordle words).
void Game::generate_random_word() {
    target_word = possible_words[rand() % possible_words.size()];
}


std::vector<std::string> Game::possible_words = get_words("possible_words.txt");
std::vector<std::string> Game::valid_words = get_words("valid_words.txt");