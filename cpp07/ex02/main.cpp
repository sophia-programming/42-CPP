#include "Array.hpp"
#include <iostream>

#define MAX_VAL 750
static int pdf_test()
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;//
	return 0;
}

static int my_test (){
	// 空の配列のテスト
	std::cout << BLUE << "===== Testing empty array =====" << STOP << std::endl;
	Array<int> emptyArray;
	std::cout << "Empty array size: " << emptyArray.size() << std::endl;
	try {
		std::cout << emptyArray[2] << std::endl;
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
		std::cout << RED << "Testing out of range access: " << intArray[intArray.size()] << STOP << std::endl;
	} catch (const std::exception& e) {
		std::cout << RED << e.what() << STOP << std::endl;
	}

	// 代入演算子のテスト
	std::cout << BLUE << "===== Testing assignment operator =====" << STOP << std::endl;
	Array<int> originalArray(5);
	for (int i = 0; i < 5; ++i) {
		originalArray[i] = i * 10;
	}

	Array<int> copyArray2;
	copyArray2 = originalArray;

	// 代入後の値を確認
	for (int i = 0; i < 5; ++i) {
		std::cout << "originalArray[" << i << "] = " << originalArray[i] << ", copyArray[" << i << "] = " << copyArray2[i] << std::endl;
	}

	// 値を変更してオリジナルが影響を受けないことを確認
	copyArray2[0] = 100;
	std::cout << "After modifying copyArray, originalArray[0] = " << originalArray[0] << ", copyArray[0] = " << copyArray2[0] << std::endl;

	// constがついていないメンバ関数のテスト
	std::cout << BLUE << "===== Testing non-const member function =====" << STOP << std::endl;
	Array<int> nonConstArray(3);
	nonConstArray[0] = 10;
	nonConstArray[1] = 20;
	nonConstArray[2] = 30;
	for (unsigned int i = 0; i < nonConstArray.size(); i++) {
		nonConstArray[i] = nonConstArray[i] * 2;
		std::cout << "nonConstArray[" << i << "] = " << nonConstArray[i] << std::endl;
	}
	return 0;
}

int main() {
	pdf_test();
	my_test();
	return 0;
}
