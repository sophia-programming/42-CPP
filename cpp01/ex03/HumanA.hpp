//
// Created by 小平波琉 on 2022/08/04.
//

#ifndef CPP_HUMANA_HPP
#define CPP_HUMANA_HPP
#include "Weapon.hpp"

class HumanA {
public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();
	void attack();

	/* accessor */
	const std::string &getName() const;
	Weapon &getWeapon() const;

	void setName(const std::string &name);
	void setWeapon(Weapon &weapon);

private:
	std::string name_;
	Weapon &weapon_;
};

#endif //CPP_HUMANA_HPP
