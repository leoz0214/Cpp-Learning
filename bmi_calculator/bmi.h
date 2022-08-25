#ifndef BMI_CALCULATOR
#define BMI_CALCULATOR

#include <string>

const std::string VALID_HEIGHT_UNITS[5] = {"m", "cm", "ft", "in", "ftin"};
const std::string VALID_WEIGHT_UNITS[3] = {"kg", "st", "lb"};

bool valid_unit(std::string value, std::string value_type);
void set_units(std::string current[2]);
void calculator(std::string units[2]);
void about_bmi();

#endif