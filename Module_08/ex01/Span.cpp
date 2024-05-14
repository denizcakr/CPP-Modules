
#include "Span.hpp"

Span::Span() : maxSize(0) {
}

Span::Span(unsigned int N) : maxSize(N) {
}

Span::~Span() {
}

Span::Span(const Span &data)
{
    *this = data;
}

Span &Span::operator=(const Span &data)
{
    intTmp = data.intTmp;
    maxSize = data.maxSize;
    return *this;
}

void Span::addNumber(long n)
{
    if (intTmp.size() >= maxSize)
        throw std::out_of_range("Maximum capacity reached.");
    if (INT_MIN > n  || INT_MAX < n)
        throw std::out_of_range("Out of integer.");
    else
        intTmp.push_back(n);   
}

int Span::shortestSpan() const
{
    if(intTmp.empty() || intTmp.size() == 1)
        throw std::logic_error("vector is empty or has only one element.");
    else
    {
        std::vector<int> tmp = intTmp;
        std::sort(tmp.begin(), tmp.end());
        int min = tmp[1] - tmp[0];
        for(unsigned int i = 1; i < tmp.size() ; i++)
        {
            int span = tmp[i] - tmp[i - 1];
            if(span < min)
                min = span;
        }
    return min;
    }
}

int Span::longestSpan() const
{
    if(intTmp.empty() || intTmp.size() == 1)
        throw std::logic_error("vector is empty or has only one element.");
    else
    {
        long max = *std::max_element(intTmp.begin(), intTmp.end());
        long min = *std::min_element(intTmp.begin(), intTmp.end());
        
        return (max - min);
    }
}

void Span::printNumbers(){
    for (std::vector<int>::iterator it = intTmp.begin();it != intTmp.end();it++)
        std::cout << *it << std::endl;
}

void Span::addMore(std::vector<int> tmp) {
    intTmp.insert(intTmp.end(), tmp.begin(), tmp.end());
}