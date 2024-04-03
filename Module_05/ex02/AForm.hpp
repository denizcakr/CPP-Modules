
#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>
#include <stdbool.h>

class Bureaucrat;

class AForm {

	private:
		const std::string name;
		bool sign;
		const int grade_sign;
		const int grade_exec;

	public:
		AForm();
		virtual ~AForm();
		AForm(const std::string name, const int grade_sign, const int grade_exec);
		AForm(const AForm& copy);
		AForm &operator=(const AForm& copy);

		std::string getName() const;
		int getGradeSign() const;
		int getGradeExec() const;
		bool getSign() const;

		void setSign(bool sign);

		class GradeTooHighException : public std::exception {
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			const char* what() const throw();
		};
		class FormNotSignedException: public std::exception {
            const char* what() const throw();
        };

		bool beSigned(Bureaucrat& b_type);
		virtual void specificExecute(void) const = 0;
		
		void execute(Bureaucrat const & executor) const;
};


std::ostream &operator<<(std::ostream& os, const AForm&);

#endif