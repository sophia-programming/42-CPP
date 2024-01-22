#ifndef CPP_CLAPTRAP_HPP
#define CPP_CLAPTRAP_HPP
#include <iostream>
#include <string>

class ClapTrap {
public:
	ClapTrap();
	ClapTrap(const std::string &name);
	~ClapTrap();
	ClapTrap(const ClapTrap &rhs);
	ClapTrap &operator=(const ClapTrap &rhs);

	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	const std::string &getName() const;
	unsigned int getHitPoints() const;
	unsigned int getEnergyPoints() const;
	unsigned int getAttackDamage() const;

private:
	std::string name_;
	unsigned int hitPoints_;
	unsigned int energyPoints_;
	unsigned int attackDamage_;

	static const unsigned int kInitHitPoints_ = 10;
	static const unsigned int kInitEnergyPoints_ = 10;
	static const unsigned int kInitAttackDamage_ = 0;
};

/* colors */
const char *const STOP = "\033[0m";
const char *const BOLD = "\033[1m";
const char *const BLACK = "\033[30m";
const char *const RED = "\033[31m";
const char *const GREEN = "\033[32m";
const char *const YELLOW = "\033[33m";
const char *const BLUE = "\033[34m";
const char *const MAGENTA = "\033[35m";
const char *const CYAN = "\033[36m";
const char *const WHITE = "\033[37m";
const char *const UNDERLINE =" \033[4m";

#endif
