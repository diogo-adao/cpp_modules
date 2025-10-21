#include "Bureaucrat.hpp"
#include "AForm.hpp"

// CONSTRUCTOR
Bureaucrat::Bureaucrat(const std::string& n, int g) : name(n), grade(g)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
}

// COPY CONSTRUCTOR
Bureaucrat::Bureaucrat(const Bureaucrat& src) : name(src.name), grade(src.grade) {}

// COPY ASSIGNMENT
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src)
{
    if (&src != this)
        grade = src.grade;

    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

// DESTRUCTOR
Bureaucrat::~Bureaucrat() {}

// GETTERS
std::string Bureaucrat::getName() const { return name; }
int Bureaucrat::getGrade() const { return grade; }

// FUNCTIONS
void Bureaucrat::signForm(AForm& f)
{
    try
    {
        f.beSigned(*this);
        std::cout << name << " signed " << f.getName() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << name << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form) const
{
    try
    {
        form.execute(*this);
        std::cout << name << " executed " << form.getName() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
    }
}

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