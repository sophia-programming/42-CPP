#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream> //std::cout
#include <vector> //std::vector
#include <deque> //std::deque
#include <cstring> //std::strcmp
#include <algorithm> //std::sort
#include <set> //std::set
#include <typeinfo> //typeid
#include "Color.hpp" //Color

class PmergeMe
{
private:
	int unpairedNumberVec_;
	int unpairedNumberDeq_;

	std::vector<int> input_;
	std::vector<int> mainVector_;
	std::vector<int> pendVector_;
	std::vector<int> jacobSeqVector_;
	std::vector<int> posVec_;

	std::vector<std::pair<int, int> > pairVec_;

	std::deque<int> input_Deq_;
	std::deque<int> mainDeq_;
	std::deque<int>	pendDeque_;
	std::deque<int>	jacobSeqDeq_;
	std::deque<int>	posDeq_;

	std::deque<std::pair<int, int> > pairDeq_;

	void populateContainers(int, char **);
	void printUnsortedSequence(int);
	int	jacobsthal(int n);

	void sortVector();
	void mergeSort(std::vector<int> &S, int start, int end);
	void insertNumbersVector();
	void positionsVector();

	void sortDeque();
	void mergeSort(std::deque<int> &S, int start, int end);
	void insertNumbersDeque();
	void positionsDeque();

public:
	PmergeMe();
	PmergeMe(PmergeMe const&);
	PmergeMe &operator=(const PmergeMe &to_copy);
	~PmergeMe();

	void merge(int, char **);

	template<typename T>
	void printSequence(const T &sequence)
	{
		typename T::const_iterator it;
		size_t i =  0;
		for (it = sequence.begin(); it != sequence.end(); ++it) {
			std::cout << *it << " ";
			if (i == 4){
				std::cout << "[...]";
				break;
			}
			i++;
		}
		std::cout << std::endl;
	}

	template<typename T>
	void displaySortInfo(clock_t start, const T &mainSequence)
	{
		clock_t end = clock();
		double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;

		std::cout << YELLOW << "After:  " << STOP;
		printSequence(mainSequence);
		std::cout << "Time to process a range of " << mainSequence.size();
		std::cout << " elements with " << RED << (typeid(mainSequence) == typeid(std::vector<int>) ? "std::vector" : "std::deque") << STOP;
		std::cout << " : " << time << " ms" << std::endl;
	}

	template<typename T>
	void jacobsthalInsertSequence(T &sequence, size_t maxSize)
	{
		size_t	jacobIndex;
		int		index;

		index = 3;
		while ((jacobIndex = PmergeMe::jacobsthal(index)) < maxSize - 1)
		{
			sequence.push_back(jacobIndex);
			index++;
		}
	}

	template<typename T>
	int binarySearch(T &container, int nbr, int begin, int end)
	{
		int mid;

		while (begin <= end)
		{
			mid = begin + (end - begin) / 2;
			if (nbr == container.at(mid))
				return (mid);

			if (nbr > container.at(mid))
				begin = mid + 1;
			else
				end = mid - 1;
		}
		if (nbr > container.at(mid))
			return (mid + 1);
		else
			return (mid);
	}
};

#endif
