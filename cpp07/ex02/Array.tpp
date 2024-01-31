#ifndef ARRAY_TPP
#define ARRAY_TPP

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

template <typename T> Array<T>::Array(const Array &c)
{
	this->ptr = c.ptr;
	this->arraySize = c.arraySize;
}

template <typename T> Array<T> &Array<T>::operator=(const Array &c)
{
	if (this->ptr == &c.ptr)
		return (*this);
	this->ptr = c.ptr;
	return (*this);
}

template <typename T> Array<T>::~Array()
{
	if (ptr)
		delete []ptr;
}

template <typename T> int Array<T>::size()
{
	return this->arraySize;
}

template <typename T> T &Array<T>::operator [] (int const n)
{
	if (n > size())
		throw Array::OutOfBound();
	return (ptr[n]);
}

template <typename T> const char *Array<T>::OutOfBound::what() const throw()
{
	return "Out of bound input.";
}

#endif