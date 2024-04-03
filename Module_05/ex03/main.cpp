#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main()
{
    {
        Intern someRandomIntern;
        AForm *tmp = 0;
        try
        {
            Bureaucrat data("Deniz", 42);
            tmp = someRandomIntern.makeForm("shrubbery creation", "test1");
            if(tmp)
            {
                data.signAForm(*tmp);
                data.executeForm(*tmp);
                delete tmp;
            }
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
            delete tmp;
        }
    }

    std::cout << " " << std::endl;

    {
        Intern someRandomIntern;
        AForm *tmp = 0;
        try
        {
            Bureaucrat data2("Zuko", 42);
            tmp = someRandomIntern.makeForm("robotomy request", "test2");
            if(tmp)
            {
                data2.signAForm(*tmp);
                data2.executeForm(*tmp);
                delete tmp;
            }
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
            delete tmp;
        }
    }
    
    std::cout << " " << std::endl;

    {
        Intern someRandomIntern;
        AForm *tmp = 0;
        try
        {
            Bureaucrat data3("Katara", 5);
            tmp = someRandomIntern.makeForm("presidential pardon", "test3");
            if(tmp)
            {
                data3.signAForm(*tmp);
                data3.executeForm(*tmp);
                delete tmp;
            }
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
            delete tmp;
        }
    }
}
