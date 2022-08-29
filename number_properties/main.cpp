#include <iostream>
#include "number.h"


int main() {
    int number;
    while (true) {
        std::cout << "Enter a number to find its properties.\n";
        std::cout << "Minimum: -2147483648, Maximum: 2147483647\n>";
        std::cin >> number;

        std::cout << '\n' << Number(number) << '\n';
    }
}