#include "Form.hpp"

// CONSTRUCTOR
Form::Form(const std::string& n, int to_sign, int to_exec) : name(n), status(false), g_sign(to_sign), g_exec(to_exec)
{
    if (g_sign < 1 || g_exec < 1)
        throw GradeTooHighException();
    else if (g_sign > 150 || g_exec > 150)
        throw GradeTooLowException();
}

// COPY CONSTRUCTOR
Form::Form(const Form& src) : name(src.name), status(src.status), g_sign(src.g_sign), g_exec(src.g_exec) {}

// COPY ASSIGNMENT
Form& Form::operator=(const Form& src) 
{
    if (this != &src)
        status = src.status;
    
    return *this;
}

// DESTRUCTOR
Form::~Form() {}


//GETTERS & SETTERS
std::string Form::getName() const { return name; }
bool Form::getStatus() const { return status; }
int Form::getSignGrade() const { return g_sign; }
int Form::getExecGrade() const { return g_exec; }

void Form::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() > g_sign)
        throw GradeTooLowException();
    status = true;
}

// EXCEPTIONS
const char* Form::GradeTooHighException::what() const throw() { return "Grade's too high"; }
const char* Form::GradeTooLowException::what() const throw() { return "Grade's too low"; }

// INSERTION OVERLOAD
std::ostream& operator<<(std::ostream& os, const Form& f)
{
    os << f.getName()
       << " [signed: " << (f.getStatus() ? "yes" : "no")
       << ", sign grade: " << f.getSignGrade()
       << ", exec grade: " << f.getExecGrade() << "]";
    return os;
}