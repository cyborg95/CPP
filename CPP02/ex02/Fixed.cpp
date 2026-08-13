#include "Fixed.hpp"

Fixed::Fixed() : value(0) {
    std::cout << "Default constructor called" << std::endl;

}

Fixed::Fixed(const int n)
{
    std::cout << "Int constructor called" << std::endl;
    value = n << fractional_bits;
}

Fixed::Fixed(const float f)
{
    std::cout << "Float constructor called" << std::endl;

    value = static_cast<int>(roundf(f * (1 << fractional_bits)));
}

Fixed::Fixed(const Fixed& other) : value(other.value) {
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        value = other.value;
    }
    return *this;
}

float Fixed::toFloat(void) const
{
    return static_cast<float>(value) / (1 << fractional_bits);
}

int Fixed::toInt(void) const
{
    return value >> fractional_bits;
}

int Fixed::getRawBits() const {
    return value;
}

void Fixed::setRawBits(int raw) {
    value = raw;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return out;
}

bool Fixed::operator>(const Fixed& other) const
{
    return value > other.value;
}

bool Fixed::operator<(const Fixed& other) const
{
    return value < other.value;
}

bool Fixed::operator>=(const Fixed& other) const
{
    return value >= other.value;
}

bool Fixed::operator<=(const Fixed& other) const
{
    return value <= other.value;
}

bool Fixed::operator==(const Fixed& other) const
{
    return value == other.value;
}

bool Fixed::operator!=(const Fixed& other) const
{
    return value != other.value;
}

Fixed Fixed::operator+(const Fixed& other) const
{
    Fixed result;

    result.value = value + other.value;

    return result;
}

Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed result;

    result.value = value - other.value;

    return result;
}

Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed result;

    result.value =
        (value * other.value) >> fractional_bits;

    return result;
}

Fixed Fixed::operator/(const Fixed& other) const
{
    Fixed result;

    if (other.value == 0)
    {
        std::cout << "Error: division by zero" << std::endl;
        return result;
    }

    result.value =
        (value << fractional_bits) / other.value;

    return result;
}

Fixed& Fixed::operator++()
{
    ++value;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed old(*this);

    ++value;

    return old;
}

Fixed& Fixed::operator--()
{
    --value;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed old(*this);

    --value;

    return old;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if (a < b)
        return a;

    return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a < b)
        return a;

    return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if (a > b)
        return a;

    return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a > b)
        return a;

    return b;
}