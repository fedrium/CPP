#include "ScalarConverter.hpp"

void	convertedPrint(char c, int i, float f, double d)
{
	if (std::isnan(c))
		std::cout << "char: impossible" << std::endl;
	else if (isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else	
		std::cout << "char: Non displayable" << std::endl;

	if (std::isnan(i))
		std::cout << "int: impossible" << std::endl;
	else if (d < 2147483647 && d > -2147483648)
		std::cout << "int: " << i << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

int wordCheck(std::string str)
{
	for (int i = 0; i < (int)str.size(); i++)
	{
		if (isdigit(str[i]) == 1 && isalpha(str[i]) == 1 && str[i] != '.' && str[i] != '+' && str[i] != '-')
			return (1);
	}
	return (0);
}

void ScalarConverter::convert(std::string str)
{
	int hasDot = 0;
	char *end;


	if (wordCheck(str) == 1)
	{
		std::cout << "Invalid input." << std::endl;
		return;
	}
	for (int i = 0; i < (int)str.size();)
	{
		if (str[i] == '.')
		{
			hasDot++;
			i++;
		}
		if ((i + 1 == (int)str.size() && str[i] == 'f') || str == "nan")
		{
			float tmp = strtof(str.c_str(), &end);
			convertedPrint(static_cast<char>(tmp), static_cast<int>(tmp), tmp, static_cast<double>(tmp));
			return;
		}
		if (!isdigit(str[i]))
			break;
		if (hasDot > 1)
			break;
		if (i + 1 == (int)str.size() && hasDot == 1)
		{
			double tmp = strtod(str.c_str(), &end);
			convertedPrint(static_cast<char>(tmp), static_cast<int>(tmp), static_cast<float>(tmp), tmp);
			return;
		}
		if (i + 1 == (int)str.size() && hasDot == 0)
		{
			int tmp = std::atoi(str.c_str());
			convertedPrint(static_cast<char>(tmp), tmp, static_cast<float>(tmp), static_cast<double>(tmp));
			return;
		}
		i++;
	}
	if (isalpha(str[0]) && str.size() == 1)
	{
		char tmp = str[0];
		convertedPrint(tmp, static_cast<int>(tmp), static_cast<float>(tmp), static_cast<double>(tmp));
		return;
	}
	std::cout << "invalid input.\n";
}

ScalarConverter::ScalarConverter()
{

}

ScalarConverter::~ScalarConverter()
{

}

ScalarConverter::ScalarConverter(const ScalarConverter &c)
{
	(void)c;
}
ScalarConverter ScalarConverter::operator=(const ScalarConverter &c)
{
	(void)c;
	return (*this);
}