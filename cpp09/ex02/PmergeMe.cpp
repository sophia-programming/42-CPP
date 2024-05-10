#include "PmergeMe.hpp"

CommandLineParser::CommandLineParser(const int argc, const char *argv[]) {
	parseArgument(argc, argv);
}

CommandLineParser::CommandLineParser() {}

CommandLineParser::CommandLineParser(const CommandLineParser &parser) {
	*this = parser;
}

CommandLineParser &CommandLineParser::operator=(const CommandLineParser &parser) {
	if (this != &parser) {
		numVec_ = parser.numVec_;
		numList_ = parser.numList_;
	}
	return (*this);
}

CommandLineParser::~CommandLineParser() {}

const std::vector<long> &CommandLineParser::getVector() const {
	return (this->numVec_);
}

const std::list<long> &CommandLineParser::getList() const {
	return (this->numList_);
}

void CommandLineParser::parseArgument(const int argc, const char *argv[]) {
	long num;

	if (argc == 1)
		throw std::invalid_argument("Argument is empty");

	for (long i = 1; i < argc; i++) {
		std::istringstream iss(argv[i]);
		iss >> num;
		if (iss.fail() || iss.peek() != EOF) {
			throw std::invalid_argument("Invalid input: " + std::string(argv[i]));
		} else if (num <= 0) {
			throw std::invalid_argument("Minus or Zero value: " + std::string(argv[i]));
		}
		numVec_.push_back(num);
		numList_.push_back(num);
	}
}

// VectorMergeInsertionSort
VectorMergeInsertionSort::VectorMergeInsertionSort() {}

VectorMergeInsertionSort::~VectorMergeInsertionSort() {}

void VectorMergeInsertionSort::sort(std::vector<long> &container) {
	if (container.size() <= 1) {
		return;
	}

	std::vector<long> smaller, larger;

	// 1. pair of elements are compared;
	for (std::size_t i = 0; i < container.size(); i += 2) {
		if (i + 1 < container.size()) {
			if (container.at(i) < container.at(i + 1)) {
				smaller.push_back(container.at(i));
				larger.push_back(container.at(i + 1));
			} else {
				smaller.push_back(container.at(i + 1));
				larger.push_back(container.at(i));
			}
		} else {
			larger.push_back(container.at(i));
		}
	}

	// 2. the larger elements are sorted recursively;
	sort(larger);

	// 3. insert small container elements into the already sorted large container
	for (std::size_t i = 0; i < smaller.size(); i++) {
		std::vector<long>::iterator insertPos =
				binarySearchInsertPosition(larger, smaller.at(i));
		larger.insert(insertPos, smaller.at(i));
	}
	container = larger;
}

VectorMergeInsertionSort::VectorMergeInsertionSort(const VectorMergeInsertionSort &sort): MergeInsertionSort(sort) {
	(void)sort;
}

VectorMergeInsertionSort &VectorMergeInsertionSort::operator=(const VectorMergeInsertionSort &sort) {
	if (this != &sort) {
	}
	return (*this);
}


// ListMergeInsertionSort
ListMergeInsertionSort::ListMergeInsertionSort() {}

ListMergeInsertionSort::~ListMergeInsertionSort() {}

void ListMergeInsertionSort::sort(std::list<long> &container) {
	if (container.size() <= 1) {
		return;
	}

	std::list<long> smaller, larger;

	// 1. pair of elements are compared;
	std::list<long>::iterator it = container.begin();
	std::list<long>::iterator current;

	while (it != container.end()) {
		current = it++;
		if (it != container.end()) {
			if (*current < *it) {
				smaller.push_back(*current);
				larger.push_back(*it);
			} else {
				smaller.push_back(*it);
				larger.push_back(*current);
			}
			it++;
		} else {
			larger.push_back(*current);
		}
	}

	// 2. the larger elements are sorted recursively;
	sort(larger);

	// 3. insert small container elements into the already sorted large container
	for (std::list<long>::iterator it = smaller.begin(); it != smaller.end();
		 it++) {
		std::list<long>::iterator insertPos = larger.begin();
		while (insertPos != larger.end() && *insertPos < *it) {
			insertPos++;
		}
		larger.insert(insertPos, *it);
	}
	container = larger;
}

ListMergeInsertionSort::ListMergeInsertionSort(const ListMergeInsertionSort &sort) : MergeInsertionSort(sort) {
	(void)sort;
}

ListMergeInsertionSort &ListMergeInsertionSort::operator=(const ListMergeInsertionSort &sort) {
	if (this != &sort) {
	}
	return (*this);
}
