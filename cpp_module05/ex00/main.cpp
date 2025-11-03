#include "Bureaucrat.hpp"

int main()
{
    std::cout << "========= VALID CREATION TEST =========" << std::endl;
    try
    {
        Bureaucrat a("Alice", 42);
        std::cout << a << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "========= INVALID CREATION TEST =========" << std::endl;
    try
    {
        Bureaucrat b("Bob", 0);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        Bureaucrat c("Charlie", 200);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "========= GRADE CHANGES TEST =========" << std::endl;
    try
    {
        Bureaucrat d("David", 2);
        d.raiseGrade();
        std::cout << d << std::endl;
        d.raiseGrade();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        Bureaucrat e("Emily", 149);
        e.lowerGrade();
        std::cout << e << std::endl;
        e.lowerGrade();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return (0);
}
