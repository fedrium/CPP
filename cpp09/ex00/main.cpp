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

void compareData(Bit *bit, char *str)
{
	string l;
	string mapped;
	string value;
	string temp;
	
	std::ifstream data;
	data.open(str, std::ifstream::in);
	getline(data, l);
	while (getline(data, l))
	{
		temp = l.substr(0, l.rfind('|'));
		value = l.substr(l.find('|') + 1, l.npos);
		if (temp.size() == 11)
		{
			if (dateCheck(temp) == 1)
			{
				std::cerr << "Error: bad input => " << temp << endl;
				return;
			}
			else
			{
				
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
	compareData(&bit, argv[1]);
}