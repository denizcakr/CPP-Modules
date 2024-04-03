#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

int main()
{
    {
        AForm *value = NULL;
        try
        {
            value = new ShrubberyCreationForm("AvatarAirGarden");
            Bureaucrat data("Aang", 136);

            data.signAForm(*value);
            data.executeForm(*value);
            delete value;
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
            delete value;
        }
    }

    std::cout << " " << std::endl;

    {
        AForm *value = NULL;
        try
        {
            value = new RobotomyRequestForm("Zuko");
            Bureaucrat data("Sokka", 10);

            data.signAForm(*value);
            data.executeForm(*value);
            delete value;
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
            delete value;
        }
    }

    std::cout << " " << std::endl;

    {
        AForm *value = NULL;
        try
        {
            value = new PresidentialPardonForm("Katara");
            Bureaucrat data("Toph", 5);

            data.signAForm(*value);
            data.executeForm(*value);
            delete value;
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
            delete value;
        }
    }

    return 0;
}
