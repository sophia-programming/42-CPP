#include "PhoneBook.hpp"

/* phonebookも出力する実装に変更する必要がある */
/* constructorのみで完結するようなプログラムがなぜ設計上よくないのかについてもう一度河田さんに聞いておきたい。*/
int main()
{
	PhoneBook phoneBook;
	std::string input;
	while (true) {
		std::cout << GREEN << "Please select one of the options." << STOP << std::endl;
		std::cout << UNDERLINE << "[ ADD | SEARCH | EXIT ]  $> " << STOP;

		if (!std::getline(std::cin, input))
			break ;
		if (input == "ADD") {
			phoneBook.addContact();
			continue ;
		}
		else if (input == "SEARCH") {
			phoneBook.searchContact();
			continue ;
		}
		else if (input == "EXIT") {
			return 1;
		}
		else if (is_str_unprintable(input) == true) {
			continue ;
		}
		else {
			std::cout << RED << "invalid input!   "
					  << "Please select one of the options!" << std::endl
					  << "[ ADD | SEARCH | EXIT ]" << STOP << std::endl;
		}
	}
}

/*
 * ↑のelseで書いている警告はユーザーの使い心地から考えると、圧迫感が強いとの指摘をもらった。
 * shellでも確かに何も入力しないようなケースにおいては何かをうながされることもないのでunprintableの時には
 * 何もしないという実装に変更する(対応ok)
 */
