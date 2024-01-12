#ifndef Form_HPP
#define Form_HPP

#include <iostream>
#include <string.h>

class bureaucrat;

class AForm{
	public:
		AForm();
		AForm(const AForm &c);
		AForm &operator=(const AForm &c);
		virtual ~AForm();
		AForm(std::string newName, int sign, int exe);
		std::string getName() const;
		bool getSign() const;
		int getGradeSign() const;
		int getGradeExe() const;
		void	beSigned(bureaucrat const &bu);
		class AFormHigh : public std::exception {
			public:
				virtual const char	*what() const throw();
		};

		class AFormLow : public std::exception {
			public:
				virtual const char	*what() const throw();
		};
	private:
		std::string const name;
		bool sign;
		int const gradeSign;
		int const gradeExe;
};

std::ostream& operator<<(std::ostream& os, const AForm &AForm);

#endif