#ifndef NUMBER_PROPERTIES
#define NUMBER_PROPERTIES


class Number {
    int value;
    bool odd, even, prime, composite, square, cube,
    triangular, pentagonal, hexagonal, octagonal, palindrome, perfect;

    bool is_prime(int number);
    bool is_square(long long int number);
    bool is_cube(long long int number);
    bool is_triangular(int number);
    bool is_pentagonal(int number);
    bool is_hexagonal(int number);
    bool is_octagonal(int number);
    bool is_palindrome(int number);
    bool is_perfect(int number);

    public:
        Number(int number);
        int get_value();
        bool is_odd();
        bool is_even();
        bool is_prime();
        bool is_composite();
        bool is_square();
        bool is_cube();
        bool is_triangular();
        bool is_pentagonal();
        bool is_hexagonal();
        bool is_octagonal();
        bool is_palindrome();
        bool is_perfect();
};

std::ostream& operator << (std::ostream &output, Number number);

#endif