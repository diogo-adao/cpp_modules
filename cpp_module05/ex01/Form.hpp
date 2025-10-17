#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form {
    private:
        const std::string name;
        bool status;
        const int g_sign;
        const int g_exec;
    public:
        Form(const std::string& n, int to_sign, int to_exec);
        Form(const Form& src);
        Form& operator=(const Form& src);
		~Form();

        std::string getName() const;
        bool getStatus() const;
        int getSignGrade() const;
        int getExecGrade() const;
        void beSigned(const Bureaucrat& b);

        class GradeTooHighException : public std::exception {
            public:
                virtual const char *what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif