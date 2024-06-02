#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream> // std::cout, std::endl
#include <sstream> // std::istringstream
#include <list> // std::list
#include <vector> // std::vector
#include <algorithm> // std::lower_bound
#include <stdexcept> // std::invalid_argument
#include <sys/time.h> // gettimeofday
#include <utility> // std::pair
#include <cmath>
#include "Color.hpp"

// CommandLineParserクラスの宣言
class CommandLineParser {
public:
	CommandLineParser();
	CommandLineParser(const int argc, const char *argv[]);
	CommandLineParser(const CommandLineParser &parser);
	CommandLineParser &operator=(const CommandLineParser &parser);
	~CommandLineParser();

	const std::vector<long> &getVector() const;
	const std::list<long> &getList() const;

private:
	std::vector<long> numVec_;
	std::list<long> numList_;

	void parseArgument(const int argc, const char *argv[]);
};

// MergeInsertionSortテンプレートクラスの宣言と定義
template <typename Container>
class MergeInsertionSort {
public:
	MergeInsertionSort() {};
	MergeInsertionSort(const MergeInsertionSort &sort) {
		*this = sort;
	};
	MergeInsertionSort &operator=(const MergeInsertionSort &sort) {
		if (this != &sort) {}
		return (*this);
	};
	virtual ~MergeInsertionSort() {};

	void displayInput(const Container &container) const {
		displayContainer("before:\t", container);
	};

	void displayOutput(const Container &container) const {
		displayContainer("after:\t", container);
	};

	long sortAndMeasure(Container &container) {
		struct timeval start, end;

		gettimeofday(&start, NULL);
		sort(container);
		gettimeofday(&end, NULL);

		long second = end.tv_sec - start.tv_sec;
		long micro = (second * 1000000) + (end.tv_usec - start.tv_usec);
		return (micro);
	};

	void displayTime(Container &container, std::string str, long time) {
		std::cout << "Time to process a range of " << container.size()
				  << " elements with " << str << " : " << time << " us"
				  << std::endl;
	};

protected:
	virtual void sort(Container &container) = 0;

	typename Container::iterator binarySearchInsertPosition(Container &container, long num) {
		return std::lower_bound(container.begin(), container.end(), num);
	}

private:
	void displayContainer(const std::string &prefix, const Container &container) const {
		std::cout << prefix;
		if (container.size() <= 5) {
			for (typename Container::const_iterator it = container.begin();
				 it != container.end(); it++) {
				std::cout << *it << ' ';
			}
			std::cout << std::endl;
		} else {
			typename Container::const_iterator it = container.begin();
			for (std::size_t i = 0; i < 4 && it != container.end(); i++, it++) {
				std::cout << *it << ' ';
			}
			std::cout << "[...]" << std::endl;
		}
	};
};

// VectorMergeInsertionSortクラスの宣言
class VectorMergeInsertionSort : public MergeInsertionSort<std::vector<long> > {
public:
	VectorMergeInsertionSort();
	VectorMergeInsertionSort(const VectorMergeInsertionSort &sort);
	VectorMergeInsertionSort &operator=(const VectorMergeInsertionSort &sort);
	~VectorMergeInsertionSort();

	void sort(std::vector<long> &container);

private:
	void mergeInsertVec(std::vector<long> &mainChain, std::vector<long> &bs, const std::vector<long> &order);
};

// ListMergeInsertionSortクラスの宣言
class ListMergeInsertionSort : public MergeInsertionSort<std::list<long> > {
public:
	ListMergeInsertionSort();
	ListMergeInsertionSort(const ListMergeInsertionSort &sort);
	ListMergeInsertionSort &operator=(const ListMergeInsertionSort &sort);
	~ListMergeInsertionSort();

	void sort(std::list<long> &container);

private:
	void mergeInsertList(std::list<long> &mainChain, std::list<long> &bs, const std::vector<long> &order);
};

// ヘルパー関数の宣言
void pairSortVec(std::vector<std::pair<long, long> > &pairs, std::vector<long> &mainChain);
void pairSortList(std::list<std::pair<long, long> > &pairs, std::list<long> &mainChain);

void vecInsertionOrder(std::vector<long> &order, int n);
void listInsertionOrder(std::vector<long> &order, int n);

#endif
