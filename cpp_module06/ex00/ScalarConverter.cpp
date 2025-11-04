#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& src) { (void)src; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& src)
{
    (void)src;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

static int detectType(const std::string& literal)
{
    if (literal == "nan" || literal == "+inf" || literal == "-inf" || literal == "inf")
        return ScalarConverter::SPECIAL_T;
    if (literal == "nanf" || literal == "+inff" || literal == "-inff" || literal == "inff")
        return ScalarConverter::SPECIAL_T;

    if (literal.length() == 1 && !std::isdigit(literal[0]))
        return ScalarConverter::CHAR_T;

    bool hasDot = false;
    bool hasF   = false;
    bool valid  = true;
    size_t i = 0;

    if (literal[i] == '+' || literal[i] == '-')
        i++;

    for (; i < literal.length(); i++)
    {
        if (literal[i] == '.')
        {
            if (hasDot) { valid = false; break; }
            hasDot = true;
        }
        else if (literal[i] == 'f' && i == literal.length() - 1)
            hasF = true;
        else if (!std::isdigit(literal[i]))
        {
            valid = false;
            break;
        }
    }

    if (!valid)
        return ScalarConverter::INVALID_T;

    if (hasDot && hasF)
        return ScalarConverter::FLOAT_T;
    else if (hasDot)
        return ScalarConverter::DOUBLE_T;
    else if (!hasDot && !hasF)
        return ScalarConverter::INT_T;

    return ScalarConverter::INVALID_T;
}

void ScalarConverter::convert(const std::string& literal)
{
    int type = detectType(literal);
    std::cout << std::fixed << std::setprecision(1);

    if (type == CHAR_T)
    {
        char c = literal[0];

        int i = static_cast<int>(c);
        float f = static_cast<float>(c);
        double d = static_cast<double>(c);

        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << i << std::endl;
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
    }
    else if (type == INT_T)
    {
        errno = 0;
        long value = strtol(literal.c_str(), NULL, 10);

        if (errno == ERANGE || value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;

            double d = strtod(literal.c_str(), NULL);
            float f = static_cast<float>(d);

            std::cout << "float: " << f << "f" << std::endl;
            std::cout << "double: " << d << std::endl;
            return;
        }

        int i = static_cast<int>(value);
        char c = static_cast<char>(i);
        float f = static_cast<float>(i);
        double d = static_cast<double>(i);

        if (i < 0 || i > 127)
            std::cout << "char: impossible" << std::endl;
        else if (!std::isprint(c))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: '" << c << "'" << std::endl;

        std::cout << "int: " << i << std::endl;
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
    }
    else if (type == FLOAT_T)
    {
        float f = strtof(literal.c_str(), NULL);

        double d = static_cast<double>(f);

        if (std::isinf(f) || std::isnan(f))
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: " << f << "f" << std::endl;
            std::cout << "double: " << d << std::endl;
            return;
        }

        char c = static_cast<char>(f);
        int i = static_cast<int>(f);

        if (f < 0 || f > 127)
            std::cout << "char: impossible" << std::endl;
        else if (!std::isprint(c))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: '" << c << "'" << std::endl;

        if (f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max())
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << i << std::endl;

        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
    }
    else if (type == DOUBLE_T)
    {
        double d = strtod(literal.c_str(), NULL);

        float f = static_cast<float>(d);

        if (std::isinf(d) || std::isnan(d))
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: " << f << "f" << std::endl;
            std::cout << "double: " << d << std::endl;
            return;
        }

        char c = static_cast<char>(d);
        int i = static_cast<int>(d);

        if (d < 0 || d > 127)
            std::cout << "char: impossible" << std::endl;
        else if (!std::isprint(c))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: '" << c << "'" << std::endl;

        if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << i << std::endl;

        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
    }
    else if (type == SPECIAL_T)
    {
        if (literal == "nan" || literal == "nanf")
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: nanf" << std::endl;
            std::cout << "double: nan" << std::endl;
        }
        else if (literal == "+inf" || literal == "+inff" || literal == "inf" || literal == "inff")
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: inff" << std::endl;
            std::cout << "double: inf" << std::endl;
        }
        else if (literal == "-inf" || literal == "-inff")
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: -inff" << std::endl;
            std::cout << "double: -inf" << std::endl;
        }
    }
    else if (type == INVALID_T)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}
