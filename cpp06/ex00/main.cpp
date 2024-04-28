#include "ScalarConverter.hpp"

void tester() {
	std::cout << GREEN << "======= test_error ========" << STOP << std::endl;
	ScalarConverter::convert("");
	ScalarConverter::convert("4 2");
	ScalarConverter::convert("  ");
	ScalarConverter::convert("..");
	ScalarConverter::convert("123.456ff");
	ScalarConverter::convert("42.0.0");

	std::cout << GREEN << "======= ok_test ========" << STOP << std::endl;
	ScalarConverter::convert(" ");
	ScalarConverter::convert(".");
	ScalarConverter::convert("42");
	ScalarConverter::convert("-42");
	ScalarConverter::convert("0");
	ScalarConverter::convert("-0");
	ScalarConverter::convert("2147483647");
	ScalarConverter::convert("-2147483648");
	ScalarConverter::convert("4.39408f");
	ScalarConverter::convert("4.39408");
	ScalarConverter::convert(".5");
	ScalarConverter::convert("0.5");
	ScalarConverter::convert(" 123.4567");
	ScalarConverter::convert("1.234567890123456E012");
	ScalarConverter::convert("1.234567890123456e-012");

	std::cout << GREEN << "======= test_Pseudo ========" << STOP << std::endl;
	ScalarConverter::convert("nan");
	ScalarConverter::convert("nanf");
	ScalarConverter::convert("inf");
	ScalarConverter::convert("+inf");
	ScalarConverter::convert("-inf");
	ScalarConverter::convert("inff");
	ScalarConverter::convert("+inff");
	ScalarConverter::convert("-inff");

	std::cout << GREEN << "======= test_overflow_int ========" << STOP << std::endl;
	ScalarConverter::convert("2147483648");
	ScalarConverter::convert("2147483711");
	ScalarConverter::convert("-2147483649");
	ScalarConverter::convert("-2147483712");
	ScalarConverter::convert("9223372036854775807");
	ScalarConverter::convert("9223372036854775808");
	ScalarConverter::convert("-9223372036854775808");
	ScalarConverter::convert("-9223372036854775809");

//	std::cout << GREEN << "======= test_overflow_float ========" << STOP << std::endl;
//	ScalarConverter::convert("3.402823466E+39");
//	ScalarConverter::convert("-1.175494351E-39");
//	ScalarConverter::convert("1.00000011920928955078125f");
//	ScalarConverter::convert("1.175494e-38f");
//	ScalarConverter::convert("1.000000059604644775390625f");
//	ScalarConverter::convert("1.79769313486231570814527424e+308");
//	ScalarConverter::convert("-1.79769313486231570814527424e+308");
//	ScalarConverter::convert("2.225074e-308");
//	ScalarConverter::convert("1.00000000000000000011102230246251565404236316680908203125e-309");
}

int	main(int argc, char *argv[]) {
	(void)argc;
	(void)argv;
//	if (argc != 2 || !argv[0] || !argv[1]) {
//		std::cerr << RED << "Usage: " << argv[0] << " <scalar>" << STOP << std::endl;
//		return (1);
//	}
//	std::string str = argv[1];
//	ScalarConverter::convert(str);
	tester();
};
