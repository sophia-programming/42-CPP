#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <list>
#include <sstream>
#include <sys/time.h>
#include <vector>
#include "Color.hpp"

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


template <typename Container> class MergeInsertionSort {
public:
	MergeInsertionSort(){};
	virtual ~MergeInsertionSort(){};

	void displayInput(const Container &container) const {
		displayContainer("before: ", container);
	};

	void displayOutput(const Container &container) const {
		displayContainer("after: ", container);
	};

	long sortAndMeasure(Container &container) {
		struct timeval start, end;

		gettimeofday(&start, NULL);
		sort(container);
		(void)(container);
		gettimeofday(&end, NULL);

		long second = end.tv_sec - start.tv_sec;
		long micoro = (second * 1000000) + (end.tv_usec - start.tv_usec);
		return (micoro);
	};

	void displayTime(Container &container, std::string str, long time) {
		std::cout << "Time to process a range of " << container.size()
				  << " elements with " << GREEN << str << STOP << " : " << time << " us"
				  << std::endl;
	};

	void showContainerElement(Container &container) {
		typename Container::const_iterator it = container.begin();
		for (; it != container.end(); it++) {
			std::cout << *it << std::endl;
		}
	};

	bool isEqualContainer(const Container &first, const Container &second) {
		if (first.size() != second.size()) {
			return (false);
		}

		typename Container::const_iterator itFirst = first.begin();
		typename Container::const_iterator itSecond = second.begin();
		while (itFirst != first.end()) {
			if (*itFirst != *itSecond) {
				return (false);
			}
			itFirst++;
			itSecond++;
		}
		return (true);
	}

protected:
	virtual void sort(Container &container) = 0;

	typename Container::iterator binarySearchInsertPosition(Container &container,
															long num) {
		typename Container::iterator low = container.begin();
		typename Container::iterator high = container.end();
		typename Container::iterator mid;

		while (low < high) {
			mid = low + (std::distance(low, high) / 2);
			if (num < *mid) {
				high = mid;
			} else {
				low = mid + 1;
			}
		}
		return (low);
	};

	MergeInsertionSort(const MergeInsertionSort &sort) { (void)sort; };

private:
	void displayContainer(const std::string &prefix,
						  const Container &container) const {
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

	MergeInsertionSort &operator=(const MergeInsertionSort &sort){
		(void)sort;
	};
};


class VectorMergeInsertionSort : public MergeInsertionSort<std::vector<long> > {
public:
	VectorMergeInsertionSort();
	VectorMergeInsertionSort(const VectorMergeInsertionSort &sort);
	VectorMergeInsertionSort &operator=(const VectorMergeInsertionSort &sort);
	~VectorMergeInsertionSort();

private:
	void sort(std::vector<long> &container);
};


class ListMergeInsertionSort : public MergeInsertionSort<std::list<long> > {
public:
	ListMergeInsertionSort();
	ListMergeInsertionSort(const ListMergeInsertionSort &sort);
	ListMergeInsertionSort &operator=(const ListMergeInsertionSort &sort);
	~ListMergeInsertionSort();

private:
	void sort(std::list<long> &container);
};

#endif
