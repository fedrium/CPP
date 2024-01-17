#include "Data.hpp"
#include "Serializer.hpp"

int main(void)
{
	Data	dataA;

	dataA.palcehodler = 'a';
	
	std::cout << "Original address of data structure: " << &dataA << std::endl;

	dataA = *Serializer::deserialize(Serializer::serialize(&dataA));

	std::cout << "Address of data structure after serialization and deserialization: " << &dataA << std::endl;

	std::cout << dataA.palcehodler << std::endl;

}