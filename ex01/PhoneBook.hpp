#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

#include "Contact.hpp"
#include "color.hpp"

#define MAX_CONTACT 8
//↑defineよりもconst int maxContactの方が良さそう←調べればすぐに出てくる

/* PhoneBookにすべき(ファイル自体もPhoneBook.cppみたいにした方がいい←pdfに書いてある)*/
/* privateを基本にした方がいい理由を調べる(関数も含め)　*/
class PhoneBook {
public:
	PhoneBook();
	~PhoneBook();


	void addContact();
	void searchContact();
private:
	void retryAddContact();
	void printOnlyInput(size_t input);
	void printTable();
	Contact contact[MAX_CONTACT];
	size_t	headIndex_;
	size_t	insertIndex_;
};

bool is_str_unprintable(const std::string &str);
#endif
