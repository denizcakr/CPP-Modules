
#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
	for(int i = 0; i < 100; i++)
		ideas[i] = "*** I am kind of animal but i have ideas ***";
}

Brain::~Brain()
{
	std::cout << "Brain Destructor called" << std::endl;
}

Brain::Brain(const Brain &data)
{
	std::cout << "Brain copy constructor called" << std::endl;
	for(int i = 0; i < 100; i++)
	{
		ideas[i] = "*** I am kind of animal but i have ideas ***";
		this->ideas[i] = data.ideas[i];
	}
}

Brain &Brain::operator=(const Brain &data)
{
	std::cout << "Brain copy assigment operator called" << std::endl;
	for(int i = 0; i < 100; i++)
		this->ideas[i] = data.ideas[i];
	
	return *this;
}

std::string *Brain::getIdeas()
{
	return ideas;
}