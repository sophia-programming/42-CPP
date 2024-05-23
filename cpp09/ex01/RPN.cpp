#include "RPN.hpp"

static int ft_stoi(std::string &str){
	int num;
	std::stringstream ss(str);

	ss >> num;
	if (!ss || !ss.eof())
		throw std::invalid_argument("Error: Invalid input: " + str);
	if (num < 0 || 10 <= num)
		throw std::invalid_argument("Error: Input number must be in the range 0 to 9");
	return num;
}

RPN::RPN() {}

RPN::RPN(const RPN &to_copy) {
	*this = to_copy;
}

RPN &RPN::operator=(const RPN &to_copy) {
	if (this != &to_copy) {
	}
	return *this;
}

RPN::~RPN() {}

bool RPN::valid_expression(const std::string &expression) {
	return expression.find_first_not_of("0123456789+-*/ ") == std::string::npos;
}

int RPN::calculate(const std::string &expression) {
	std::stringstream postfix(expression);
	std::stack<int> tmp;
	std::string s;

	while (postfix >> s) {
		if (std::isdigit(s[0]))
			tmp.push(ft_stoi(s));
		else if (s == "+" || s == "-" || s == "/" || s == "*") {
			if (tmp.size() < 2) {
				throw NoResultException();
			}
			int right = tmp.top();
			tmp.pop();
			int left = tmp.top();
			tmp.pop();

			if (s == "+") {
				// オーバーフローをチェックする
				if ((right > 0 && left > std::numeric_limits<int>::max() - right) ||
					(right < 0 && left < std::numeric_limits<int>::min() - right)) {
					throw std::overflow_error("Error: Addition overflow");
				}
				tmp.push(left + right);

			} else if (s == "-") {
				// アンダーフローをチェックする
				if ((right < 0 && left > std::numeric_limits<int>::max() + right) ||
					(right > 0 && left < std::numeric_limits<int>::min() + right)) {
					throw std::underflow_error("Error: Subtraction underflow");
				}
				tmp.push(left - right);

			} else if (s == "/") {
				if (right == 0) {
					throw DivisionByZeroException();
				}
				// INT_MIN / -1をチェックする
				if (left == std::numeric_limits<int>::min() && right == -1) {
					throw std::overflow_error("Error: Division overflow");
				}
				tmp.push(left / right);

			} else if (s == "*") {
				// 正の数同士の乗算オーバーフロー, 負の数同士の乗算オーバーフローをチェック
				if ((left > 0 && right > 0 && left > std::numeric_limits<int>::max() / right) ||
				    (left < 0 && right < 0 && left < std::numeric_limits<int>::max() / right)) {
					throw std::overflow_error("Error: Multiplication overflow");
				}
				//正の数と負の数の乗算オーバーフローをチェック
				if ((left > 0 && right < 0 && right < std::numeric_limits<int>::min() / left) ||
				    (left < 0 && right > 0 && left < std::numeric_limits<int>::min() / right)) {
					throw std::overflow_error("Error: Multiplication overflow");
				}
				tmp.push(left * right);
			}
		} else {
			throw std::invalid_argument("Error: Invalid operator: " + s);
		}
	}
	// 演算子が多すぎる場合
	if (tmp.size() != 1) {
		throw NoResultException();
	}
	return tmp.top();
}

const char *RPN::NoResultException::what() const throw() {
	return "RPN exception: No result";
}

const char *RPN::DivisionByZeroException::what() const throw() {
	return "RPN exception: Division by zero";
}
