#include "PresidentialPardonForm.hpp"

// CONSTRUCTOR
PresidentialPardonForm::PresidentialPardonForm(const std::string& t) : AForm("PresidentialPardonForm", 25, 5), target(t) {}

// COPY CONSTRUCTOR
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) : AForm(src), target(src.target) {}

// COPY ASSIGNMENT
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& src)
{
    if (this != &src)
        target = src.target;

    return *this;
}

// DESTRUCTOR
PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::executeAction() const
{
    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}