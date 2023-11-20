#include <iostream>
#include <string>

class ThisClass {
public:
	ThisClass(const std::string &privacy, const std::string &publicity);

	std::string getPrivacy() const;
	void setPrivacy(const std::string privacy);
private:
	std::string privacy_;
	std::string publicity_;
};

ThisClass::ThisClass(const std::string &privacy, const std::string &publicty)
:privacy_(privacy), publicity_(publicty) {};


std::string ThisClass::getPrivacy() const
{
	return this->privacy_;
}

void ThisClass::setPrivacy(const std::string privacy)
{
	this->privacy_ = privacy;
}

int main()
{
	ThisClass thisclass("private", "public");
	std::cout << "PRIVATE->" << thisclass.getPrivacy() << std::endl;
	std::cout << "CHANGE PRIVATE" << std::endl;
	thisclass.setPrivacy("42Tokyo!!!!!!");
	std::cout << "PRIVATE->" << thisclass.getPrivacy() << std::endl;
}
