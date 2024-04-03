#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::~AForm() {
}

AForm::AForm(std::string name, const int grade_sign, const int grade_exec) : name(name), grade_sign(grade_sign), grade_exec(grade_exec) {
    this->sign = 0;
    if (grade_sign < 1 || grade_exec < 1)
        throw GradeTooHighException();
    else if (grade_sign > 150 || grade_exec > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& copy): name(copy.getName()), grade_sign(copy.getGradeSign()), grade_exec(copy.getGradeExec()) {
    *this = copy;
}

AForm &AForm::operator=(const AForm& copy) {
    this->sign = copy.getSign();
    return (*this);
}

std::string AForm::getName() const {
    return(this->name);
}

int AForm::getGradeSign() const{
    return (this->grade_sign);
}

int AForm::getGradeExec() const {
    return (this->grade_exec);
}

bool AForm::getSign() const {
    return (this->sign);
}

void AForm::setSign(bool sign) {
    this->sign = sign;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return ("AForm: grade is too high!");
}

const char* AForm::GradeTooLowException::what() const throw() {
    return ("AForm: grade is too low!");
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "AForm: Form not signed!";
};

std::ostream& operator<<(std::ostream& os, const AForm& other) {
    os  << " signed " << other.getName() << std::endl;
    return os;
}

bool AForm::beSigned(Bureaucrat& b_type) {
    if(b_type.getGrade() <= this->getGradeSign())
        return (this->sign = 1);
    throw GradeTooLowException();
}

void AForm::execute(Bureaucrat const & executor) const {

    if(!sign)
        throw FormNotSignedException();
    if(executor.getGrade() >= this->getGradeExec())
        throw GradeTooLowException();
    specificExecute();
}