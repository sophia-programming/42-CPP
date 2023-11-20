//
// Created by 小平波琉 on 2022/08/04.
//

#ifndef CPP_HUMANB_HPP
#define CPP_HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
public:
	HumanB(std::string name);
	~HumanB();
	void attack();
	void setWeapon(Weapon &weapon);

private:
	std::string name_;
	Weapon *weapon_;
};

#endif //CPP_HUMANB_HPP
