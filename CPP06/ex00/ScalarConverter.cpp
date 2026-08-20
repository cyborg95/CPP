#include "ScalarConverter.hpp"
#include <cstdlib>
#include <cctype>
#include <iomanip>
#include <sstream>
#include <limits>

static bool isChar(const std::string& s)
{
    return s.length() == 1 && !std::isdigit(s[0]);
}

static bool isPseudoLiteral(const std::string& s)
{
    return s == "nan" || s == "+inf" || s == "-inf"
        || s == "nanf" || s == "+inff" || s == "-inff";
}

static bool isFloat(const std::string& s)
{
    if (s.length() < 2 || s[s.length() - 1] != 'f')
        return false;

    std::istringstream iss(s.substr(0, s.length() - 1));
    double value;
    char extra;

    return (iss >> value) && !(iss >> extra);
}

static bool isDouble(const std::string& s)
{
    std::istringstream iss(s);
    double value;
    char extra;

    return (iss >> value) && !(iss >> extra);
}

void ScalarConverter::convert(const std::string& literal)
{
    if (isChar(literal))
    {
        char c = literal[0];

        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
        return;
    }

    if (isPseudoLiteral(literal))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;

        if (literal == "nan" || literal == "nanf")
        {
            std::cout << "float: nanf" << std::endl;
            std::cout << "double: nan" << std::endl;
        }
        else if (literal == "+inf" || literal == "+inff")
        {
            std::cout << "float: +inff" << std::endl;
            std::cout << "double: +inf" << std::endl;
        }
        else
        {
            std::cout << "float: -inff" << std::endl;
            std::cout << "double: -inf" << std::endl;
        }
        return;
    }

    double value;

    if (isFloat(literal))
        value = std::atof(literal.c_str());
    else if (isDouble(literal))
        value = std::atof(literal.c_str());
    else
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    if (value < 0 || value > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<int>(value)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;

    if (value < -2147483648.0 || value > 2147483647.0)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;

    std::cout << "float: " << static_cast<float>(value);

    if (value == static_cast<int>(value))
        std::cout << ".0";

    std::cout << "f" << std::endl;

    std::cout << "double: " << value;

    if (value == static_cast<int>(value))
        std::cout << ".0";

    std::cout << std::endl;
}

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { (void)other; return *this; }

ScalarConverter::~ScalarConverter() {}
