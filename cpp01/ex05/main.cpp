#include "Harl.hpp"

int main()
{
	Harl harl;
	/* DEBUG */
	harl.complain("DEBUG");
	/* INFO */
	harl.complain("INFO");
	/* WARNING */
	harl.complain("WARNING");
	/* ERROR */
	harl.complain("ERROR");
	/* exception */
	harl.complain("INVALID");
}
