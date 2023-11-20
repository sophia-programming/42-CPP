#include <iostream>

int main()
{
	const int64_t Nb_Nbrs = 100;
	int64_t *nbrs = new int64_t [Nb_Nbrs];
	for (int64_t i = 0; i < Nb_Nbrs; i++) {
		nbrs[i] = i + 1;
		std::cout << nbrs[i] << std::endl;
	}
	delete [] nbrs;
}
