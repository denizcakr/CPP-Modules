
#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern {
	public:
		Intern();
		~Intern();
		Intern(const Intern& copy);
		Intern &operator=(const Intern& copy);

		AForm* makeForm(std::string name, std::string target);

		AForm* makeShrubberyCreationForm(std::string target);
		AForm* makeRobotomyRequestForm(std::string target);
		AForm* makePresidentialPardonForm(std::string target);

		class FormNotFoundException: public std::exception {
            const char* what() const throw();
        };
};

#endif