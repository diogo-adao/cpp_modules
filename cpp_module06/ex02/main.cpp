#include "Base.hpp"

int main()
{
    srand(time(NULL));

    Base *p = generate();

    identify(p);
    identify(*p);
    delete p;

    return (0);
}
