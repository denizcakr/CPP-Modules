
#include "Fixed.hpp"

Fixed::Fixed()
{
    holder = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i_fixed)
{
    holder = i_fixed << _fixed;
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f_fixed)
{
    holder = roundf(f_fixed * (1 << _fixed));
    std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &data)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = data;
}

Fixed &Fixed::operator=(const Fixed &data)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->holder = data.holder;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}

int Fixed::toInt(void) const
{
    int i_back = holder >> _fixed;
    return (i_back);
}

float Fixed::toFloat(void) const
{
    float f_back = (float)holder / (float)(1 << _fixed);
    return (f_back);
}
