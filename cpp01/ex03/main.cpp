//
// Created by 小平波琉 on 2022/08/04.
//
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"
/* PDF */

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}

/*
 * crude : in a natural or raw state; not yet processed or refined.
 * spike : impale on or pierce with a sharp point.
 */

/*
int main()
{
	Weapon weapon("crude spiked club");
	HumanA nop("nop", weapon);
	nop.attack();

	HumanB sataharu("sataharu");
//	sataharu.setWeapon(weapon);
	sataharu.attack();
}
*/

/*
 * the most biggest difference between 'refarence' and 'pointer'
 * is whether you can use nullptr.
 */
