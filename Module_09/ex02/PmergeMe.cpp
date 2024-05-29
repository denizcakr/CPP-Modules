#include "PmergeMe.hpp"
#include <ctime>
PmergeMe::PmergeMe() {
}

PmergeMe::~PmergeMe() {
}

PmergeMe::PmergeMe(const PmergeMe &data)
{
    *this = data;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	this->vec = other.vec;
	return (*this);
}

int PmergeMe::argumentsControl(char  **av, int ac)
{
	if (av[1] == NULL)
	{
		std::cout << "No arguments" << std::endl;
		return (0);
	}
	for (int i = 1; i < ac; i++)
	{
		int x;
		int y = stringToInt(av[i], x);
		if (!y || x <= 0)
		{
			std::cout << "Error" << std::endl;
			return (0);
		}
	}
	return (1);
}

void PmergeMe::printTime(clock_t start, clock_t end, std::string type, size_t size)
{
	double time_taken = double(end - start) / 1000000.0;
	std::cout << "Time to process a range of " << size << " elements with " << type << " : " << std::fixed << time_taken << " us" << std::endl;
}

void PmergeMe::printBeforeAndAfter(size_t k, std::vector<int> &vec, std::string data)
{
	if (data == "before")
	{
		std::cout << "Before: ";
		for(size_t i = 0; i < k; i++)
		{
			if (i == 4 && k > 5)
			{
				std::cout << " [...]";
				break;
			}
			std::cout << vec[i] << " ";
		}
		std::cout << std::endl;
	}
	else
	{
		std::cout << "After:  ";
		for(size_t i = 0; i < k; i++)
		{
			if (i == 4 && k > 5)
			{
				std::cout << " [...]";
				break;
			}
			std::cout << vec[i] << " ";
		}
		std::cout << std::endl;
	}
}

int PmergeMe::stringToInt(std::string str, int &num)
{
    std::istringstream iss(str);
	if (str.find(' ', 0) == std::string::npos)
		return iss >> num ? 1 : 0;
	return(0);
}

void PmergeMe::operation(char **av, int ac)
{
  	clock_t start, end;
	int vecNum, deqNum;
	for (size_t i = 1; av[i]; i++)
	{
		if (stringToInt(av[i], vecNum))
			vec.push_back(vecNum);
		else
		{
			std::cout << "Error" << std::endl;
			return;
		}
	}
	printBeforeAndAfter(ac - 1, vec, "before");
    start = clock();
	mergeSort(vec);
	end = clock();
	printBeforeAndAfter(ac - 1, vec, "after");
	printTime(start, end, "std::vector", ac - 1);
	for(size_t i = 1; av[i]; i++)
	{
		if (stringToInt(av[i], deqNum))
			deq.push_back(deqNum);
		else
		{
			std::cout << "Error" << std::endl;
			return;
		}
	}
    start = clock();
	mergeSort(deq);
	end = clock();
	printTime(start, end, "std::deque", ac - 1);
}

template <typename T>
void PmergeMe::insertSort(T &c)
{
	if (c.size() == 2)
	{
		int swap;
		if (c[0] > c[1])
		{
			swap = c[1];
			c[1] = c[0];
			c[0] = swap;
		}
	}
	else
		return ;

}
template <typename T>
void PmergeMe::merge(T &c, T &left, T &right)
{
	size_t i = 0;
	size_t j = 0;
	size_t k = 0;

	while (i < left.size() && j < right.size())
	{
		if (left[i] < right[j])
		{
			c[k] = left[i];
			i++;
		}
		else
		{
			c[k] = right[j];
			j++;
		}
		k++;
	}
	
	while (i < left.size())
	{
		c[k] = left[i];
		i++;
		k++;
	}
	while (j < right.size())
	{
		c[k] = right[j];
		j++;
		k++;
	}
}


template <typename T>
void PmergeMe::mergeSort(T &c)
{
	size_t l = c.size() / 2;

	if (c.size() <= 2)
	{
		insertSort(c);
		return;
	}
	T left;
    T right;
	for(size_t i = 0; i < l; i++)
		left.push_back(c[i]);
	for(size_t i = l; i < c.size(); i++)
		right.push_back(c[i]);

	mergeSort(left);
	mergeSort(right);
	merge(c, left, right);
}