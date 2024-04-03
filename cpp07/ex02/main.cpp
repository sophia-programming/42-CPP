#include "Array.hpp"
#include <iostream>

int main() {
	// パラメータなしのコンストラクタによる空の配列の作成
	std::cout << BLUE << "============" << STOP << std::endl;
	Array<int> emptyArray;
	std::cout << "Empty array size: " << emptyArray.size() << std::endl;

	// パラメータ付きコンストラクタによる配列の作成
	std::cout << BLUE << "============" << STOP << std::endl;
	Array<int> intArray(5);
	std::cout << "Array initialized with size 5." << std::endl;

	for (unsigned int i = 0; i < intArray.size(); i++) {
		intArray[i] = i * 10;
		std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
	}

	// コピーコンストラクタによる配列のコピー
	std::cout << BLUE << "============" << STOP << std::endl;
	Array<int> copyArray(intArray);
	std::cout << "Copy of intArray created." << std::endl;

	// コピーされた配列の要素を変更し、元の配列と異なるか比較
	std::cout << BLUE << "============" << STOP << std::endl;
	copyArray[0] = 100;
	std::cout << YELLOW << "After modifying copyArray, intArray[0] = " << intArray[0] << ", copyArray[0] = " << copyArray[0] << STOP << std::endl;

	// 範囲外アクセスのテスト
	try {
		std::cout << RED << "index is out of range: " << intArray[intArray.size()] << STOP << std::endl;
	} catch (std::exception& e) {
		std::cout << RED << "Caught exception for out of bounds access." << STOP << std::endl;
	}

	// 代入演算子による配列のコピーと変更
	Array<int> assignArray = intArray;
	assignArray[1] = 200;
	std::cout << "After assignment, intArray[1] = " << intArray[1] << ", assignArray[1] = " << assignArray[1] << std::endl;

	return 0;
}
