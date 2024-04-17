#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

int	main(void)
{
	srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		std::cout << "Test " << i + 1 << ":" << std::endl;
		Base *ptr = generate();
		if (!ptr) {
			std::cerr << "Failed to generate instance." << std::endl;
			continue;
		}

		Base &ref = *ptr;

		std::cout << GREEN << "Pointer:" << STOP << std::endl;
		identify(ptr);
		std::cout << YELLOW << "Reference:" << STOP << std::endl;
		identify(ref);

		delete ptr;
		std::cout << std::endl;
	}
	return 0;
}
