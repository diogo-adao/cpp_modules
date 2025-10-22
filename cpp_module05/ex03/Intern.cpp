#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& src) { (void)src; }

Intern& Intern::operator=(const Intern& src)
{
    (void)src;
    return *this;
}

Intern::~Intern() {}

struct FormPair {
    const char *name;
    AForm* (*create)(const std::string& target);
};

AForm* createShrubbery(const std::string& target) { return new ShrubberyCreationForm(target); }
AForm* createRobotomy(const std::string& target) { return new RobotomyRequestForm(target); }
AForm* createPardon(const std::string& target) { return new PresidentialPardonForm(target); }

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
    FormPair forms[] = {
        {"shrubbery creation", &createShrubbery},
        {"robotomy request", &createRobotomy},
        {"presidential pardon", &createPardon}
    };

    for (int i = 0; i < 3; ++i)
    {
        if (formName == forms[i].name) {
            std::cout << "Intern creates " << formName << std::endl;
            return forms[i].create(target);
        }
    }

    std::cout << "Intern couldn't find form called " << formName << std::endl;
    return NULL;
}