//
// Created by 小平波琉 on 2022/08/04.
//

#ifndef CPP_FRAGTRAP_HPP
#define CPP_FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
	FragTrap();
	FragTrap(const std::string &name);
	FragTrap(const FragTrap &rhs);
	~FragTrap();
	FragTrap &operator=(const FragTrap &rhs);

	void highFivesGuys();
	void attack(const std::string &target);

private:
	static const unsigned int kInitHitPoint_ = 100;
	static const unsigned int kInitEnergyPoint_ = 100;
	static const unsigned int kInitAttackDamage_ = 30;
};

#endif //CPP_FRAGTRAP_HPP
