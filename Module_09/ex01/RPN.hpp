#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <list>

class RPN {

	private:
		std::stack<int> _stack;
	public:
		RPN();
		RPN(const RPN &);
		RPN &operator=(const RPN &);
		~RPN();
		void calculateRpn(std::string str);
};
#endif