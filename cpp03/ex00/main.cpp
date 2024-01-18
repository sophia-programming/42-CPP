#include "ClapTrap.hpp"

void printInfo(const ClapTrap &x)
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
	ClapTrap wolf("wolf");
	printInfo(wolf);
	wolf.attack("fox");
	wolf.takeDamage(2);
	wolf.beRepaired(3);
	wolf.takeDamage(5);

	std::cout << "===[GAMEOVER CASE]===" << std::endl;
	ClapTrap neko("neko");
	printInfo(neko);
	neko.attack("mouse");
	neko.takeDamage(100);
}
