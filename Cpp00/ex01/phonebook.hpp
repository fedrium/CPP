#ifndef PHONEBOOK
# define PHONEBOOK

#include <iostream>
#include <iomanip>
#include <string>

using std::string;
using std::endl;

class Contact
{
    public:
        string first_name;
        string last_name;
        string nickname;
        string phone_number;
        string secret;
};

class PhoneBook
{
    public:
        void add_contact(int i);
        void search_contact();
    private:
        Contact contact[8];
};

#endif