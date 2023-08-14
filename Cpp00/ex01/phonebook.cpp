#include "phonebook.hpp"

int main()
{
	PhoneBook pb;
    int i = 0;
    string input;

	while (true)
	{
		if (i == 8)
			i = 0;
    	std::cout << "PhoneBook" << endl;
		std::cout << "ADD | SEARCH | EXIT" << endl;
		std::cout << "Input: ";
		std::cin >> input;
		if (input == "ADD")
		{
			pb.add_contact(i);
			i++;
		}
		if (input == "SEARCH")
		{
			pb.search_contact();
		}
		if (input == "EXIT")
		{
			std::exit(0);
		}
	}
}

void	PhoneBook::search_contact()
{
	std::cout << "INDEX     |FIRST NAME|LAST NAME |NICKNAME  |" << endl;
	for (int j = 0; j < 8; j++)
	{
		std::cout << std::setw(10) << j + 1 << "|";
		if (contact[j].first_name.size() > 10)
		{
			std::cout << contact[j].first_name.substr(0, 9);
			std::cout << ".|";
		}
		else
			std::cout << std::setw(10) << contact[j].first_name << "|";
		if (contact[j].first_name.size() > 10)
		{
			std::cout << contact[j].last_name.substr(0, 9);
			std::cout << ".|";
		}
		else
			std::cout << std::setw(10) << contact[j].last_name << "|";
		if (contact[j].first_name.size() > 10)
		{
			std::cout << contact[j].nickname.substr(0, 9);
			std::cout << ".|" << endl;
		}
		else
			std::cout << std::setw(10) << contact[j].nickname << "|" << endl;
	}

	int input;
	std::cout << "SEARCHING FOR: ";
	std::cin >> input;
	if (contact[input - 1].first_name.size() == 0)
		std::cout << "Invalid index" << endl;
	else if (input > 0 && input < 9)
	{
		std::cout << "First name: " << contact[input - 1].first_name << endl;
		std::cout << "Last name: " << contact[input - 1].last_name << endl;
		std::cout << "Nickname: " << contact[input - 1].nickname << endl;
		std::cout << "Phone number: " << contact[input - 1].phone_number << endl;
		std::cout << "Darkest secret: " << contact[input - 1].secret << endl;
	}
	else
		std::cout << "Invalid index" << endl;
}

void	PhoneBook::add_contact(int i)
{
	std::cout << "First Name: ";
	std::cin >> contact[i].first_name;
	std::cout << "Last Name: ";
	std::cin >> contact[i].last_name;
	std::cout << "Nickname: ";
	std::cin >> contact[i].nickname;
	std::cout << "Phone Number: ";
	std::cin >> contact[i].phone_number;
	std::cout << "Darkest Secret: ";
	std::cin >> contact[i].secret;
}