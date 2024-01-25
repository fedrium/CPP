#include "BitcoinExchange.hpp"
#include <stdlib.h>

void insertData(Bit *bit)
{
	string l;
	string mapped;
	string value;

	std::ifstream data;
	data.open("data.csv", std::ifstream::in);
	getline(data, l);
	while (getline(data, l))
	{
		mapped = l.substr(0, 10);
		value = l.substr(11, ((int)l.size() - 10));
		bit->insertValue(mapped, strtof(value.c_str(), NULL));
	}
	data.close();
}

void compareData(Bit &bit, char *str)
{
	string l;
	string mapped;
	string value;
	string key;
	
	std::ifstream data;
	data.open(str, std::ifstream::in);
	getline(data, l);
	while (getline(data, l))
	{
		key = l.substr(0, l.rfind('|'));
		value = l.substr(l.find('|') + 1, l.npos);
		if (key.size() != 11)
		{
			std::cerr << "Error: bad input => " << key << endl;
		}
		else if (key.size() == 11)
		{
			if (dateCheck(key, value) == 1)
			{
				std::cerr << "Error: bad input => " << key << endl;
			}
			else if (dateCheck(key, value) == 2)
			{
				std::cerr << "Error: not a positive number." << endl;
			}
			else if (dateCheck(key, value) == 3)
			{
				std::cerr << "Error: too large a number." << endl;
			}
			else
			{
				float res = bit.compare(key, std::strtof(value.c_str(), NULL));
				cout << key << "=>" << value << " = " << res << endl;
			}
		}
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
		std::cerr << "Error: could not open file." << endl;
	Bit bit;
	insertData(&bit);
	// bit.printValue();
	compareData(bit, argv[1]);
}