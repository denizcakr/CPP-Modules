#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request", 72, 45), target("Default") {
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request", 72, 45), target(target) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm("Robotomy Request", 72, 45) {
    *this = copy;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm& copy) {

    if(this != &copy)
        this->target = copy.target;
    return *this; 
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

void RobotomyRequestForm::specificExecute() const {
    std::srand(time(0));
    bool success = std::rand() % 2 == 0;

    std::cout << "* DRILLING NOISES *" << std::endl;
    if (success)
        std::cout << target << " has been robotomized successfully." << std::endl;
    else
        std::cout << "ROBOTOMY " << target << " failed."  << std::endl;
}
