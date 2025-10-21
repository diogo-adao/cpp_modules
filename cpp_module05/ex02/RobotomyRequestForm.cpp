#include "RobotomyRequestForm.hpp"
#include <cstdlib>

// CONSTRUCTOR
RobotomyRequestForm::RobotomyRequestForm(const std::string& t) : AForm("RobotomyRequestForm", 72, 45), target(t) {}

// COPY CONSTRUCTOR
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) : AForm(src), target(src.target) {}

// COPY ASSIGNMENT
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
    if (this != &src)
        target = src.target;

    return *this;
}

// DESTRUCTOR
RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::executeAction() const
{
    std::cout << "Bzzz... Bzzz... *drilling noises*" << std::endl;

    if (rand() % 2 == 0)
        std::cout << target << " has been robotomized successfully " << std::endl;
    else
        std::cout << "Robotomy failed" << std::endl;
}
