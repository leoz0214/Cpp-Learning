#include <iostream>
#include <vector>
#include <algorithm>
#include "collatz.h"


namespace collatz {
    // Gets number of calculations before number ends in the 4-2-1 loop.
    unsigned int count(unsigned long long int number) {
        unsigned int count = 0;

        while (number != 1) {
            number = number % 2 == 0 ? number / 2 : 3 * number + 1;
            count++;
        }
        return count;
    }


    // Gets number in a range which takes the longest to reach the 4-2-1 loop.
    // If two numbers share the maximum, the smaller number is returned.
    unsigned int max_count(unsigned int start, unsigned int stop) {
        unsigned int max_number, max_count, c;
        max_count = 0;

        for (unsigned int n = start; n <= stop; n++) {
            c = count(n);
            if (c > max_count) {
                max_number = n;
                max_count = c;
            }
        }
        return max_number;
    }


    // Gets number in a range which takes the shortest to reach the 4-2-1 loop.
    // If two numbers share the minimum, the smaller number is returned.
    unsigned int min_count(unsigned int start, unsigned int stop) {
        unsigned int min_number, min_count, c;
        min_number = start;
        min_count = count(start);

        for (unsigned int n = start; n <= stop; n++) {
            c = count(n);
            if (c < min_count) {
                min_number = n;
                min_count = c;
            }
        }
        return min_number;
    }


    // Displays sequence from starting number to 1.
    void visualise_sequence(unsigned long long int number) {
        std::cout << number;
        while (number != 1) {
            number = number % 2 == 0 ? number / 2 : 3 * number + 1;
            std::cout << " -> " << number;
        }
    }


    // Displays reverse sequence from 1 to original number.
    void visualise_reverse_sequence(unsigned long long int number) {
        std::vector<unsigned long long int> numbers = {number};

        while (number != 1) {
            number = number % 2 == 0 ? number / 2 : 3 * number + 1;
            // Efficient insertion of current number to start of vector.
            numbers.push_back(number);
            std::rotate(
                numbers.rbegin(), numbers.rbegin() + 1, numbers.rend());
        }
        
        bool first = true;
        for (unsigned long long int number : numbers) {
            if (first) {
                std::cout << number;
                first = false;
                continue;
            }
            std::cout << " -> " << number;
        }
    }
}