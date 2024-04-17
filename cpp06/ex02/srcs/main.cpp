#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

int	main(void)
{
	srand(time(NULL));
	Base *ptr = generate();
	Base &ref = *ptr;
	identify(ptr);
	identify(ref);
	delete ptr;
	return 0;
}
