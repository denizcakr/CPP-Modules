
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
    private:
        int fixed;
        static const int _fixed = 8;
    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed &);
        Fixed &operator=(const Fixed &);
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif
