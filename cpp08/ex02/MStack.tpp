#include "MStack.hpp"

template <typename T>
MutantStack<T>::MutantStack()
{
    std::cout << "Constructor called" << std::endl;
}

template <typename T>
MutantStack<T>::~MutantStack()
{
    std::cout << "Destructor called" << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(MutantStack &mutantstack): std::stack<T>(mutantstack)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = mutantstack; 
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &mutantstack)
{
    std::cout << "Copy assignment called" << std::endl;
    if (this == &mutantstack)
		return (*this);
    this->c = mutantstack.c;
    return *this;
}
