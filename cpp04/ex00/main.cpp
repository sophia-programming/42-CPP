#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cerr << "___________[CorrectAnimal]______________" << std::endl;
	{
		const Animal *meta = new Animal();
		std::cout << meta->getType() << std::endl;
		meta->makeSound();
		delete meta;
		std::cerr << "________________________________________" << std::endl;


		const Animal *j = new Dog();
		std::cout << j->getType() << std::endl;
		j->makeSound();
		delete j;
		std::cerr << "________________________________________" << std::endl;

		const Animal *i = new Cat();
		std::cout << i->getType() << std::endl;
		i->makeSound();
		delete i;
	}

	std::cerr << "___________[WrongAnimal]________________" << std::endl;
	{
		const WrongAnimal *meta = new WrongAnimal();
		std::cout << meta->getType() << std::endl;
		meta->makeSound();
		delete meta;
		std::cerr << "____________________________________" << std::endl;

		const WrongAnimal *i = new WrongCat();
		std::cout << i->getType() << std::endl;
		i->makeSound();
		delete i;
	}
}


/* PDF */

/*int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	return 0;
}
*/
