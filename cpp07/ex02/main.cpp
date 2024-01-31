#include "Array.hpp"
#include <iostream>

#define MAX_VAL 750
int main(int, char**)
{
    // try
	// {
	// 	Array<int>		intArray = Array<int>(10);
	// 	Array<std::string>	strArray = Array<std::string>(2);

	// 	Array<int>		intArray2 = Array<int>();
		

	// 	intArray[0] = 2;
	// 	std::cout << intArray[0] << std::endl;
	// 	std::cout << intArray[1] << std::endl;
	// 	std::cout << "Size of int array: " << intArray.size() << std::endl;

	// 	std::cout << strArray[0] << std::endl;
	// 	strArray[0] = "Foo bar baz";

	// 	Array<std::string>	strArray2(strArray);
	// 	strArray2[0] = "Different text goes here";
	// 	std::cout << strArray2[0] << std::endl;
	// 	std::cout << strArray[0] << std::endl;
		
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }

    // return 0;
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}