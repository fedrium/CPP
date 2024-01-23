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

int dateCheck(string date)
{
    string year;
    string month;
    string day;

    year = date.substr(0, date.find('-'));
    month = date.substr(date.find('-') + 1, 2);
    day = date.substr(date.rfind('-') + 1, date.npos);

    cout << "year: " << year << " month: " << month << " day: " << day << endl;
    if (date[4] != '-' || date[7] != '-')
        return (1);
    if (year.size() != 4)
        return (1);
    if (month.size() != 2 || atoi(month.c_str()) > 12)
        return (1);
    if (day.size() != 3 || atoi(day.c_str()) > 31)
        return (1);
    return(0);
}

int Bit::compare(string date, float value)
{
    std::map<string, float>::reverse_iterator iter;

    if ()
}