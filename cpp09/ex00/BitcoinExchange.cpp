#include "BitcoinExchange.hpp"

Bit::Bit()
{

}

Bit::Bit(const Bit &c)
{
	(void)c;
}

Bit Bit::operator=(const Bit &c)
{
	(void)c;
	return (*this);
}

Bit::~Bit()
{

}

void Bit::insertValue(string str, float f)
{
	this->values.insert(std::pair<string, float>(str, f));
}

void Bit::printValue()
{
	std::map<string, float>::iterator itr;

    cout << "\tKEY\tELEMENT\n";
    for (itr = this->values.begin(); itr != this->values.end(); ++itr) {
        cout << '\t' << itr->first << '\t' << itr->second
             << '\n';
    }
    cout << endl;
}