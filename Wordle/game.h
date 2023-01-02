#pragma once
#ifndef GAME_H
#define GAME_H
#include <string>
#include <vector>


std::vector<std::string> get_words(std::string file_path);
void strip_string(std::string& str);


class Game {
    public:
        std::string target_word;

        Game();
        int play();
    private:
        static std::vector<std::string> possible_words;
        static std::vector<std::string> valid_words;
        std::vector<std::string> lines;
        std::string non_existent_letters;
        int lives = 6;

        std::string enter_word();
        bool word_exists(std::string word);
        bool check_word(std::string word);
        void generate_random_word();
};


#endif