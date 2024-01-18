#include "FragTrap.hpp"

void printInfo(const FragTrap &x)
{
	std::cout << UNDERLINE;
	std::cout << "Name: " << x.getName() << std::endl;
	std::cout << " [HP]: " << x.getHitPoints() << std::endl;
	std::cout << " [EP]: " << x.getEnergyPoint() << std::endl;
	std::cout << " [AD]: " << x.getAttackDamage() << std::endl;
	std::cout << STOP;
}

int main()
{
	std::cout << "===[NORMAL CASE]===" << std::endl;
	FragTrap naganoyu("naganoyu");
	printInfo(naganoyu);
	naganoyu.attack("ako");
	naganoyu.takeDamage(2);
	naganoyu.beRepaired(3);
	naganoyu.takeDamage(5);
	std::cout << "===[ADDED FUNCTION]===" << std::endl;
	naganoyu.highFivesGuys();

	std::cout << "===[GAMEOVER CASE]===" << std::endl;
	FragTrap nop("nop");
	printInfo(nop);
	nop.attack("sataharu");
	nop.takeDamage(100);
}
