#include "Base.hpp"

Base::~Base() {}

Base * generate(void)
{
    int r = rand() % 3;

    if (r == 0)
        return new A();
    else if (r == 1)
        return new B();
    else
        return new C();
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "p points to A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "p points to B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "p points to C" << std::endl;
}

void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "p refers to A" << std::endl;
        return ;
    }
    catch (std::exception& e) {}

    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "p refers to B" << std::endl;
        return ;
    }
    catch (std::exception& e) {}

    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "p refers to C" << std::endl;
        return ;
    }
    catch (std::exception& e) {}
}
