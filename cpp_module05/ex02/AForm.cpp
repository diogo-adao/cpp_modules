#include "AForm.hpp"

// CONSTRUCTOR
AForm::AForm(const std::string& n, int to_sign, int to_exec) : name(n), status(false), g_sign(to_sign), g_exec(to_exec)
{
    if (g_sign < 1 || g_exec < 1)
        throw GradeTooHighException();
    else if (g_sign > 150 || g_exec > 150)
        throw GradeTooLowException();
}

// COPY CONSTRUCTOR
AForm::AForm(const AForm& src) : name(src.name), status(src.status), g_sign(src.g_sign), g_exec(src.g_exec) {}

// COPY ASSIGNMENT
AForm& AForm::operator=(const AForm& src) 
{
    if (this != &src)
        status = src.status;
    
    return *this;
}

// DESTRUCTOR
AForm::~AForm() {}

//GETTERS
std::string AForm::getName() const { return name; }
bool AForm::getStatus() const { return status; }
int AForm::getSignGrade() const { return g_sign; }
int AForm::getExecGrade() const { return g_exec; }

// FUNCTIONS
void AForm::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() > g_sign)
        throw GradeTooLowException();
    status = true;
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (!getStatus())
        throw FormNotSignedException();
    if (executor.getGrade() > getExecGrade())
        throw GradeTooLowException();

    executeAction();
}

// EXCEPTIONS
const char* AForm::GradeTooHighException::what() const throw() { return "grade's too high"; }
const char* AForm::GradeTooLowException::what() const throw() { return "grade's too low"; }
const char* AForm::FormNotSignedException::what() const throw() { return "this form is not signed"; }

// INSERTION OVERLOAD
std::ostream& operator<<(std::ostream& os, const AForm& f)
{
    os << f.getName()
       << " [signed: " << (f.getStatus() ? "yes" : "no")
       << ", sign grade: " << f.getSignGrade()
       << ", exec grade: " << f.getExecGrade() << "]";
    return os;
}