#include "RPN.hpp"

static int ft_stoi(std::string &str){
	int num;
	std::stringstream ss(str);

	ss >> num;
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

uint64_t RPN::calculate(const std::string &expression) {
	int left;
	int right;
	int result;

	std::stringstream postfix(expression);
	std::stack<int> temp;
	std::string s;

	while (postfix >> s){
		if (s == "+" || s == "-" || s == "/" || s == "*"){
			if (temp.size() < 2)
				throw NoResultException();
			right = temp.top();
			temp.pop();
			left = temp.top();
			temp.pop();
			if (s == "+")
				result = left + right;
			else if (s == "-")
				result = left - right;
			else if (s == "/"){
				if (right == 0)
					throw DivisionByZeroException();
				result = left / right;
			}
			else if (s == "*")
				result = left * right;
			temp.push(result);
		}
		else
			temp.push(ft_stoi(s));
	}
	return temp.top();
}

const char *RPN::NoResultException::what() const throw() {
	return "RPN exception: No result";
}

const char *RPN::DivisionByZeroException::what() const throw() {
	return "RPN exception: Division by zero";
}
