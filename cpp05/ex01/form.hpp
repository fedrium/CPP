#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string.h>

class bureaucrat;

class form{
	public:
		form();
		form(const form &c);
		form &operator=(const form &c);
		~form();
		form(std::string newName, int sign, int exe);
		std::string getName() const;
		bool getSign() const;
		int getGradeSign() const;
		int getGradeExe() const;
		void	beSigned(bureaucrat const &bu);
		class FormHigh : public std::exception {
			public:
				virtual const char	*what() const throw();
		};

		class FormLow : public std::exception {
			public:
				virtual const char	*what() const throw();
		};
	private:
		std::string const name;
		bool sign;
		int const gradeSign;
		int const gradeExe;
};

std::ostream& operator<<(std::ostream& os, const form &Form);

#endif