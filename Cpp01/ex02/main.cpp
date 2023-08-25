#include <iostream>
#include <string>

int main()
{
    std::string zom = "HI THIS IS BRAIN";
    std::string *stringPTR = &zom;
    std::string &stringREF = zom;

    std::cout << &zom << std:: endl;
    std::cout << &stringPTR << std:: endl;
    std::cout << &stringREF << std::endl;

    std::cout << zom << std:: endl;
    std::cout << *stringPTR << std:: endl;
    std::cout << stringREF << std:: endl;
};