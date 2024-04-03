#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {
}

Intern::Intern(const Intern& copy) {
    *this = copy;
}

Intern &Intern::operator=(const Intern& copy) {
    (void)copy;
    return(*this);
}

Intern::~Intern(){}

const char* Intern::FormNotFoundException::what() const throw() {
    return ("Intern : form not found");
}

AForm* Intern::makeShrubberyCreationForm(std::string target) {
    std::cout << "Intern creates Shrubbery Creation Form" << std::endl;
    return (new ShrubberyCreationForm(target));
}

AForm* Intern::makeRobotomyRequestForm(std::string target) {
    std::cout << "Intern creates Robotomy Request Form" << std::endl;
    return (new RobotomyRequestForm(target));
}

AForm* Intern::makePresidentialPardonForm(std::string target) {
    std::cout << "Intern creates Presidential Pardon Form" << std::endl;
    return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string name, std::string target) {
    std::string names[3] = {
        "presidential pardon",
        "robotomy request",
        "shrubbery creation"
    };

    AForm* (Intern::*ptr[3])(std::string) = {
        &Intern::makePresidentialPardonForm,
        &Intern::makeRobotomyRequestForm,
        &Intern::makeShrubberyCreationForm,
    };
    
    for (size_t i = 0; i < 3; ++i) {
        if (names[i] == name)
            return (this->*ptr[i])(target);
    }
    throw Intern::FormNotFoundException();
}