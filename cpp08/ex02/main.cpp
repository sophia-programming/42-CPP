#include "MutantStack.hpp"
#include "list"

void pdf_test()
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
}

void my_test()
{
	std::cout << GREEN << "=== [MutantStack with int] ===" << STOP << std::endl;
	MutantStack<int> ms1;
	ms1.push(5);
	ms1.push(17);
	ms1.pop();
	ms1.push(-35);
	ms1.push(10);
	for (MutantStack<int>::iterator it = ms1.begin(); it != ms1.end(); it++)
	{
		std::cout << *it << std::endl;
	}

	std::cout << GREEN << "=== [MutantStack with list] ===" << STOP << std::endl;
	MutantStack<std::list<int> > ms2;
	std::list<int> list1;
	list1.push_back(5);
	list1.push_back(17);
	ms2.push(list1); //リスト全体をMutantStackに追加

	std::list<int> list2;
	list2.push_back(-35);
	list2.push_back(10);
	ms2.push(list2); //別リストをMutantStackに追加

	for (MutantStack<std::list<int> >::iterator it = ms2.begin(); it != ms2.end(); it++)
	{
		for (std::list<int>::iterator itList = it->begin(); itList != it->end(); itList++)
		{
			std::cout << *itList << std::endl;
		}
	}
}

int main() {
	pdf_test();
	my_test();
	return 0;
}
