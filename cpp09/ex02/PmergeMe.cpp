#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
	this->unpairedNumberDeq_ = -1;
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
	PmergeMe::sortDeque();
}


void PmergeMe::populateContainers(int argc, char **argv) {
	std::set<int>	numbers;

	for (int i = 1; i < argc; i++) {
		int length = std::strlen(argv[i]);
		for (int j = 0; j < length; j++) {
			if (!isdigit(argv[i][j]) && argv[i][j] != '+')
				throw std::invalid_argument("Error: Invalid argument.");
		}

		int	num = atoi(argv[i]);
		if (num < 0)
			throw std::runtime_error("Error: Negative Numbers are invalid");
		if (!numbers.insert(num).second)
			throw std::runtime_error("Error: Duplicate number detected.");
		input_.push_back(num);
		input_Deq_.push_back(num);
	}
}

void	PmergeMe::printUnsortedSequence(int argc) {
	std::cout << YELLOW << "Before: " << STOP;
	for(int i = 0; i < (argc - 1) ; i++) {
		std::cout << input_[i] << " ";
		if (i == 4) {
			std::cout << "[...]";
			break;
		}
	}
	std::cout << std::endl;
}

int PmergeMe::jacobsthal( int nbr ) {
	if (nbr == 0)
		return (0);
	if (nbr == 1)
		return (1);

	int prev1 = 0;
	int prev2 = 1;
	int current = 0;

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
	PmergeMe::jacobsthalInsertSequence(jacobSeqVector_, pendVector_.size());
	size_t lastPos = 1;
	size_t val = 1;
	for (size_t i = 0; i < jacobSeqVector_.size(); i++) {
		val = jacobSeqVector_.at(i);
		posVec_.push_back(val);

		size_t pos = val - 1;
		while (pos > lastPos) {
			posVec_.push_back(pos);
			pos--;
		}
		lastPos = val;
	}

	while (val++ < pendVector_.size())
		posVec_.push_back(val);
}

void PmergeMe::insertNumbersVector() {
	std::vector<int>::iterator	it;
	size_t	addCount = 0;

	PmergeMe::positionsVector();
	for (it = posVec_.begin(); it < posVec_.end(); it++) {
		int nbr = pendVector_.at(*it - 1);
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
	if (start >= end)
		return;

	int mid = (start + end) / 2;

	PmergeMe::mergeSort(vector, start, mid);
	PmergeMe::mergeSort(vector, mid + 1, end);

	std::vector<int> sorted;

	int left = start;
	int right = mid + 1;

	while (left <= mid && right <= end) {
		if (vector[left] <= vector[right]) {
			sorted.push_back(vector[left]);
			left++;
		} else {
			sorted.push_back(vector[right]);
			right++;
		}
	}
	while (left <= mid) {
		sorted.push_back(vector[left]);
		left++;
	}
	while (right <= end) {
		sorted.push_back(vector[right]);
		right++;
	}
	for (int i = start; i <= end; i++)
		vector[i] = sorted[i - start];
}


void	PmergeMe::sortVector() {
	clock_t start = clock();
	size_t	size = input_.size();

	if (size % 2 == 1) {
		unpairedNumberVec_ = input_.back();
		input_.pop_back();
	}

	for (size_t i = 0; i < size - 1; i += 2)
		pairVec_.push_back(std::make_pair(input_[i], input_[i + 1]));

	for (size_t i = 0; i < pairVec_.size(); i++) {
		if (pairVec_[i].first < pairVec_[i].second){
			std::swap(pairVec_[i].first, pairVec_[i].second);
		}
		mainVector_.push_back(pairVec_[i].first);
		pendVector_.push_back(pairVec_[i].second);
	}
	PmergeMe::mergeSort(mainVector_, 0, mainVector_.size() - 1);
	mainVector_.insert(mainVector_.begin(), pendVector_[0]);
	PmergeMe::insertNumbersVector();
	PmergeMe::displaySortInfo(start, mainVector_);
}


void PmergeMe::positionsDeque() {
	if (pendDeque_.empty())
		return;

	PmergeMe::jacobsthalInsertSequence(jacobSeqDeq_, pendDeque_.size());
	size_t lastPos = 1;
	size_t val = 1;
	while (!jacobSeqDeq_.empty()) {
		val = jacobSeqDeq_.front();

		jacobSeqDeq_.pop_front();
		posDeq_.push_back(val);

		size_t pos = val - 1;
		while (pos > lastPos) {
			posDeq_.push_back(pos);
			pos--;
		}
		lastPos = val;
	}
	while (val++ < pendDeque_.size())
		posDeq_.push_back(val);
}


void PmergeMe::insertNumbersDeque() {
	std::deque<int>::iterator it;
	size_t addCount = 0;

	PmergeMe::positionsDeque();
	for (it = posDeq_.begin(); it < posDeq_.end(); it++) {
		int n = pendDeque_.at(*it - 1);

		size_t endPos = *it + addCount;
		size_t pos = PmergeMe::binarySearch(mainDeq_, n, 0, endPos);
		mainDeq_.insert(mainDeq_.begin() + pos, n);
		addCount++;
	}
	if (unpairedNumberDeq_ != -1) {
		size_t nbr = unpairedNumberDeq_;
		size_t pos = PmergeMe::binarySearch(mainDeq_, nbr, 0, mainDeq_.size() - 1);
		mainDeq_.insert(mainDeq_.begin() + pos, nbr);
	}
}


void PmergeMe::mergeSort(std::deque<int>& deq, int start, int end) {
	if (start >= end)
		return ;

	int mid = (start + end) / 2;

	mergeSort(deq, start, mid);
	mergeSort(deq, mid + 1, end);

	std::vector<int> sorted;

	int left = start;
	int right = mid + 1;

	while (left <= mid && right <= end)	{
		if (deq[left] <= deq[right]) {
			sorted.push_back(deq[left]);
			left++;
		} else {
			sorted.push_back(deq[right]);
			right++;
		}
	}
	while (left <= mid)	{
		sorted.push_back(deq[left]);
		left++;
	}
	while (right <= end) {
		sorted.push_back(deq[right]);
		right++;
	}
	for (int i = start; i <= end; i++) {
		deq[i] = sorted[i - start];
	}
}


void	PmergeMe::sortDeque() {
	clock_t start = clock();
	size_t	size = input_Deq_.size();

	if (size % 2 == 1) {
		unpairedNumberDeq_ = input_Deq_.back();
		input_Deq_.pop_back();
	}
	for (size_t i = 0; i < size - 1; i += 2) {
		pairDeq_.push_back(std::make_pair(input_Deq_[i], input_Deq_[i + 1]));
	}
	for (size_t i = 0; i < pairDeq_.size(); i++) {
		if (pairDeq_[i].first < pairDeq_[i].second)
			std::swap(pairDeq_[i].first, pairDeq_[i].second);
		mainDeq_.push_back(pairDeq_[i].first);
		pendDeque_.push_back(pairDeq_[i].second);
	}

	mergeSort(mainDeq_, 0, mainDeq_.size() - 1);
	mainDeq_.push_front(pendDeque_[0]);

	insertNumbersDeque();

	displaySortInfo(start, mainDeq_);
}
