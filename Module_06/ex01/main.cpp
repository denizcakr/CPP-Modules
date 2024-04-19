
#include "Serializer.hpp"

int main()
{
    Data *d = new Data;
    d->f = 42;

    std::cout << d << std::endl;

    uintptr_t rawPtr = Serializer::serialize(d);

    std::cout << rawPtr << std::endl;

    Data *tmp = NULL;

    tmp = Serializer::deserialize(rawPtr);

    std::cout << tmp << std::endl;
    std::cout << tmp->f << std::endl;

    delete d;
}