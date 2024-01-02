#include "PhoneBook.hpp"

/*-------utils--------*/
bool	is_str_digit(const std::string &str)
{
	size_t i = 0;
	while (str[i]) {
		if (str[i] < '0' || '9' < str[i]) {
			return false;
		}
		i++;
	}
	return true;
}

void printContact(const std::string &str)
{
	std::cout << UNDERLINE << "|";
	if (10 < str.size()) {
		std::cout << str.substr(0, 9) + ".";
	} else {
		std::cout << std::right << std::setw(10) << str;
		std::cout << STOP;
	}
}

bool is_printable(const char c)
{
	return (' ' < c && c <= '~');
}

bool is_str_unprintable(const std::string &str)
{
	size_t i = 0;
	while (str[i]) {
		if (is_printable(str[i]) == true)
			return false;
		i++;
	}
	return true;
}

/* [SEARCH] */
void PhoneBook::printTable() {
	std::cout << UNDERLINE
	<< "                                             "
	<< std::endl
	<< "|    ID    |FIRSTNAME | LASTNAME | NICKNAME |"
	<< std::endl
	<< STOP;
	for (size_t i = 0; i < 8; i++) {
		std::stringstream sstream;
		sstream << i;
		printContact(sstream.str());
		printContact(contact[i].getFirstName());
		printContact(contact[i].getLastName());
		printContact(contact[i].getNickname());
		std::cout << "|" << std::endl;
	}
}

void PhoneBook::printOnlyInput(size_t index)
{
	std::cout << "FIRSTNAME     : " << contact[index].getFirstName() << std::endl;
	std::cout << "LASTNAME      : " << contact[index].getLastName() << std::endl;
	std::cout << "NICKNAME      : " << contact[index].getNickname() << std::endl;
	std::cout << "PHONENUMBER   : " << contact[index].getPhoneNumber() << std::endl;
	std::cout << "DARKESTSECRET : " << contact[index].getDarkestSecret() << std::endl;
}

void PhoneBook::searchContact()
{
	PhoneBook::printTable();
	std::cout << GREEN << "Please tell me [ID] you want to know!" << STOP << std::endl;

	std::string input;
	if (!std::getline(std::cin, input)
	|| is_str_digit(input) == false
	||input.length() > 1) {
		std::cout << RED << "Invalid input." << std::endl;
		return ;
	}
	size_t index;
	std::istringstream(input) >> index;
	if (headIndex_ <= index || headIndex_ == 0) {
		std::cout << RED << "You can't know the [ID]!!" << STOP << std::endl;
		return ;
	}
	if (index <= 7) {
		this->printOnlyInput(index);
	}
	else {
		std::cout << BLUE << "You should input the number from 0 to 7 (personal [ID])." << STOP << std::endl;
	}
}

/* [ADD] */
void PhoneBook::retryAddContact()
{
	std::cout << GREEN << "Retry[ADD]!" << STOP << std::endl;
	addContact();
}

void PhoneBook::addContact() {
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

	std::cout << UNDERLINE
	<< "FirstName     $> ";
	if (!getline(std::cin, firstName) || is_str_unprintable(firstName) == true) {
		retryAddContact();
		return ;
	}
	std::cout << "LastName      $> ";
	if (!getline(std::cin, lastName) || is_str_unprintable(lastName) == true) {
		retryAddContact();
		return ;
	}
	std::cout << "Nickname      $> ";
	if (!getline(std::cin, nickname) || is_str_unprintable(nickname) == true) {
		retryAddContact();
		return ;
	}
	std::cout << "phoneNumber   $> ";
	if (!getline(std::cin, phoneNumber)
	|| is_str_unprintable(phoneNumber) == true
	|| is_str_digit(phoneNumber) == false) {
		retryAddContact();
		return ;
	}
	std::cout << "DarkestSecret $> " << STOP;
	if (!getline(std::cin, darkestSecret) || is_str_unprintable(darkestSecret) == true) {
		retryAddContact();
		return ;
	}
	if (headIndex_ < 8) {
		contact[headIndex_++] = Contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
	}
	else if (headIndex_ == 8) {
		contact[insertIndex_++] = Contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
	}
	else if (headIndex_ == 8 && insertIndex_ == 8) {
		insertIndex_ = 0;
		contact[insertIndex_++] = Contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
	}
}

PhoneBook::PhoneBook() : headIndex_(0), insertIndex_(0) {}

/*PhoneBook class destructor*/
PhoneBook::~PhoneBook()
{
	std::cout << CYAN <<  "That's all!!!" << STOP << std::endl;
}
