#include "Form.hpp"

int main()
{
    std::cout << "===== VALID CREATION TEST =====" << std::endl;
    try
    {
        Form f1("TaxForm", 50, 25);
        std::cout << f1 << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "===== INVALID CREATION TEST =====" << std::endl;
    try
    {
        Form f2("BadFormHigh", 0, 10);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Form f3("BadFormLow", 151, 10);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "===== SIGN FORMS TEST =====" << std::endl;
    Bureaucrat alice("Alice", 45);
    Form tax("TaxForm", 50, 25);

    alice.signForm(tax);
    std::cout << tax << std::endl;

    Bureaucrat bob("Bob", 60);
    Form report("Report", 50, 20);

    bob.signForm(report);
    std::cout << report << std::endl;

    return (0);
}