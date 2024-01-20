#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main() {
	const int numAnimals = 10;
	Animal *animals[numAnimals];

	// 動物のオブジェクトを交互に作成（偶数はDog、奇数はCat）
	for (int i = 0; i < numAnimals; i++) {
		if (i % 2 == 0) {
			animals[i] = new Dog();
		} else {
			animals[i] = new Cat();
		}
	}

	// 各動物の音を出力
	for (int i = 0; i < numAnimals; i++) {
		std::cout << "animals[" << i << "]->makeSound\t";
		animals[i]->makeSound();
	}

	// 動物のオブジェクトを削除
	for (int i = 0; i < numAnimals; i++) {
		delete animals[i];
	}

	std::cout << "+----------------------------------------------------------------+" << std::endl;

	// Catオブジェクトのコピーをテスト（コピーの確認方法はクラスの実装に依存）
	Cat *originalCat = new Cat;
	Cat *copiedCat = new Cat(*originalCat);

	// （ここでコピーがディープコピーであることを確認する方法を実装する）

	delete originalCat;
	delete copiedCat;

	std::cout << "+----------------------------------------------------------------+" << std::endl;

	// メモリリークチェックは適切なツールを使用して実行

	return 0;
}
