
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"

class PhoneBook {
    private:
       Contact cntact[8];
       int counter;
       int y;
       int size;
    public:
        PhoneBook();
        void ADD();
        void SEARCH();   
};

#endif