#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <iterator>

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
		void dataInsert();
		void insertValue(string str, float f);
		void printValue();
	private:
		std::map<string, float> values;
};

#endif