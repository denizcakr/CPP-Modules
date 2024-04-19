
#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
}

ScalarConverter::~ScalarConverter() {
}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
	(void)other;
	return *this;
}


int nanControl(std::string data)
{
	if(data == "-inff" || data == "+inff" || data == "nanf")
	{
		float f = atof(data.c_str());
		
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << static_cast<float>(f) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(f) << std::endl;
		return 1;
	}

	if(data == "-inf" || data == "+inf" || data == "nan")
	{
		double d = atof(data.c_str());

		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(d) << std::endl;
		return 1;
	}
	return 0;
}

int caseControl(std::string data)
{
	if (nanControl(data) || isalpha(data[1]) || data[1] == '-' || data[1] == '+' || data == "")
		return 1;
	else if(data[1] == 32 || data[1] == '\t')
		return 1;
	return 0;	
}

void charConvert(std::string &data)
{
	char c;
	int i;
	float f;
	double d;
	
	c = data[0];

	i = static_cast<int>(c);
	f = static_cast<float>(c);
	d = static_cast<double>(c);

	std::cout << "char: " << "'" << c << "'" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << ".0f" << std::endl;
	std::cout << "double: " << d << ".0" << std::endl;  
}

void intConvert(std::string &data)
{
	char c;
	long lng;
	int i;
	float f;
	double d;

	lng = atol(data.c_str());
	i = atoi(data.c_str());
	c = static_cast<char>(i);
	f = static_cast<float>(i);
	d = static_cast<double>(i);

	if(lng > CHAR_MAX || lng < CHAR_MIN)
		std::cout << "char: impossible" << std::endl;
	else if(!isprint(c))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << "'" << c << "'" << std::endl;

	if(lng > INT_MAX || lng < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;

    std::cout << "float: " << static_cast<float>(atol(data.c_str())) <<  ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(atol(data.c_str()))<< ".0" <<std::endl;
}

void floatConvert(std::string &data)
{
	char c;
	int i;
	float f;
	double d;
	long double ld;
	char *endptr;
	
	int iorf = data.find('.', 0);

	std::string value = data.substr(iorf + 1, data.size());
	std::string newData = data.substr(0, data.size() - 1);
	ld = strtold(newData.c_str(), &endptr);
	f = atof(data.c_str());

	if(*endptr != '\0')
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return ;
	}

	c = static_cast<char>(f);
	i = static_cast<int>(f);
	d = static_cast<double>(f);

	if((ld > 0 && ld < 1) || (ld > CHAR_MAX || ld < CHAR_MIN))
		std::cout << "char: impossible" << std::endl;
	else if(!isprint(c))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << "'" << c << "'" << std::endl;
	
	if(ld > INT_MAX || ld < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
	
	if(ld > std::numeric_limits<float>::max() || ld < std::numeric_limits<float>::min())
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << f << ".0f" << std::endl;

	if(ld > std::numeric_limits<double>::max() || ld < std::numeric_limits<double>::min())
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << d << ".0" << std::endl;
}

void doubleConvert(std::string &data)
{
	char c;
	int i;
	float f;
	double d;
	long double ld;
	char *endptr;

	int iorf = data.find('.', 0);

	std::string value = data.substr(iorf + 1, data.size());
	std::string newData = data.substr(0, data.size() - 1);
	ld = strtold(newData.c_str(), &endptr);
	d = atof(data.c_str());

	if(*endptr != '\0')
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return ;
	}

	c = static_cast<char>(d);
	i = static_cast<int>(d);
	f = static_cast<float>(d);

	if((ld > 0 && ld < 1) || (ld > CHAR_MAX || ld < CHAR_MIN))
		std::cout << "char: impossible" << std::endl;
	else if(!isprint(c))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << "'" << c << "'" << std::endl;

	if(ld > INT_MAX || ld < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
	
	if(ld > std::numeric_limits<float>::max() || ld < std::numeric_limits<float>::min())
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << f << ".0f" << std::endl;
	
	if(ld > std::numeric_limits<double>::max() || ld < std::numeric_limits<double>::min())
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << d << ".0" << std::endl;
}

void ScalarConverter::convert(std::string data)
{
	if(caseControl(data))
		return ;
	if(data.size() == 1 && !isdigit(data[0]))
		charConvert(data);
	else if(data.find('.', 0) == std::string::npos)
		intConvert(data);
	else if(data.find('f', 0) != std::string::npos || data.find('F', 0) != std::string::npos)
		floatConvert(data);
	else if(data.find('.', 0) != std::string::npos)
		doubleConvert(data);
}