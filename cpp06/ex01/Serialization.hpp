#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <iostream>
#include "Data.hpp"

class Serializer
{
public:
	Serializer();
	Serializer(const Serializer &rhs);
	Serializer &operator=(const Serializer &rhs);
	~Serializer();

public:
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);
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
