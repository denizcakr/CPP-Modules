
#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	private:

	public:
		FragTrap();
		~FragTrap();
		FragTrap(std::string str);
		FragTrap(const FragTrap &);
		FragTrap &operator=(const FragTrap &);
		void highFivesGuys(void);
};

#endif