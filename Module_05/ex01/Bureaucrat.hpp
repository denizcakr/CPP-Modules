#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Form;

class Bureaucrat {

    private:
        const std::string name;
        int grade;
        void setGrade(int number);
    public:
        Bureaucrat();
        ~Bureaucrat();
        Bureaucrat(std::string name);
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat& copy);
        Bureaucrat &operator=(const Bureaucrat& copy);
        
        std::string getName() const;
        int getGrade() const;
        
        void incrementGrade(int number);
        void decrementGrade(int number);

        class GradeTooHighException : public std::exception{
            const char* what() const throw();
        };
        class GradeTooLowException : public std::exception{
            const char* what() const throw();
        };

        void signForm(Form& form);
};

std::ostream &operator<<(std::ostream& os, const Bureaucrat&);

#endif