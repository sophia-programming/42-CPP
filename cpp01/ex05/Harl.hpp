//
// Created by 小平波琉 on 2022/08/07.
//

#ifndef CPP_HARL_HPP
#define CPP_HARL_HPP

#include "color.hpp"

#include <iostream>
#include <string>

enum {
	DEBUG = 1,
	INFO,
	WARNING,
	ERROR
};

class Harl {
public:
	Harl();
	~Harl();
	void complain(std::string level);

private:
	void debug();
	void info();
	void warning();
	void error();
	void invalidArg();
};

#endif //CPP_HARL_HPP
