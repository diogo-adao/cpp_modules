#include <cstdlib>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    srand(time(NULL));

    Bureaucrat alice("Alice", 140);
    Bureaucrat bob("Bob", 50);
    Bureaucrat charlie("Charlie", 1);

    Intern someRandomIntern;
    AForm* rrf;

    rrf = someRandomIntern.makeForm("shrubbery creation", "Garden");
    if (rrf) {
        alice.signForm(*rrf);
        alice.executeForm(*rrf);
        delete rrf;
    }

    rrf = someRandomIntern.makeForm("robotomy request", "Wall-E");
    if (rrf) {
        bob.signForm(*rrf);
        bob.executeForm(*rrf);
        delete rrf;
    }

    rrf = someRandomIntern.makeForm("presidential pardon", "Arthur");
    if (rrf) {
        charlie.signForm(*rrf);
        charlie.executeForm(*rrf);
        delete rrf;
    }

    rrf = someRandomIntern.makeForm("invalid form", "Nobody");

    return 0;
}