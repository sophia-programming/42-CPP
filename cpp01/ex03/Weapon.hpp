#ifndef CPP_WEAPON_HPP
#define CPP_WEAPON_HPP
#include <string>
#include <iostream>

class Weapon {
public:
	Weapon(std::string type);
	~Weapon();

	/* accessor (PDF指定あり)*/
	void setType(const std::string &type);
	const std::string &getType();
private:
	std::string type_;
};

#endif
