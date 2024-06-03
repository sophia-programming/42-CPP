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


	// Step 1: ペアを作成
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

void ListMergeInsertionSort::sort(std::list<long> &lst) {
	std::list<std::pair<long, long> > pairs;
	std::list<long> mainChain;
	std::list<long> remainingBs;

//	 Step 1: ペアを作成
	std::list<long>::iterator it = lst.begin();
	while (it != lst.end()) {
		long first = *it;
		++it;
		if (it != lst.end()) {
			long second = *it;
			pairs.push_back(std::make_pair(first, second));
			++it;
		} else
			remainingBs.push_back(first);
	}

//	 Step 2: ペアをsortしてmainChainにa要素（小さい方の値）を追加
	pairSortList(pairs, mainChain);

	// 残ったb要素をremainingBsに追加
	for (std::list<std::pair<long, long> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
		remainingBs.push_back(it->second);
	}

//	Step 3: remainingBsの要素をJacobsthal数列に基づいてmainChainに挿入
	insertRemainingBsUsingJacobsthal(mainChain, remainingBs);

//	 ソートされた要素を元のlistにコピー
	lst = mainChain;
}

// ペアをソートし、mainChainにa要素を追加
void pairSortVec(std::vector<std::pair<long, long> > &pairs, std::vector<long> &mainChain) {
	for (size_t i = 0; i < pairs.size(); ++i) {
		if (pairs[i].first > pairs[i].second)
			std::swap(pairs[i].first, pairs[i].second);
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


// Jacobsthal数列を生成する関数
std::vector<int> generateJacobsthalSequence(int n) {
	std::vector<int> jacobsthal;
	jacobsthal.push_back(0); // 初期値 Jacobsthal(1) = 0
	jacobsthal.push_back(1); // 初期値 Jacobsthal(2) = 1
	int i = 2;
	while (true) {
		int next = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
		if (next >= n) break;
		jacobsthal.push_back(next);
		++i;
	}
	return jacobsthal;
}


// 二分探索で挿入位置を探す　（Vector用）
size_t binarySearchInsertPosition (const std::vector<long>& mainChain, long value) {
	return std::lower_bound(mainChain.begin(), mainChain.end(), value) - mainChain.begin();
}

// 二分探索で挿入位置を探す　（List用）
std::list<long>::iterator binarySearchInsertPosition(std::list<long>& mainChain, long value) {
	std::list<long>::iterator begin = mainChain.begin();
	std::list<long>::iterator end = mainChain.end();
	std::list<long>::iterator mid;
	std::ptrdiff_t len = std::distance(begin, end);

	while (0 < len) {
		std::ptrdiff_t step = len / 2;
		mid = begin;
		// midをbeginからstep分進める
		std::advance(mid, step);
		if (*mid < value) {
			// 次の探索範囲を後半に設定
			begin = ++mid;
			// 残りの探索範囲を更新
			len -= step + 1;
		} else {
			// 次の探索範囲を前半に設定
			len = step;
		}
	}
	// beginは挿入位置（value以上の最初の要素を指す）
	return begin;
}


// (Vector用) Jacobsthal数列に基づいてremainingBsの要素を挿入する関数
void insertRemainingBsUsingJacobsthal(std::vector<long>& mainChain, const std::vector<long>& remainingBs) {
	std::vector<int> jacobsthal = generateJacobsthalSequence(remainingBs.size());
	// 大きい数から順に使用するため逆順にする
	std::reverse(jacobsthal.begin(), jacobsthal.end());

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


// (List用) Jacobsthal数列に基づいてremainingBsの要素を挿入する関数
void insertRemainingBsUsingJacobsthal(std::list<long>& mainChain, const std::list<long>& remainingBs) {
	std::vector<int> jacobsthal = generateJacobsthalSequence(remainingBs.size());
	std::reverse(jacobsthal.begin(), jacobsthal.end());

	for (size_t j = 0; j < jacobsthal.size(); ++j) {
		int index = jacobsthal[j] - 1;
		if (index < static_cast<int>(remainingBs.size())) {
			std::list<long>::const_iterator it = remainingBs.begin();
			std::advance(it, index);
			long value = *it;
			std::list<long>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), value);
			mainChain.insert(pos, value);
		}
	}

	for (std::list<long>::const_iterator it = remainingBs.begin(); it != remainingBs.end(); ++it) {
		int i = std::distance(remainingBs.begin(), it);
		if (std::find(jacobsthal.begin(), jacobsthal.end(), i + 1) == jacobsthal.end()) {
			long value = *it;
			std::list<long>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), value);
			mainChain.insert(pos, value);
		}
	}
}
