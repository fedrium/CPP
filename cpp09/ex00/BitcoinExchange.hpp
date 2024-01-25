#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <iterator>
#include <sstream>
#include <math.h>
#include <stdlib.h>

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
		float compare(string date, float value);
		std::map<string, float>::iterator lowerBound(string date);
	private:
		std::map<string, float> values;
};

int dateCheck(string date, string value);

#endif