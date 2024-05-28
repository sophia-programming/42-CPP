#include "PmergeMe.hpp"

// CommandLineParserクラスの実装
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

// VectorMergeInsertionSortクラスの実装
VectorMergeInsertionSort::VectorMergeInsertionSort() {}
VectorMergeInsertionSort::VectorMergeInsertionSort(const VectorMergeInsertionSort &sort) {
	*this = sort;
}
VectorMergeInsertionSort &VectorMergeInsertionSort::operator=(const VectorMergeInsertionSort &sort) {
	if (this != &sort) {}
	return (*this);
}
VectorMergeInsertionSort::~VectorMergeInsertionSort() {}

void VectorMergeInsertionSort::sort(std::vector<long> &vec) {
	size_t n = vec.size();
	std::vector<std::pair<int, int> > pairs;
	std::vector<long> mainChain;

	// Step 1: ペアを作成し、ソート
	for (size_t i = 0; i < n; i += 2) {
		if (i + 1 < n) {
			pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
		} else {
			pairs.push_back(std::make_pair(vec[i], vec[i]));
		}
	}

	// Step 2: ペアのa要素を再帰的にソート
	pairSortVec(pairs, mainChain);
	std::sort(mainChain.begin(), mainChain.end());

	// Step 3: b要素をJacobsthal数列の順に挿入
	std::vector<long> bs;
	for (size_t i = 0; i < pairs.size(); ++i) {
		bs.push_back(pairs[i].second);
	}

	std::vector<long> order;
	vecInsertionOrder(order, bs.size());

	mergeInsertVec(mainChain, bs, order);

	// ソートされた要素を元のvectorにコピー
	for (size_t i = 0; i < n; ++i) {
		vec[i] = mainChain[i];
	}
}

// ListMergeInsertionSortクラスの実装
ListMergeInsertionSort::ListMergeInsertionSort() {}
ListMergeInsertionSort::ListMergeInsertionSort(const ListMergeInsertionSort &sort) {
	*this = sort;
}
ListMergeInsertionSort &ListMergeInsertionSort::operator=(const ListMergeInsertionSort &sort) {
	if (this != &sort) {}
	return (*this);
}
ListMergeInsertionSort::~ListMergeInsertionSort() {}

void ListMergeInsertionSort::sort(std::list<long> &lst) {
	std::list<std::pair<int, int> > pairs;
	std::list<long> mainChain;

	// Step 1: ペアを作成し、ソート
	std::list<long>::iterator it = lst.begin();
	while (it != lst.end()) {
		int first = *it;
		++it;
		int second = (it != lst.end()) ? *it : first;
		pairs.push_back(std::make_pair(first, second));
		if (it != lst.end()) ++it;
	}

	// Step 2: ペアのa要素を再帰的にソート
	pairSortList(pairs, mainChain);
	mainChain.sort();

	// Step 3: b要素をJacobsthal数列の順に挿入
	std::list<long> bs;
	for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
		bs.push_back(it->second);
	}

	std::vector<long> order;
	listInsertionOrder(order, bs.size());

	mergeInsertList(mainChain, bs, order);

	// ソートされた要素を元のlistにコピー
	lst = mainChain;
}

// ヘルパー関数の実装
void pairSortVec(std::vector<std::pair<int, int> > &pairs, std::vector<long> &mainChain) {
	for (size_t i = 0; i < pairs.size(); ++i) {
		if (pairs[i].first > pairs[i].second) {
			std::swap(pairs[i].first, pairs[i].second);
		}
		mainChain.push_back(pairs[i].first);
	}
}

void pairSortList(std::list<std::pair<int, int> > &pairs, std::list<long> &mainChain) {
	for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
		if (it->first > it->second) {
			std::swap(it->first, it->second);
		}
		mainChain.push_back(it->first);
	}
}

void vecInsertionOrder(std::vector<long> &order, int n) {
	for (int i = 1; i <= n; ++i) {
		int value = (int)(std::log(i * 3 / 4.0) / std::log(2.0));
		if (value < n) {
			order.push_back(value);
		}
	}
}

void listInsertionOrder(std::vector<long> &order, int n) {
	for (int i = 1; i <= n; ++i) {
		int value = (int)(std::log(i * 3 / 4.0) / std::log(2.0));
		if (value < n) {
			order.push_back(value);
		}
	}
}

void mergeInsertVec(std::vector<long> &mainChain, std::vector<long> &bs, const std::vector<long> &order) {
	for (size_t i = 0; i < order.size(); ++i) {
		int value = bs[order[i] - 1];
		std::vector<long>::iterator it = std::upper_bound(mainChain.begin(), mainChain.end(), value);
		mainChain.insert(it, value);
	}
}

void mergeInsertList(std::list<long> &mainChain, std::list<long> &bs, const std::vector<long> &order) {
	for (size_t i = 0; i < order.size(); ++i) {
		int value = *(std::next(bs.begin(), order[i] - 1));
		std::list<long>::iterator it = mainChain.begin();
		while (it != mainChain.end() && *it < value) {
			++it;
		}
		mainChain.insert(it, value);
	}
}

// ソート関数の実装
void mergeInsertionSort(std::vector<long> &vec) {
	VectorMergeInsertionSort sorter;
	sorter.sort(vec);
}

void mergeInsertionSort(std::list<long> &lst) {
	ListMergeInsertionSort sorter;
	sorter.sort(lst);
}
