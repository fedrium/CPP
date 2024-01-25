#include "RPN.hpp"

RPN::RPN()
{

}

RPN::RPN(const RPN &c)
{
	(void)c;
}

RPN RPN::operator=(const RPN &c)
{
	(void)c;
	return (*this);
}

RPN::~RPN()
{

}

int RPN::numberCheck(string value)
{
	if (value.size() > 1)
		return (1);
	if (isdigit(value[0]))
		return (0);
	return(1);
}

int RPN::operandCheck(string value)
{
	if (value.size() > 1)
		return (1);
	if (value[0] == '+' || value[0] == '-' || value[0] == '*' || value[0] == '/')
		return (0);
	return (1);
}

int RPN::operation(string op)
{
	int num1;
	int num2;
	int res;

	num2 = this->stacks.top();
	this->stacks.pop();
	num1 = this->stacks.top();
	this->stacks.pop();
	if (num1 == 0 || num2 == 0)
		return (1);
	if (op[0] == '+')
		res = num1 + num2;
	if (op[0] == '-')
		res = num1 - num2;
	if (op[0] == '*')
		res = num1 * num2;
	if (op[0] == '/')
		res = num1 / num2;
	this->stacks.push(res);
	return (0);
}

int RPN::split(string str)
{
	string value;
	std::stringstream s(str);

	while (std::getline(s, value, ' '))
	{
		if (numberCheck(value) == 0)
		 	this->stacks.push(atoi(value.c_str()));
		else if (operandCheck(value) == 0 && this->stacks.size() >= 2)
			operation(value);
		else
		{
			std::cerr << "Error" << endl;
			return (1);
		}
	}
	return (0);
}

int RPN::getValue()
{
	return (this->stacks.top());
}