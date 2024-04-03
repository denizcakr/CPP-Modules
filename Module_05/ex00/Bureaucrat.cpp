#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(150) {
}

Bureaucrat::~Bureaucrat() {
}

Bureaucrat::Bureaucrat(const Bureaucrat& data) : name(data.getName()) {
    *this = data;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name) {
    this->setGrade(grade);
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& data) {
    this->grade = data.getGrade();
    return (*this);
}

std::string Bureaucrat::getName() const {
    return (this->name);
}

int Bureaucrat::getGrade() const {
    return (this->grade);
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return ("Careful, grade is too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return ("Careful, grade is too low!");
}

void Bureaucrat::incrementGrade() {
    setGrade(getGrade() - 1);
}

void Bureaucrat::decrementGrade() {
    setGrade(getGrade() + 1);
}

void Bureaucrat::setGrade(int number) {
    if(number < 1)
        throw GradeTooHighException();
    else if(number > 150)
        throw GradeTooLowException();
    this->grade = number;
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat &other) {
    os << other.getName() << ", bureaucrat grade " << other.getGrade() << std::endl;
    return os;
}
