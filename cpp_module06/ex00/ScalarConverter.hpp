#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cerrno>
#include <limits>

class ScalarConverter {
    public:
        enum type {
            CHAR_T,
            INT_T,
            FLOAT_T,
            DOUBLE_T,
            SPECIAL_T,
            INVALID_T
        };

        static void convert(const std::string& literal);
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& src);
        ScalarConverter& operator=(const ScalarConverter& src);
        ~ScalarConverter();
};

#endif
