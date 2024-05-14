
#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <string>

class Span
{
    private:
        unsigned int maxSize;
        std::vector<int> intTmp;

        public:
            Span();
            ~Span();
            Span(const Span &);
            Span &operator=(const Span &);
            
            Span(unsigned int N);

            void addNumber(long n);

            int shortestSpan() const;
            int longestSpan() const;

            void addMore(std::vector<int> tmp);
            void printNumbers();
            
};
#endif