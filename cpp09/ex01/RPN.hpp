#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <stdlib.h>
#include <sstream>

using std::cout;
using std::string;
using std::endl;

class RPN 
{
	public:
		RPN();
		RPN(const RPN &c);
		RPN operator=(const RPN &c);
		~RPN();

		int split(string str);
		int numberCheck(string num);
		int operandCheck(string num);
		int operation(string op);
		int getValue();
	private:
		std::stack<int> stacks;
};

#endif