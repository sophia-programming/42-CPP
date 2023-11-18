//clock.cpp
#include <iostream>
class Clock {
public:
	int hour;
	int minute;
	void set(int hour, int minute);
	void print();
private:
	int hour_;
	int minute_;
};

void Clock::set(int hour, int minute)
{
	if (0 <= hour && hour <= 24 && 0 <= minute && minute <= 60) {
		this->hour = hour % 24;
		this->minute = minute % 60;
	} else {
		throw "NG";
	}
}

void Clock::print(void)
{
	std::cout << this->hour << ":" << this->minute << "!" << std::endl;
}

int main(int argc, char **argv)
{
	Clock clock;

	std::cout << "What time is it? ";
	int hour, minute;
	std::cin >> hour >> minute;
	clock.set(hour, minute);
	std::cout << "thank you!" << std::endl << "The current time is ";
	clock.print();

	Clock aoba_clock;
	aoba_clock.set(7, 30);
	std::cout << "always wakes up at ";
	aoba_clock.print();
	return 0;
}
