#ifndef COLLATZ
#define COLLATZ

#include <string>

enum Modes {calculation_count, visual, reverse_visual, max_count, min_count};

const std::string MENU_RETURN =
"\nEnter -1 at any time to return to the menu.\n";

const std::string ABOUT_COLLATZ_CONJECTURE = 
"\n----- About ------\n"
"The Collatz conjecture is an unsolved mathematical problem,\n"
"very easy to understand, but notoriously difficult, "
"if not impossible to solve.\n"
"\nHere's how it works:\n"
"Start with any positive integer.\n"
"If the number is even, divide it by 2, and "
"if the number is odd, multiply it by 3, and add 1.\n"
"This process is repeated until the original number reaches 1, "
"where it gets stuck in an infinite 4-2-1 loop.\n"
"\nThe Collatz conjecture states that this is "
"true for all positive integers.\n"
"\nFor example, this is how 3 would end up as 1:\n"
"3 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1\n"
"\nFor more information, check out the Wikipedia page:\n"
"https://en.wikipedia.org/wiki/Collatz_conjecture\n";

namespace collatz {
    unsigned int count(unsigned long long int number);
    unsigned int max_count(unsigned int first, unsigned int last);
    unsigned int min_count(unsigned int first, unsigned int last);

    void visualise_sequence(unsigned long long int number);
    void visualise_reverse_sequence(unsigned long long int number);
}

#endif