#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class AForm {
    private:
        const std::string name;
        bool status;
        const int g_sign;
        const int g_exec;
    public:
        AForm(const std::string& n, int to_sign, int to_exec);
        AForm(const AForm& src);
        AForm& operator=(const AForm& src);
		virtual ~AForm();

        std::string getName() const;
        bool getStatus() const;
        int getSignGrade() const;
        int getExecGrade() const;

        void beSigned(const Bureaucrat& b);
        void execute(Bureaucrat const & executor) const;
        virtual void executeAction() const = 0;

        class GradeTooHighException : public std::exception {
            public:
                virtual const char *what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char *what() const throw();
        };

        class FormNotSignedException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif
