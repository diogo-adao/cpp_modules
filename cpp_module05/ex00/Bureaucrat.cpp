#include "Bureaucrat.hpp"

// CONSTRUCTOR
Bureaucrat::Bureaucrat(const std::string& n, int g) : name(n), grade(g)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    
    std::cout << "Constructor called" << std::endl;
}

// COPY CONSTRUCTOR
Bureaucrat::Bureaucrat(const Bureaucrat& src) : name(src.name), grade(src.grade)
{
    std::cout << "Copy constructor called" << std::endl;
}

// COPY ASSIGNMENT
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src)
{
    if (&src != this)
        grade = src.grade;

    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

// DESTRUCTOR
Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor called" << std::endl;
}

// GETTERS
std::string Bureaucrat::getName() const { return name; }
int Bureaucrat::getGrade() const { return grade; }

// CHANGE GRADE
void Bureaucrat::raiseGrade()
{
    if (grade <= 1)
        throw GradeTooHighException();
    grade--;
}

void Bureaucrat::lowerGrade()
{
    if (grade >= 150)
        throw GradeTooLowException();
    grade++;
}

// EXCEPTIONS
const char* Bureaucrat::GradeTooHighException::what() const throw() { return "Grade too high"; }
const char* Bureaucrat::GradeTooLowException::what() const throw() { return "Grade too low"; }

// INSERTION OVERLOAD
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}