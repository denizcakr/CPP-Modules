#include "RPN.hpp"

RPN::RPN() {
}

RPN::~RPN() {
}

RPN::RPN(const RPN &data) {
	*this = data;
}

RPN &RPN::operator=(const RPN &other)
{
	this->_stack = other._stack;
	return (*this);
}

int stringToInt(std::string str, int &num)
{
	std::istringstream iss(str);
	return iss >> num ? 1 : 0;
}

void RPN::calculateRpn(std::string expression)
{
	int flag = 0;
	for(size_t i = 0; i < expression.size(); i++)
	{
		if (isdigit(expression[i]))
			flag++;
	}
	if (flag == 1)
	{
		std::cout << "Error: you have a only number" << std::endl; 
		return;
	}
	std::istringstream str(expression);
	std::string data;

	while(str >> data)
	{
		if (data == "+" || data == "-" || data == "/" || data == "*")
		{
			if (_stack.size() < 2)
			{
				std::cout << "Error: not enough values" << std::endl;
				return ;
			}
			int x = _stack.top();
			_stack.pop();
			int y = _stack.top();
			_stack.pop();
			if (data == "+")
				_stack.push(y + x);
			else if (data == "-")
				_stack.push(y - x);
			else if (data == "*")
				_stack.push(y * x);
			else if (data == "/")
			{
				if(x == 0)
				{
					std::cout << "Error: division by zero" << std::endl;
					return ;
				}
				else
				_stack.push(y / x);

			}
		}
		else
		{
			int num;
			if (!stringToInt(data, num))
			{
				std::cout << "Error" << std::endl;
				return ;
			}
			if(num >= 10 || num < 0)
			{
				std::cout << "Error: the number bigger than 10" << std::endl;
				return ;
			}
			_stack.push(num);
		}
	}
	if (_stack.size() != 1) {
		std::cerr << "Error: Invalid RPN expression" << std::endl;
		return ;
	}
	std::cout << _stack.top() << std::endl;
}