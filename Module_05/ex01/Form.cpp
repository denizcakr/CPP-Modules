
#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string name, const int grade_sign, const int grade_exec) : name(name), grade_sign(grade_sign), grade_exec(grade_exec){
    this->sign = 0;
    if (grade_sign < 1 || grade_exec < 1)
        throw GradeTooHighException();
    else if (grade_sign > 150 || grade_exec > 150)
        throw GradeTooLowException();
}

Form::~Form() {
}
Form::Form(const Form& copy): name(copy.getName()), grade_sign(copy.getGradeSign()), grade_exec(copy.getGradeExec()){
    *this = copy;
}
Form &Form::operator=(const Form& copy) {
    this->sign = copy.getSign();
    return (*this);
}

std::string Form::getName() const {
    return(this->name);
}

int Form::getGradeSign() const {
    return (this->grade_sign);
}

int Form::getGradeExec() const {
    return (this->grade_exec);
}

bool Form::getSign() const {
    return (this->sign);
}

void Form::setSign(bool sign) {
    this->sign = sign;
}

const char* Form::GradeTooHighException::what() const throw() {
    return ("Form: grade is too high!");
}

const char* Form::GradeTooLowException::what() const throw() {
    return ("Form: grade is too low!");
}

std::ostream& operator<<(std::ostream& os, const Form& other) {
    os  << " signed " << other.getName() << std::endl;
    return os;
}

bool Form::beSigned(Bureaucrat& b_type){

    if(b_type.getGrade() <= this->getGradeSign())
        return (this->sign = 1);
    throw GradeTooLowException();
}