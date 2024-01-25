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
	return(0);
}

int RPN::operandCheck(string value)
{
	if (value.size() > 1)
		return (1);
	if (value[0] == '+' || value[0] == '-' || value[0] == '*' || value[0] == '/')
		return (0);
	return (0);
}

void RPN::operation(string op)
{
	int num1;
	int num2;
	int res;

	num2 = this->stacks.top();
	this->stacks.pop();
	num1 = this->stacks.top();
	this->stacks.pop();
	if (op[0] == '+')
		res = num1 + num2;
	if (op[0] == '-')
		res = num1 - num2;
	if (op[0] == '*')
		res = num1 * num2;
	if (op[0] == '/')
		res = num1 / num2;
	this->stacks.push(res);
}

void RPN::split(string str)
{
	string value;
	std::stringstream s(str);

	while (std::getline(s, value, ' '))
	{
		if (numberCheck(value) == 0)
		 	this->stacks.push(atoi(value.c_str()));
		if (operandCheck(value) == 0)
			operation(value);
	}
}