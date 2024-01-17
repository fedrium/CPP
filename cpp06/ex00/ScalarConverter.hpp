#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <iomanip>
#include <limits>

class ScalarConverter 
{
	public:
		static void convert(std::string str);
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &c);
		ScalarConverter operator=(const ScalarConverter &c);
};

#endif