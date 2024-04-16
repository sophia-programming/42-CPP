#include "Serialization.hpp"

int main(void)
{
	Data *data = new Data;
	std::cout << data << std::endl;
	data->s1 = "Hello";
	data->n = 42;
	data->s2 = "Neko";

	uintptr_t row = Serializer::serialize(data);
	std::cout << YELLOW << "serialize address: " << STOP << row << std::endl;

	Data *deserialized = Serializer::deserialize(row);
	std::cout << YELLOW << "deserialized pointer address:  " << STOP << deserialized << std::endl;

	std::cout << CYAN << "Original pointer address: " << STOP << data << std::endl;
	std::cout << "s1: " << deserialized->s1 << std::endl;
	std::cout << "n: " << deserialized->n << std::endl;
	std::cout << "s2: " << deserialized->s2 << std::endl;

	std::cout << "---------------------------" << std::endl;

	std::cout << CYAN << "Deserialized pointer address: " << STOP << deserialized << std::endl;
	std::cout << "s1: " << data->s1 << std::endl;
	std::cout << "n: " << data->n << std::endl;
	std::cout << "s2: " << data->s2 << std::endl;

	delete data;
	return 0;
}
