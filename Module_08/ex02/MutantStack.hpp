
#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>
#include <list>

template<typename T>

class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		~MutantStack();
		MutantStack(const MutantStack &);
		MutantStack &operator=(const MutantStack &);

		typedef typename std::deque<T>::iterator iterator;

		iterator begin();
		iterator end();
};

#include "MutantStack.tpp"

#endif