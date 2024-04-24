#include "Array.hpp"
#include <iostream>

int main() {
	// 空の配列のテスト
	std::cout << BLUE << "===== Testing empty array =====" << STOP << std::endl;
	Array<int> emptyArray;
	std::cout << "Empty array size: " << emptyArray.size() << std::endl;
	try {
		std::cout << emptyArray[0] << std::endl;  // これは例外を投げるべき
	} catch (const std::exception& e) {
		std::cout << RED << "Caught exception for accessing empty array: " << e.what() << STOP << std::endl;
	}

	// 初期化された配列のテスト
	std::cout << BLUE << "===== Testing initialized array =====" << STOP << std::endl;
	Array<int> intArray(5);
	std::cout << "Array initialized with size 5." << std::endl;
	for (unsigned int i = 0; i < intArray.size(); i++) {
		intArray[i] = i * 10;
		std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
	}

	// コピーコンストラクタのテスト
	std::cout << BLUE << "===== Testing copy constructor =====" << STOP << std::endl;
	Array<int> copyArray(intArray);
	copyArray[0] = 100;
	std::cout << "After modifying copyArray, intArray[0] = " << intArray[0] << ", copyArray[0] = " << copyArray[0] << STOP << std::endl;

	// 範囲外アクセスのテスト
	try {
		std::cout << RED << "index is out of range: " << intArray[intArray.size()] << STOP << std::endl;
	} catch (const std::exception& e) {
		std::cout << RED << "Caught exception for out of bounds access: " << e.what() << STOP << std::endl;
	}

	// 代入演算子のテスト
	std::cout << BLUE << "===== Testing assignment operator =====" << STOP << std::endl;
	Array<int> assignArray = intArray;
	assignArray[1] = 200;
	std::cout << "After assignment, intArray[1] = " << intArray[1] << ", assignArray[1] = " << assignArray[1] << std::endl;

	return 0;
}
