#include "Serialization.hpp"

Serializer::Serializer() {

}

Serializer::Serializer(const Serializer &rhs) {
	*this = rhs;
}

Serializer &Serializer::operator=(const Serializer &rhs) {
	if (this != &rhs)
		*this = rhs;
	return *this;
}

Serializer::~Serializer() {

}

uintptr_t Serializer::serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}
