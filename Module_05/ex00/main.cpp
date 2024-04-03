
#include "Bureaucrat.hpp"

int main()
{
    try {
        Bureaucrat a("Ezgi", 160);
    }
    catch(std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        Bureaucrat b("Eymen", -1);
    }
    catch(std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        Bureaucrat c("Melike", 100);
        std::cout << c;
    }
    catch(std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        Bureaucrat d("Deniz", 5);
        for (size_t i = 0; i < 6; i++)
        {
            if (i == 0)
                std::cout << d;
            d.incrementGrade();
            std::cout << d;
        }
    }
    catch(std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}
