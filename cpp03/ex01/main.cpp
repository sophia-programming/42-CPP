#include "ScavTrap.hpp"

void printInfo(const ScavTrap &x)
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
	ScavTrap wolf("wolf");
	printInfo(wolf);
	wolf.attack("fox");
	wolf.takeDamage(2);
	wolf.beRepaired(3);
	wolf.takeDamage(5);
	std::cout << "===[ADDED FUNCTION]===" << std::endl;
	wolf.guardGate();

	std::cout << "===[GAMEOVER CASE]===" << std::endl;
	ScavTrap neko("neko");
	printInfo(neko);
	neko.attack("mouse");
	neko.takeDamage(100);
}
