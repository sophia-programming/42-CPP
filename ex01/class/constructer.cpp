#include <iostream>

class Test
{
	void output(void)
	{
		this->i = 0;
		std::cout << "start! with " << this->i << std::endl;
	}
	void ~output(void)
	{
		this->i = 1;
		std::cout << "end! with " << this->i << std::endl;
	}
public:
	int i;
	output(){this->i = 0;};
	~output(){this->i = 0;};
};

int main(void)
{
	Test test;
	return 0;
}
