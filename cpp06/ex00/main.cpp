#include "ScalarConverter.hpp"

//void tester() {
//	std::cout << GREEN << "======= test_error ========" << STOP << std::endl;
//	ScalarConverter::convert("");
//	ScalarConverter::convert("4 2");
//	ScalarConverter::convert("  ");
//	ScalarConverter::convert("..");
//	ScalarConverter::convert("123.456ff");
//	ScalarConverter::convert("42.0.0");
//
//	std::cout << GREEN << "======= ok_test ========" << STOP << std::endl;
//	ScalarConverter::convert(" ");
//	ScalarConverter::convert(".");
//	ScalarConverter::convert("42");
//	ScalarConverter::convert("-42");
//	ScalarConverter::convert("42.0f");
//	ScalarConverter::convert("0");
//	ScalarConverter::convert("-0");
//	ScalarConverter::convert("2147483647");
//	ScalarConverter::convert("-2147483648");
//	ScalarConverter::convert("4.39408f");
//	ScalarConverter::convert("4.39408");
//	ScalarConverter::convert(".5");
//	ScalarConverter::convert("0.5");
//	ScalarConverter::convert(" 123.4567");
//	ScalarConverter::convert("1.234567890123456E012"); //数値的には 1,234,567,890,123,456
//	ScalarConverter::convert("1.234567890123456e-012"); //数値的には 0.000000001234567890123456
//	ScalarConverter::convert("1.00000011920928955078125f"); //floatの1.0
//
//	std::cout << GREEN << "======= test_Pseudo ========" << STOP << std::endl;
//	ScalarConverter::convert("nan");
//	ScalarConverter::convert("nanf");
//	ScalarConverter::convert("inf");
//	ScalarConverter::convert("+inf");
//	ScalarConverter::convert("-inf");
//	ScalarConverter::convert("inff");
//	ScalarConverter::convert("+inff");
//	ScalarConverter::convert("-inff");
//
//	std::cout << GREEN << "======= test_overflow_int ========" << STOP << std::endl;
//	ScalarConverter::convert("2147483648");
//	ScalarConverter::convert("2147483712");
//	ScalarConverter::convert("-2147483649");
//	ScalarConverter::convert("-2147483712");
//	ScalarConverter::convert("9223372036854775807"); //int64_tの最大値(LONG_MAX)
//	ScalarConverter::convert("9223372036854775810");
//	ScalarConverter::convert("-9223372036854775808"); //int64_tの最小値(LONG_MIN)
//	ScalarConverter::convert("-9223372036854775810");
//
//	std::cout << GREEN << "======= test_overflow_float ========" << STOP << std::endl;
//	ScalarConverter::convert("3.402823466E+38"); //floatの最大値
//	ScalarConverter::convert("1.175494351E-38"); //floatの最小値
//	ScalarConverter::convert("3.402823466E+40");
//	ScalarConverter::convert("1.175494351E-40");
//	ScalarConverter::convert("2.225074e-308"); //0に近い
//
//	std::cout << GREEN << "======= test_overflow_double ========" << STOP << std::endl;
//	ScalarConverter::convert("1.7976931348623158E+308"); //doubleの最大値
//	ScalarConverter::convert("2.2250738585072014E-308"); //doubleの最小値
//	ScalarConverter::convert("1.7976931348623158E+310");
//	ScalarConverter::convert("2.2250738585072014E-310");
//	ScalarConverter::convert("-1.79769313486231570814527424e+309");
//}
//
//int main() {
//	tester();
//}

int	main(int argc, char *argv[]) {
	if (argc != 2 || !argv[0] || !argv[1]) {
		std::cerr << RED << "Usage: " << argv[0] << " <scalar>" << STOP << std::endl;
		return (1);
	}
	std::string str = argv[1];
	ScalarConverter::convert(str);
};
