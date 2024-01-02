#include <iostream>

//-----------------  [1]  ------------------
//int main()
//{
//	std::cout << "HELLO " << 42  << " neko" << std::endl;
//}

//-----------------  [2]  ------------------
//int main()
//{
//	int num;
//
//	std::cin >> num;
//	// 文字が数値でなかった場合のエラー処理
//	if (std::cin.fail())
//	{
//		// std::cin にエラーフラグが立っているので、エラーフラグを解除する
//		std::cin.clear();
//		// std::cin に残っている文字を読み飛ばす
//		std::cin.ignore(100, '\n');
//	}
//	std::cout << num << std::endl;
//}

//-----------------  [3]  ------------------
using namespace std;

class Car {
public:
//	const char *owner;
//	const char *colour;
    std :: string owner;
	std :: string colour;
	int number;
};

int main() {
	auto a = Car();
	a.owner = "Rera";
	a.colour = "Blue";
	a.number = 1234;
	cout << "a.owner = " << a.owner << ", a.colour = " << a.colour << ", a.number = " << a.number << endl;
}
