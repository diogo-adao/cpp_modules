#include "ShrubberyCreationForm.hpp"
#include <fstream>

// CONSTRUCTOR
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& t) : AForm("ShrubberyCreationForm", 145, 137), target(t) {}

// COPY CONSTRUCTOR
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) : AForm(src), target(src.target) {}

// COPY ASSIGNMENT
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
    if (this != &src)
        target = src.target;

    return *this;
}

// DESTRUCTOR
ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::executeAction() const
{
    std::ofstream file((target + "_shrubbery").c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file");
    }

    file << "       _-_\n";
    file << "    /~~   ~~\\\n";
    file << " /~~         ~~\\\n";
    file << "{               }\n";
    file << " \\  _-     -_  /\n";
    file << "   ~  \\\\ //  ~\n";
    file << "_- -   | | _- _\n";
    file << "  _ -  | |   -_\n";
    file << "      // \\\n";
}
