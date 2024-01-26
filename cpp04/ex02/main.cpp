#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

int main() {
	const int numAnimals = 4;
	AAnimal* animals[numAnimals];

	// Animal配列にDogとCatを交互に割り当て
	for (int i = 0; i < numAnimals; i++) {
		if (i % 2 == 0) {
			animals[i] = new Dog();
		} else {
			animals[i] = new Cat();
		}
	}

	// 各AnimalのmakeSoundメソッドをテスト
	for (int i = 0; i < numAnimals; i++) {
		std::cout << GREEN << "animals[" << i << "]->makeSound->";
		animals[i]->makeSound();
		std::cout << STOP;
	}

	for (int i = 0; i < numAnimals; i++)
		delete animals[i];

	// Brainクラス テスト
	std::cout << RED << "============= Brain Test ===================" << STOP << std::endl;
	Dog *dog = new Dog;
	Dog *dogCopy = new Dog(*dog);
	std::cout << "Dog *dog Brain: " << dog->getBrain() << std::endl;
	std::cout << "Dog *dogCopy Brain: " << dogCopy->getBrain() << std::endl;
	delete dog;
	delete dogCopy;

	// CatとDogのコピーコンストラクタをテスト
	std::cout << RED << "============== dog  copy test  ===================" << STOP << std::endl;
	Dog originalDog;
	Dog copyDog(originalDog);

	std::cout << RED << "============== cat  copy test  ===================" << STOP << std::endl;
	Cat originalCat;
	Cat copyCat(originalCat);

	std::cout << GREEN << "All animals were deleted successfully." << STOP << std::endl;

	return 0;
}
