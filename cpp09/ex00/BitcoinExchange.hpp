#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <fstream>

using std::string;
using std::cout;
using std::endl;

class Bit
{
	public:
		Bit();
		Bit(const Bit &c);
		Bit operator=(const Bit &c);
		~Bit();

	private:
		std::map<string, int> values;
};

#endif