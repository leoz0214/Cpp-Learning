#include <cmath>
#include <string>
#include <iostream>
#include "number.h"


bool Number::is_prime(int number) {
    if (number < 2) {
        return false;
    } else if (number == 2) {
        return true;
    } else if (number % 2 == 0) {
        return false;
    }

    for (int i = 3; i <= sqrt(number) + 1; i += 2) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}


bool Number::is_square(long long int number) {
    if (number < 1) {
        return false;
    }
    long long int x = 1;
    while (pow(x, 2) < number) {
        x++;
    }
    return pow(x, 2) == number;
};


bool Number::is_cube(long long int number) {
    unsigned long long int absolute = abs(number);
    if (number == 0) {
        return false;
    }
    unsigned long long int x = 1;
    while (pow(x, 3) < absolute) {
        x++;
    }
    return pow(x, 3) == absolute;
};


bool Number::is_triangular(int number) {
    return number >= 1 && fmod((sqrt(8 * number + 1) - 1), 2) == 0;
};


bool Number::is_pentagonal(int number) {
    return number >= 1 && fmod((sqrt(24 * number + 1) + 1), 6) == 0;
};


bool Number::is_hexagonal(int number) {
    return number >= 1 && fmod((sqrt(8 * number + 1) + 1), 4) == 0;
};


bool Number::is_octagonal(int number) {
    return number >= 1 && fmod((sqrt(12 * number + 4) + 2), 6) == 0;
};


bool Number::is_palindrome(int number) {
    if (number < 0) {
        // Minus sign disallows negative numbers to be palindromes.
        return false;
    }
    std::string number_string = std::to_string(number);
    std::string reversed_string(
        number_string.rbegin(), number_string.rend());
    return number_string == reversed_string;
};


bool Number::is_perfect(int number) {
    if (number < 6) {
        return false;
    }
    int total = square ? sqrt(number) + 1 : 1;
    for (int i = 2; i < sqrt(number); i++) {
        if (number % i == 0) {
            total += i;
            total += (number / i);
        }
    }
    return total == number;
};


Number::Number(int number) {
    value = number;
    odd = abs(number) % 2 == 1;
    even = !odd;
    prime = is_prime(number);
    composite = (!prime) && number > 1;
    square = is_square(number);
    cube = is_cube(number);
    triangular = is_triangular(number);
    pentagonal = is_pentagonal(number);
    hexagonal = is_hexagonal(number);
    octagonal = is_octagonal(number);
    palindrome = is_palindrome(number);
    perfect = is_perfect(number);
};


int Number::get_value() {return value;}
bool Number::is_odd() {return odd;}
bool Number::is_even() {return even;}
bool Number::is_prime() {return prime;}
bool Number::is_composite() {return composite;}
bool Number::is_square() {return square;}
bool Number::is_cube() {return cube;}
bool Number::is_triangular() {return triangular;}
bool Number::is_pentagonal() {return pentagonal;}
bool Number::is_hexagonal() {return hexagonal;}
bool Number::is_octagonal() {return octagonal;}
bool Number::is_palindrome() {return palindrome;}
bool Number::is_perfect() {return perfect;}


std::ostream& operator << (std::ostream &output, Number number) {
    output << number.get_value() << " is an ";
    output << (number.is_odd() ? "odd" : "even") << " number.\n";
    output << "Prime      - " << (number.is_prime() ? "Yes" : "No") << '\n';
    output << "Composite  - " << (number.is_composite() ? "Yes" : "No") << '\n';
    output << "Square     - " << (number.is_square() ? "Yes" : "No") << '\n';
    output << "Cube       - " << (number.is_cube() ? "Yes" : "No") << '\n';
    output << "Triangular - " << (number.is_triangular() ? "Yes" : "No") << '\n';
    output << "Pentagonal - " << (number.is_pentagonal() ? "Yes" : "No") << '\n';
    output << "Hexagonal  - " << (number.is_hexagonal() ? "Yes" : "No") << '\n';
    output << "Octagonal  - " << (number.is_octagonal() ? "Yes" : "No") << '\n';
    output << "Palindrome - " << (number.is_palindrome() ? "Yes" : "No") << '\n';
    output << "Perfect    - " << (number.is_perfect() ? "Yes" : "No") << '\n';
    return output;
}