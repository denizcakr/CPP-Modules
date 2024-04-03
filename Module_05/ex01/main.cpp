
#include "Bureaucrat.hpp"
#include "Form.hpp"
int main()
{
    try{
        Bureaucrat a("Deniz", 110);
        Form b("Eymen", 140, 120);
        a.signForm(b);
    }
     catch(std::exception & e) {
        std::cout << e.what() << std::endl;
    }

    try{
        Bureaucrat b("Melike", 10);
        Form x("Ezgi", 5, 10);
        b.signForm(x);
    }
    catch(std::exception & e) {
        std::cout << e.what() << std::endl;
    }

    try{
        Bureaucrat c("Avatar", 100);
        std::cout << c << std::endl;
    }
    catch(std::exception & e) {
        std::cout << e.what() << std::endl;
    }
}