#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

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
        Bureaucrat(const Bureaucrat &);
        Bureaucrat &operator=(const Bureaucrat &);
        void incrementGrade();
        void decrementGrade();
        std::string getName() const;
        int getGrade() const;
        

        class GradeTooHighException : public std::exception {
            const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            const char* what() const throw();
        };
};

std::ostream &operator<<(std::ostream& os, const Bureaucrat& other);

#endif