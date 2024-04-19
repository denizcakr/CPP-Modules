
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


void typePrinter(const std::string &data)
{
	std::cout << data << std::endl;
}

Base* generate(void)
{
	Base *tmp = NULL;
	srand(time(0));
	size_t data = rand();

	if(data % 2 == 0)
		tmp = new A;
	else if(data % 3 == 0)
		tmp = new B;
	else
		tmp = new C;
	return tmp;
}

void identify(Base* p)
{
	if(dynamic_cast<A*>(p))
		typePrinter("Actual type is*: A");
	else if(dynamic_cast<B*>(p))
		typePrinter("Actual type is*: B");
	else if(dynamic_cast<C*>(p))
		typePrinter("Actual type is*: C");
}

void identify(Base& p)
{
	A a;
	B b;
	C c;

	try
	{
		a = dynamic_cast<A&>(p);
		typePrinter("Actual type is&: A");
	}
	catch(std::exception& e)
	{
		typePrinter(e.what());
	}

	try
	{
		b = dynamic_cast<B&>(p);
		typePrinter("Actual type is&: B");
	}
	catch(std::exception& e)
	{
		typePrinter(e.what());
	}

	try
	{
		c = dynamic_cast<C&>(p);
		typePrinter("Actual type is&: C");
	}
	catch(std::exception& e)
	{
		typePrinter(e.what());
	}
	
}

int main()
{
	Base *data = generate();

	identify(data);
	identify(*data);

	delete data;
	return 0;
}