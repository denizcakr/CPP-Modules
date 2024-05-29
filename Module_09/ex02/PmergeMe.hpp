#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <string>
class PmergeMe {

	private:
		std::vector<int> vec;
		std::deque<int> deq;
		std::string type;
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &);
		PmergeMe &operator=(const PmergeMe &);
		~PmergeMe();
		int argumentsControl(char **av, int ac);
		void operation(char **av, int ac);
		template <typename T> 
		void mergeSort(T &);
		template <typename T> 
		void insertSort(T &);
		template <typename T> 
		void merge(T &, T &, T &);
		template <typename T>
		void ultimateMergeSort(T &, size_t l);
		void printTime(clock_t start, clock_t end, std::string type, size_t size);
		void printBeforeAndAfter(size_t k, std::vector<int> &vec, std::string data);
		int stringToInt(std::string str, int &num);

};

#endif