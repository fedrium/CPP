#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		cout << "Error: could not open file." << endl;
	
	std::map<string, int> input;
	std::fstream file;
	file.open(argv[1], std::fstream::in);
	
}