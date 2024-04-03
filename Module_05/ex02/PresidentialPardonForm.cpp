#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon", 25, 5), target("Default") {
}
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon", 25, 5), target(target) {
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : AForm("Presidential Pardon", 25, 5) {
    *this = copy;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm& copy) {

    if(this != &copy)
        this->target = copy.target;
    return *this; 
}
PresidentialPardonForm::~PresidentialPardonForm() {
}

void PresidentialPardonForm::specificExecute() const {
    std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}