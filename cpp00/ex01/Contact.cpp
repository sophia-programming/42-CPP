#include "Contact.hpp"

Contact::Contact(const std::string &firstName,
				 const std::string &lastName,
				 const std::string &nickname,
				 const std::string &phoneNumber,
				 const std::string &darkestSecret)
		: firstName_(firstName),
		  lastName_(lastName),
		  nickname_(nickname),
		  phoneNumber_(phoneNumber),
		  darkestSecret_(darkestSecret) {}

/* default constructor & destructor */
Contact::Contact() {}
Contact::~Contact() {}

const std::string &Contact::getFirstName() const
{
	return firstName_;
}

const std::string &Contact::getLastName() const
{
	return lastName_;
}

const std::string &Contact::getNickname() const
{
	return nickname_;
}

const std::string &Contact::getPhoneNumber() const {
	return phoneNumber_;
}

const std::string &Contact::getDarkestSecret() const
{
	return darkestSecret_;
}
