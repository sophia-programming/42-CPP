#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	try {
		Bureaucrat b("Bureaucrat", 1);
		Form f("Form", 100, 2);
		b.signForm(f);
		b.execute(f);
	} catch (std::exception &e) {
		std::cout << RED << e.what() << STOP << std::endl;
	}
}
