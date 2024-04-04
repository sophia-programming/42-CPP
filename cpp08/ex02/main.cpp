#include "MutantStack.hpp"

int main()
{
	MutantStack<int> ms;
	std::cout << GREEN << "=== [top] ===" << STOP << std::endl;
	ms.push(5);
	ms.push(17);
	std::cout << ms.top() << std::endl;

	std::cout << GREEN << "=== [pop] ===" << STOP << std::endl;
	ms.pop();
	std::cout << ms.size() << std::endl;

	std::cout << GREEN << "=== [push] ===" << STOP << std::endl;
	ms.push(3);
	ms.push(5);
	ms.push(737);
//[...]
	ms.push(0);
	MutantStack<int>::iterator it = ms.begin();
	MutantStack<int>::iterator ite = ms.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}
	std::stack<int> s(ms);
	return 0;
}
