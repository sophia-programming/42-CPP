#include "PmergeMe.hpp"
#include <stdio.h>

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
		if (i + 1 < n)
			pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
		else
			remainingBs.push_back(vec[i]);
	}

	// Step 2: ペアをsortしてmainChainにa要素（小さい方の値）を追加
	// 例) (1, 2) (3, 4) (5) -> 1 3がmainChainに追加。5はremainingBsに追加
	pairSortVec(pairs, mainChain);

	// 残ったb要素(2 4 5)をremainingBsに追加
	for (size_t i = 0; i < pairs.size(); ++i){
		remainingBs.push_back(pairs[i].second);
	}

	// Step 3: remainingBsの要素をJacobsthal数列に基づいてmainChainに挿入
	insertRemainingBsUsingJacobsthal(mainChain, remainingBs);

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

//void ListMergeInsertionSort::sort(std::list<long> &lst) {
//	std::list<std::pair<long, long> > pairs;
//	std::list<long> mainChain;
//
//	 Step 1: ペアを作成し、ソート
//	std::list<long>::iterator it = lst.begin();
//	while (it != lst.end()) {
//		long first = *it;
//		++it;
//		long second = (it != lst.end()) ? *it : first;
//		pairs.push_back(std::make_pair(first, second));
//		if (it != lst.end()) ++it;
//	}
//
//	 Step 2: ペアのa要素を再帰的にソート
//	pairSortList(pairs, mainChain);
//	mainChain.sort();
//
//	 残ったb要素をbsに追加
//	std::list<long> bs;
//	for (std::list<std::pair<long, long> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
//		bs.push_back(it->second);
//	}
//
//
//	 bsの要素を順番に並び替える
//	std::vector<long> order;
//	listInsertionOrder(order, bs.size());
//
//	 Step 3:　b要素をsortされたmainChainに挿入
//	mergeInsertList(mainChain, bs, order);
//
//	 ソートされた要素を元のlistにコピー
//	lst = mainChain;
//}
//
///* 二分探索で挿入位置を探す
// * 引数1: mainChain: ソート済みのvector
// * 引数2: bs: 挿入する値
// * 引数3: order: 挿入する順番 */
//void ListMergeInsertionSort::mergeInsertList(std::list<long> &mainChain, std::list<long> &bs, const std::vector<long> &order) {
//	for (size_t i = 0; i < order.size(); ++i) {
//		if (order[i] <= 0 || order[i] > static_cast<int>(bs.size())) continue;
//		long value = *(std::next(bs.begin(), order[i] - 1));
//		std::list<long>::iterator it = binarySearchInsertPosition(mainChain, value);
//		mainChain.insert(it, value);
//	}
//}


// ペアをソートし、mainChainにa要素を追加
void pairSortVec(std::vector<std::pair<long, long> > &pairs, std::vector<long> &mainChain) {
	for (size_t i = 0; i < pairs.size(); ++i) {
		if (pairs[i].first > pairs[i].second) {
			std::swap(pairs[i].first, pairs[i].second);
		}
		mainChain.push_back(pairs[i].first);
	}
}

//void pairSortList(std::list<std::pair<long, long> > &pairs, std::list<long> &mainChain) {
//	for (std::list<std::pair<long, long> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
//		if (it->first > it->second) {
//			std::swap(it->first, it->second);
//		}
//		mainChain.push_back(it->first);
//	}
//}


// Jacobsthal数列を生成する関数
std::vector<int> generateJacobsthalSequence(int n) {
	std::vector<int> jacobsthal;
	jacobsthal.push_back(1); // 初期値 Jacobsthal(1) = 1
	jacobsthal.push_back(3); // 初期値 Jacobsthal(2) = 3
	int i = 2;
	while (true) {
		int next = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
		if (next >= n) break;
		jacobsthal.push_back(next);
		++i;
	}
	return jacobsthal;
}


// 二分探索で挿入位置を探す
size_t binarySearchInsertPosition (const std::vector<long>& mainChain, long value) {
	return std::lower_bound(mainChain.begin(), mainChain.end(), value) - mainChain.begin();
}


// Jacobsthal数列に基づいてremainingBsの要素を挿入する関数
void insertRemainingBsUsingJacobsthal(std::vector<long>& mainChain, const std::vector<long>& remainingBs) {
	std::vector<int> jacobsthal = generateJacobsthalSequence(remainingBs.size());
	std::reverse(jacobsthal.begin(), jacobsthal.end());  // 大きい数から順に使用するため逆順にする

	for (size_t j = 0; j < jacobsthal.size(); ++j) {
		int index = jacobsthal[j];
		if (index < static_cast<int>(remainingBs.size())) {
			long value = remainingBs[index];
			size_t pos = binarySearchInsertPosition(mainChain, value);
			mainChain.insert(mainChain.begin() + pos, value);
		}
	}

	// Jacobsthal数列に含まれていないremainingBsの要素を挿入
	for (size_t i = 0; i < remainingBs.size(); ++i) {
		if (std::find(jacobsthal.begin(), jacobsthal.end(), i) == jacobsthal.end()) {
			long value = remainingBs[i];
			size_t pos = binarySearchInsertPosition(mainChain, value);
			mainChain.insert(mainChain.begin() + pos, value);
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
