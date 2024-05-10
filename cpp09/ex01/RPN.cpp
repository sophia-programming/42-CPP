#include "RPN.hpp"

static int ft_stoi(std::string &str){
	int num;
	std::stringstream ss(str);

	ss >> num;
	if (10 <= num )
		throw std::invalid_argument("Error: Input number must be less than 10");
	else if (num <= -10)
		throw std::invalid_argument("Error: Input number must be greater than -10");
	return num;
}

RPN::RPN() {}

RPN::RPN(const RPN &to_copy) {
	*this = to_copy;
}

RPN &RPN::operator=(const RPN &to_copy) {
	if (this != &to_copy) {
		*this = to_copy;
	}
	return *this;
}

RPN::~RPN() {}

bool RPN::valid_expression(const std::string &expression) {
	if (expression.find_first_not_of("0123456789+-*/ ") == std::string::npos)
		return true;
	return false;
}

int RPN::calculate(const std::string &expression) {
	std::stringstream postfix(expression);
	std::stack<int> tmp;
	std::string s;

	while (postfix >> s) {
		if (std::isdigit(s[0]) || (s[0] == '-' && s.length() > 1))
			tmp.push(ft_stoi(s));
		else if (s == "+" || s == "-" || s == "/" || s == "*") {
			if (tmp.size() < 2) {
				throw NoResultException();
			}
			int right = tmp.top();
			tmp.pop();
			int left = tmp.top();
			tmp.pop();

			if (s == "+")
				tmp.push(left + right);
			else if (s == "-")
				tmp.push(left - right);
			else if (s == "/") {
				if (right == 0)
					throw DivisionByZeroException();
				tmp.push(left / right);
			}
			else if (s == "*")
				tmp.push(left * right);
		} else
			tmp.push(ft_stoi(s));
	}
	if (tmp.size() != 1)
		throw NoResultException(); // Ensures only one result is left in the stack, indicating proper RPN format
	return tmp.top();
}

const char *RPN::NoResultException::what() const throw() {
	return "RPN exception: No result";
}

const char *RPN::DivisionByZeroException::what() const throw() {
	return "RPN exception: Division by zero";
}
