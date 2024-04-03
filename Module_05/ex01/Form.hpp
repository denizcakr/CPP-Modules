#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include <stdbool.h>

class Bureaucrat;

class Form {

	private:
		const std::string name;
		bool sign;
		const int grade_sign;
		const int grade_exec;

	public:
		Form();
		~Form();
		Form(const std::string name, const int grade_sign, const int grade_exec);
		Form(const Form& copy);
		Form &operator=(const Form& copy);

		std::string getName() const;
		int getGradeSign() const;
		int getGradeExec() const;
		bool getSign() const;

		void setSign(bool sign);

		class GradeTooHighException : public std::exception{
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception{
			const char* what() const throw();
		};

		bool beSigned(Bureaucrat& b_type);
};


std::ostream &operator<<(std::ostream& os, const Form&);

#endif
