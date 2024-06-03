#include "PmergeMe.hpp"
#include "Color.hpp"

int main(int argc, const char *argv[]) {
	try {
		CommandLineParser parser(argc, argv);

		std::vector<long> numVec = parser.getVector();
		std::list<long> numList = parser.getList();

		VectorMergeInsertionSort sortVec;
		ListMergeInsertionSort sortList;

		// display input
		sortVec.displayInput(numVec);
//		sortList.displayInput(numList);

		// sort
		long timeVec = sortVec.sortAndMeasure(numVec);
		long timeList = sortList.sortAndMeasure(numList);

		// display output
		sortVec.displayOutput(numVec);
//		sortList.displayOutput(numList);

		// display time
		sortVec.displayTime(numVec, "std::vector", timeVec);
		sortList.displayTime(numList, "std::list", timeList);

	} catch (const std::exception &e) {
		std::cout << RED << "Error: " << e.what() << STOP << std::endl;
		std::exit(EXIT_FAILURE);
	}
	return (0);
}
