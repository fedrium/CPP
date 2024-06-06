#ifndef MSTACK_HPP
#define MSTACK_HPP

#include <deque>
#include <stack>
#include <iterator>
#include <algorithm>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack();
        ~MutantStack();
        MutantStack(MutantStack &mutantStack);
        MutantStack<T> &operator=(const MutantStack &mutantstack);
        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator begin()
        {
            return this->c.begin();
        }
        iterator end()
        {
            return this->c.end();
        }
};

#include "MStack.tpp"

#endif
