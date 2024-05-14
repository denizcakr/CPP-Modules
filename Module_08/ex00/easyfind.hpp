
#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <exception>
#include <string>

class NumberNotFound: public std::exception{
    const char *what() const throw(){
        return "Number not found in the contanier.";
    }
};

template<typename T>
int  easyfind(T &a, int sec){
    typename T::iterator it = std::find(a.begin(), a.end(), sec);
        if (it != a.end())
            return (sec);
    throw (NumberNotFound());
}

#endif