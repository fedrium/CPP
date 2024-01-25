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

		void split(string str);
		int numberCheck(string num);
		int operandCheck(string num);
		void operation(string op);
	private:
		std::stack<int> stacks;
};

#endif