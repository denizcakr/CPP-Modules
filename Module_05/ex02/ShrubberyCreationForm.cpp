#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm::AForm("Shrubbery Creation", 145, 137), target("Default"){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm::AForm("Shrubbery Creation", 145, 137), target(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm::AForm("Shrubbery Creation", 145, 137){
    *this = copy;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy) {
    if(this != &copy)
        this->target = copy.target;
    return *this; 
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

void ShrubberyCreationForm::specificExecute() const {
    std::ofstream file((target + "_shrubbery").c_str());

        if (file.is_open())
        {
            file << "        *" << std::endl;
            file << "       /|\\" << std::endl;
            file << "      / | \\" << std::endl;
            file << "     /  |  \\" << std::endl;
            file << "    /   |   \\" << std::endl;
            file << "   /    |    \\" << std::endl;
            file << "  /     |     \\" << std::endl;
            file << " /      |      \\" << std::endl;
            file << "/_______|_______\\" << std::endl;
            file << "    |||||||||" << std::endl;
            file << "    |||||||||" << std::endl;
            file << "    ---------" << std::endl;
            file.close();
        }
        else
            std::cout << "File not found" << std::endl;
}