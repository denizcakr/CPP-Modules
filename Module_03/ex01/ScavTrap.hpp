
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:

	public:
		ScavTrap();
		~ScavTrap();
		ScavTrap(std::string str);
		ScavTrap(const ScavTrap &);
		ScavTrap &operator=(const ScavTrap &);
		void guardGate();
};

#endif
