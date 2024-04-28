
#include "iter.hpp"

int main()
{
	int intArray[] = {1,2,3};
	size_t intArrayLength = sizeof(intArray) / sizeof(intArray[0]);
	std::cout << "int array elements are: " << std::endl;
	iter(intArray, intArrayLength, printElements<int>);
	
	std::string strArray[] = {"pen", "pineapple", "apple"};
	size_t strArrayLength = sizeof(strArray) / sizeof(strArray[0]);
	std::cout << "string array elements are: " << std::endl;
	iter(strArray, strArrayLength, printElements<std::string>);

	return 0;
}
