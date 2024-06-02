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

	for (int i = 1; i < argc; i++) {
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
	std::vector<std::pair<long, long> > pairs;
	std::vector<long> mainChain; // a要素を格納
	std::vector<long> remainingBs; // b要素を格納

	// Step 1: ペアを作成し、ソート
	for (size_t i = 0; i < n; i += 2) {
		// i+1の必要性：要素数が奇数の場合、最後の要素はb要素になる
		// 例) 1 2 3 4 5 -> (1, 2) (3, 4) (5)
		if (i + 1 < n) {
			pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
		} else {
			remainingBs.push_back(vec[i]);
		}
	}

	// Step 2: ペアのa要素を再帰的にソート
	// 例) (1, 2) (3, 4) (5) -> 1 3がmainChainに追加。5はremainingBsに追加
	pairSortVec(pairs, mainChain);

	// 残ったb要素(2 4 5)をbsに追加
	std::vector<long> bs;
	for (size_t i = 0; i < pairs.size(); ++i) {
		bs.push_back(pairs[i].second);
	}

	// remainingBsをbsに追加
	bs.insert(bs.end(), remainingBs.begin(), remainingBs.end());

	// bsの要素を順番に並び替える
	std::vector<long> order;
	vecInsertionOrder(order, bs.size());

	// Step 3:　b要素をsortされたmainChainに挿入
	mergeInsertVec(mainChain, bs, order);

	// ソートされた要素を元のvectorにコピー
	for (size_t i = 0; i < n; ++i) {
		vec[i] = mainChain[i];
	}
}

void VectorMergeInsertionSort::mergeInsertVec(std::vector<long> &mainChain, std::vector<long> &bs, const std::vector<long> &order) {
	for (size_t i = 0; i < order.size(); ++i) {
		for (size_t j = 0; j <= order.size(); ++j) {
			std::cout << RED << order[j] << ' ' << STOP ;
		}
		long value = bs[order[i] - 1];
		std::vector<long>::iterator it = binarySearchInsertPosition(mainChain, value);
		mainChain.insert(it, value);
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
	std::list<std::pair<long, long> > pairs;
	std::list<long> mainChain;

	// Step 1: ペアを作成し、ソート
	std::list<long>::iterator it = lst.begin();
	while (it != lst.end()) {
		long first = *it;
		++it;
		long second = (it != lst.end()) ? *it : first;
		pairs.push_back(std::make_pair(first, second));
		if (it != lst.end()) ++it;
	}

	// Step 2: ペアのa要素を再帰的にソート
	pairSortList(pairs, mainChain);
	mainChain.sort();

	// 残ったb要素をbsに追加
	std::list<long> bs;
	for (std::list<std::pair<long, long> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
		bs.push_back(it->second);
	}

	// bsの要素を順番に並び替える
	std::vector<long> order;
	listInsertionOrder(order, bs.size());

	// Step 3:　b要素をsortされたmainChainに挿入
	mergeInsertList(mainChain, bs, order);

	// ソートされた要素を元のlistにコピー
	lst = mainChain;
}

/* 二分探索で挿入位置を探す
 * 引数1: mainChain: ソート済みのvector
 * 引数2: bs: 挿入する値
 * 引数3: order: 挿入する順番 */
void ListMergeInsertionSort::mergeInsertList(std::list<long> &mainChain, std::list<long> &bs, const std::vector<long> &order) {
	for (size_t i = 0; i < order.size(); ++i) {
		if (order[i] <= 0 || order[i] > static_cast<int>(bs.size())) continue;
		long value = *(std::next(bs.begin(), order[i] - 1));
		std::list<long>::iterator it = binarySearchInsertPosition(mainChain, value);
		mainChain.insert(it, value);
	}
}

// ヘルパー関数の実装
void pairSortVec(std::vector<std::pair<long, long> > &pairs, std::vector<long> &mainChain) {
	for (size_t i = 0; i < pairs.size(); ++i) {
		if (pairs[i].first > pairs[i].second) {
			std::swap(pairs[i].first, pairs[i].second);
		}
		mainChain.push_back(pairs[i].first);
	}
}

void pairSortList(std::list<std::pair<long, long> > &pairs, std::list<long> &mainChain) {
	for (std::list<std::pair<long, long> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
		if (it->first > it->second) {
			std::swap(it->first, it->second);
		}
		mainChain.push_back(it->first);
	}
}

/* bsを並び替える関数
   引数1: order: 挿入する順番
   引数2: n: Jacobsthal数列の長さ */
void vecInsertionOrder(std::vector<long> &order, int n) {
	for (int i = 1; i <= n; ++i) {
		int value = static_cast<int>(std::log(i * 3 / 4.0) / std::log(2.0));
		if (value < n) {
			order.push_back(value);
		}
	}
}

void listInsertionOrder(std::vector<long> &order, int n) {
	for (int i = 1; i <= n; ++i) {
		int value = static_cast<int>(std::log(i * 3 / 4.0) / std::log(2.0));
		if (value < n) {
			order.push_back(value);
		}
	}
}
