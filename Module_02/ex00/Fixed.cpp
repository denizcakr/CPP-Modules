
#include "Fixed.hpp"

Fixed::Fixed() : fixed(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &data)
{
    this->fixed = data.fixed;
    std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &data)
{
    std::cout << "Copy assignment operator called" << std::endl;
        this->fixed = data.getRawBits();
        return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return fixed;
}

void Fixed::setRawBits(int const raw)
{   
    fixed = raw;
}
