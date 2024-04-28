
#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
    elements = NULL;
    Size = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
    elements = new T[n];
    Size = n;
}

template <typename T>
Array<T>::Array(const Array &other)
{
    Size = other.Size;
    elements = new T[Size];
    for(unsigned int i = 0; i < Size; i++)
        elements[i] = other.elements[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
    if(elements)
        delete[] elements;
    Size = other.Size;
    elements = new T[Size];
    Size = other.Size;
    for(int i = 0; i < Size; i++)
        elements[i] = other.elements[i];
    return (*this);
}

template <typename T>
Array<T>::~Array()
{
    delete[] elements;
}

template <typename T>
T &Array<T>::operator[](unsigned int i)
{
    if(i < 0 || i >= Size)
        throw std::out_of_range("Index is out of range");
    return elements[i];
}

template <typename T>
unsigned int Array<T>::size() const
{
    return Size;
}

#endif