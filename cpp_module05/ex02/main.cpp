#include <cstdlib>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    srand(time(NULL));

    Bureaucrat alice("Alice", 1);
    Bureaucrat bob("Bob", 150);

    std::cout << "========= FORMS CREATION =========\n";
    ShrubberyCreationForm shrub("Garden");
    RobotomyRequestForm robot("Marvin");
    PresidentialPardonForm pardon("Zaphod");

    std::cout << shrub << std::endl;
    std::cout << robot << std::endl;
    std::cout << pardon << std::endl;

    std::cout << "\n========= SIGNING FORMS =========\n";
    alice.signForm(shrub);
    alice.signForm(robot);
    alice.signForm(pardon);

    std::cout << std::endl;
    std::cout << shrub << std::endl;
    std::cout << robot << std::endl;
    std::cout << pardon << std::endl;

    std::cout << "\n========= EXECUTING FORMS =========\n";
    alice.executeForm(shrub);
    alice.executeForm(robot);
    alice.executeForm(robot);
    alice.executeForm(pardon);

    std::cout << "\n========= EXCEPTION HANDLING =========\n";
    ShrubberyCreationForm unsignedForm("Forest");
    alice.executeForm(unsignedForm);
    bob.signForm(shrub);
    bob.executeForm(shrub);

    return 0;
}