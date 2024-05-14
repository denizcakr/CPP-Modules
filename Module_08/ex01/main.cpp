
#include "Span.hpp"

int main()
{
	try
    {
    Span sp = Span(6);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
		std::vector<int> vec;
		Span data(10000);
		for (size_t i = 0; i < 10000; i++)
			vec.push_back(i);
		data.addMore(vec);
		std::cout << data.shortestSpan() << std::endl;
		std::cout << data.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

    return 0;
}