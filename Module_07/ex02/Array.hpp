
#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template<typename T>
class Array
{
    private:
        T *elements;
        unsigned int Size;
    public:
        Array();
        ~Array();
        Array &operator=(const Array &);
        Array(const Array &);
        Array(unsigned int n);
        T &operator[](unsigned int i);
        unsigned int size() const;
};

#include "Array.tpp"

#endif