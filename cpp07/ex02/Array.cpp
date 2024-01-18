#include "Array.hpp"

template <typename T> Array<T>::Array()
{
	this->ptr = new T[0];
	this->arraySize = 0;
}

template <typename T> Array<T>::Array(unsigned int n)
{
	this->ptr = new T[n];
	this->arraySize = n;
}

template <typename T> Array<T> Array<T>::operator=(const Array &c)
{
	if (this->ptr == &c.ptr)
		return (*this);
	this->ptr = c.ptr;
	return (*this);
}

template <typename T> Array<T>::~Array()
{
	delete this->ptr;
}

template <typename T> int Array<T>::size()
{
	return this->arraysize();
}

template <typename T> int Array<T>::operator [] (unsigned int n)
{
	if (n >= size())
		throw Array::OutOfBound();
	return (ptr[n]);
}