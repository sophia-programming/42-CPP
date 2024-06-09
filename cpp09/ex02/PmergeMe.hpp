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
	int		unpairedNumberVec_;
	int		unpairedNumberDeq_;

	std::vector<int>	input_;
	std::vector<int>	mainVector_;
	std::vector<int>	pendVector_;
	std::vector<int>	jacobSeqVector_;
	std::vector<int>	posVec_;

	std::vector<std::pair<int, int> >	pairVec_;

	std::deque<int>		input_Deq_;
	std::deque<int>		mainDeq_;
	std::deque<int>		pendDeque_;
	std::deque<int>		jacobSeqDeq_;
	std::deque<int>		posDeq_;

	std::deque<std::pair<int, int> >	pairDeq_;

	void	populateContainers(int, char **);

	void	printUnsortedSequence(int);
	int		jacobsthal(int n);

	void	sortVector();
	void	mergeSort(std::vector<int>& S, int start, int end);
	void 	insertNumbersVector();
	void	positionsVector();

	void	sortDeque();
	void	mergeSort(std::deque<int>& S, int start, int end);
	void	insertNumbersDeque();
	void	positionsDeque();

public:
	PmergeMe();
	PmergeMe(PmergeMe const&);
	~PmergeMe();

	PmergeMe& operator=(const PmergeMe &);

	void merge(int, char **);

	template<typename T>
	void	printSequence(const T&);

	template<typename T>
	void displaySortInfo(clock_t, const T&);

	template<typename T>
	void jacobsthalInsertSequence(T&, size_t );

	template<typename T>
	int binarySearch(T& deq, int nbr, int begin, int end);
};

#endif
