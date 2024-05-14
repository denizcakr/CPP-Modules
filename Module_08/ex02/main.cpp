
#include "MutantStack.hpp"
#include "MutantStack.tpp"

int main()
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;

    mstack.pop();
    
    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::stack<int> s(mstack);

    s.size();
    mstack.size();
    std::list<int> data;
    data.push_back(5);
    data.push_back(17);

    std::cout << data.back() << std::endl;

    data.pop_back();
    
    std::cout << data.size() << std::endl;

    data.push_back(3);
    data.push_back(5);
    data.push_back(737);
    //[...]
    data.push_back(0);

    std::list<int>::iterator it1 = data.begin();
    std::list<int>::iterator ite2 = data.end();

    ++it1;
    --it1;
    while (it1 != ite2)
    {
        std::cout << *it1 << std::endl;
        ++it1;
    }
    return 0;
}