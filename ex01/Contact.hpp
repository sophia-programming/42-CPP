#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact {
private:
	std::string firstName_;
	std::string lastName_;
	std::string nickname_;
	std::string phoneNumber_;
	std::string darkestSecret_;

public:
	Contact();
	Contact(const std::string &firstName,
			const std::string &lastName,
			const std::string &nickname,
			const std::string &phoneNumber,
			const std::string &darkestSecret);
	~Contact();

	// setter
	void setFirstName(const std::string &firstName);
	void setLastName(const std::string &lastName);
	void setNickname(const std::string &nickname);
	void setPhoneNumber(const std::string &phoneNumber);
	void setDarkestSecret(const std::string &darkestSecret);

	// getter
	const std::string &getFirstName() const;
	const std::string &getLastName() const;
	const std::string &getNickname() const;
	const std::string &getPhoneNumber() const;
	const std::string &getDarkestSecret() const;
};

#endif
