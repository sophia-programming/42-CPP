#include "PmergeMe.hpp"
PmergeMe::PmergeMe() {
	this->unpairedNumberList_ = -1;
	this->unpairedNumberVec_ = -1;
}

PmergeMe::PmergeMe(const PmergeMe &obj) {
	*this = obj;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &to_copy) {
	if (this != &to_copy) {
	}
	return (*this);
}

PmergeMe::~PmergeMe(){}

void PmergeMe::merge(int argc, char **argv) {
	PmergeMe::populateContainers(argc, argv);
	PmergeMe::printUnsortedSequence(argc);
	PmergeMe::sortVector();
	PmergeMe::sortList();
}

void PmergeMe::populateContainers(int argc, char **argv) {
	for (int i = 1; i < argc; i++) {
		int length = std::strlen(argv[i]);
		for (int j = 0; j < length; j++) {
			if (!isdigit(argv[i][j]) && argv[i][j] != '+')
				throw std::invalid_argument("Error: Invalid argument.");
		}

		int num = std::atoi(argv[i]);
		if (num < 0)
			throw std::runtime_error("Error: Negative Numbers are invalid");
		input_Vector_.push_back(num);
		input_List_.push_back(num);
	}
}

void PmergeMe::printUnsortedSequence(int argc) {
	std::cout << YELLOW << "Before: " << STOP;
	for (int i = 0; i < (argc - 1); i++) {
		std::cout << input_Vector_[i] << " ";
		if (i == 5) {
			std::cout << "[...]";
			break;
		}
	}
	std::cout << std::endl;
}

int PmergeMe::jacobsthal(int nbr) {
	if (nbr == 0)
		return 0;
	if (nbr == 1)
		return 1;

	int prev1 = 0; // Jacobsthal(0) nbr == 0の場合
	int prev2 = 1; // Jacobsthal(1) nbr == 1の場合
	int current = 0; // 計算中のJacobsthal数

	for (int i = 2; i <= nbr; ++i) {
		current = prev1 + 2 * prev2;
		prev1 = prev2;
		prev2 = current;
	}
	return current;
}

void PmergeMe::positionsVector() {
	if (this->pendVector_.empty())
		return;

	// Jacobsthal数列を使って挿入位置を計算
	PmergeMe::jacobsthalInsertSequence(jacobSeqVector_, pendVector_.size());

	size_t lastPos = 0;
	size_t currentPos = 1;

	// Jacobsthal数列に基づいて挿入位置を決定
	for (size_t i = 0; i < jacobSeqVector_.size(); i++) {
		currentPos = jacobSeqVector_[i];
		sortedVec_.push_back(currentPos);

		size_t pos = currentPos - 1;
		while (lastPos < pos) {
			sortedVec_.push_back(pos);
			pos--;
		}
		lastPos = currentPos;
	}
	// Jacobsthal数列の範囲外の値を追加
	while (currentPos++ < pendVector_.size())
		sortedVec_.push_back(currentPos);
}

void PmergeMe::insertNumbersVector() {
	std::vector<int>::iterator it;
	size_t addCount = 0;

	PmergeMe::positionsVector();
	for (it = sortedVec_.begin(); it < sortedVec_.end(); it++) {
		int nbr = pendVector_[*it - 1];
		size_t endPos = *it + addCount;
		size_t pos = PmergeMe::binarySearch(mainVector_, nbr, 0, endPos);
		mainVector_.insert(mainVector_.begin() + pos, nbr);
		addCount++;
	}
	if (unpairedNumberVec_ != -1) {
		size_t nbr = unpairedNumberVec_;
		size_t pos = PmergeMe::binarySearch(mainVector_, nbr, 0, mainVector_.size() - 1);
		mainVector_.insert(mainVector_.begin() + pos, nbr);
	}
}

void PmergeMe::mergeSort(std::vector<int>& vector, int start, int end) {
	// 配列の要素が1つの場合は何もしない
	if (end <= start)
		return;

	// 中間点の計算
	int mid = (start + end) / 2;

	// 左側の配列を再帰的にソート
	PmergeMe::mergeSort(vector, start, mid);
	// 右側の配列を再帰的にソート
	PmergeMe::mergeSort(vector, mid + 1, end);

	// 2つの配列をマージ
	std::vector<int> sorted;

	int left = start;
	int right = mid + 1;

	// 左右の部分配列をマージ
	while (left <= mid && right <= end) {
		if (vector[left] <= vector[right]) {
			sorted.push_back(vector[left]);
			left++;
		} else {
			sorted.push_back(vector[right]);
			right++;
		}
	}

	// 左側の残りを追加
	while (left <= mid) {
		sorted.push_back(vector[left]);
		left++;
	}

	// 右側の残りを追加
	while (right <= end) {
		sorted.push_back(vector[right]);
		right++;
	}

	// マージ結果を元の配列にコピー
	for (int i = start; i <= end; i++)
		vector[i] = sorted[i - start];
}

void PmergeMe::sortVector() {
	clock_t start = clock();
	size_t size = input_Vector_.size();

	// ベクターの要素数が奇数の場合は、最後の要素を取り出し、unpairedNumberVec_に格納
	if (size % 2 == 1) {
		unpairedNumberVec_ = input_Vector_.back();
		input_Vector_.pop_back();
	}

	// ペアを作成してpairVec_に格納
	for (size_t i = 0; i < size - 1; i += 2)
		pairVec_.push_back(std::make_pair(input_Vector_[i], input_Vector_[i + 1]));

	for (size_t i = 0; i < pairVec_.size(); i++) {
		if (pairVec_[i].first < pairVec_[i].second) {
			std::swap(pairVec_[i].first, pairVec_[i].second);
		}
		// 大きい方の値をmainVector_に追加
		mainVector_.push_back(pairVec_[i].first);
		// 小さい方の値をpendVector_に追加
		pendVector_.push_back(pairVec_[i].second);
	}

	// mainVector_をマージソート
	PmergeMe::mergeSort(mainVector_, 0, mainVector_.size() - 1);

	// pendVector_の最初の要素をmainVector_の先頭に挿入
	mainVector_.insert(mainVector_.begin(), pendVector_[0]);

	// 残りのpendVector_の要素をmainVector_に挿入
	PmergeMe::insertNumbersVector();

	// ソート結果を表示
	PmergeMe::displaySortInfo(start, mainVector_);
}

void PmergeMe::positionsList() {
	if (pendList_.empty())
		return;

	PmergeMe::jacobsthalInsertSequence(jacobSeqList_, pendList_.size());
	size_t lastPos = 0;
	size_t currentPos = 1;
	while (!jacobSeqList_.empty()) {
		currentPos = jacobSeqList_.front();

		jacobSeqList_.pop_front();
		posList_.push_back(currentPos);

		size_t pos = currentPos - 1;
		while (pos > lastPos) {
			posList_.push_back(pos);
			pos--;
		}
		lastPos = currentPos;
	}
	while (currentPos++ < pendList_.size())
		posList_.push_back(currentPos);
}

void PmergeMe::insertNumbersList() {
	std::list<int>::iterator it;
	size_t addCount = 0;

	PmergeMe::positionsList();
	for (it = posList_.begin(); it != posList_.end(); ++it) {
		std::list<int>::iterator pendIt = pendList_.begin();
		std::advance(pendIt, *it - 1);
		int n = *pendIt;

		std::list<int>::iterator mainIt = mainList_.begin();
		std::advance(mainIt, *it + addCount);
		size_t pos = PmergeMe::binarySearch(mainList_, n, 0, *it + addCount);
		mainIt = mainList_.begin();
		std::advance(mainIt, pos);
		mainList_.insert(mainIt, n);
		addCount++;
	}
	if (unpairedNumberList_ != -1) {
		int nbr = unpairedNumberList_;
		size_t pos = PmergeMe::binarySearch(mainList_, nbr, 0, mainList_.size() - 1);
		std::list<int>::iterator mainIt = mainList_.begin();
		std::advance(mainIt, pos);
		mainList_.insert(mainIt, nbr);
	}
}

void PmergeMe::mergeSort(std::list<int>& list, int start, int end) {
	if (start >= end)
		return;

	int mid = (start + end) / 2;

	mergeSort(list, start, mid);
	mergeSort(list, mid + 1, end);

	std::vector<int> sorted;

	int left = start;
	int right = mid + 1;

	std::list<int>::iterator it = list.begin();
	std::advance(it, start);
	std::list<int>::iterator leftIt = it;
	std::advance(it, mid - start + 1);
	std::list<int>::iterator rightIt = it;

	while (left <= mid && right <= end) {
		if (*leftIt <= *rightIt) {
			sorted.push_back(*leftIt);
			leftIt++;
			left++;
		} else {
			sorted.push_back(*rightIt);
			rightIt++;
			right++;
		}
	}
	while (left <= mid) {
		sorted.push_back(*leftIt);
		leftIt++;
		left++;
	}
	while (right <= end) {
		sorted.push_back(*rightIt);
		rightIt++;
		right++;
	}
	std::list<int>::iterator insertIt = list.begin();
	std::advance(insertIt, start);
	for (unsigned int i = 0; i < sorted.size(); ++i) {
		*insertIt = sorted[i];
		std::advance(insertIt, 1);
	}
}

void PmergeMe::sortList() {
	clock_t start = clock();
	size_t size = input_List_.size();

	if (size % 2 == 1) {
		unpairedNumberList_ = input_List_.back();
		input_List_.pop_back();
	}
	for (size_t i = 0; i < size - 1; i += 2) {
		std::list<int>::iterator it = input_List_.begin();
		std::advance(it, i);
		std::list<int>::iterator next_it = it;
		std::advance(next_it, 1);
		pairList_.push_back(std::make_pair(*it, *next_it));
	}
	std::list<std::pair<int, int> >::iterator pairIt = pairList_.begin();
	while (pairIt != pairList_.end()) {
		if (pairIt->first < pairIt->second)
			std::swap(pairIt->first, pairIt->second);
		mainList_.push_back(pairIt->first);
		pendList_.push_back(pairIt->second);
		++pairIt;
	}

	mergeSort(mainList_, 0, mainList_.size() - 1);
	mainList_.push_front(pendList_.front());

	insertNumbersList();

	displaySortInfo(start, mainList_);
}
