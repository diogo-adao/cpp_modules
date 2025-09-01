#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	fixed = 0;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	fixed = n << f_bits;
}

Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called" << std::endl;
	fixed = roundf(n * (1 << f_bits));
}

Fixed::Fixed(const Fixed& f)
{
	std::cout << "Copy constructor called" << std::endl;
	fixed = f.fixed;
}

Fixed& Fixed::operator=(const Fixed& f)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (&f != this)
		fixed = f.fixed;

	return (*this);
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (fixed);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	fixed = raw;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::toInt(void) const {
	return fixed >> f_bits;
}

float Fixed::toFloat(void) const {
	return (float)fixed / (1 << f_bits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& f) {
	os << f.toFloat();
	return os;
}

// ============ NEW FUNCTIONS ============
bool Fixed::operator>(const Fixed& other) const { return fixed > other.fixed; }
bool Fixed::operator<(const Fixed& other) const { return fixed < other.fixed; }
bool Fixed::operator>=(const Fixed& other) const { return fixed >= other.fixed; }
bool Fixed::operator<=(const Fixed& other) const { return fixed <= other.fixed; }
bool Fixed::operator==(const Fixed& other) const { return fixed == other.fixed; }
bool Fixed::operator!=(const Fixed& other) const { return fixed != other.fixed; }

Fixed Fixed::operator+(const Fixed& other) const {
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++() {
	++fixed;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	++fixed;
	return tmp;
}

Fixed& Fixed::operator--() {
	--fixed;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	--fixed;
	return tmp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return (a > b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return (a < b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return (a > b) ? a : b;
}
