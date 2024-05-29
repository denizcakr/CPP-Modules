#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
}

BitcoinExchange::~BitcoinExchange() {
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &data)
{
    *this = data;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	this->_map = other._map;
	return (*this);
}

int BitcoinExchange::readCsv()
{
	std::ifstream dataCsv("data.csv");

	if (!dataCsv)
	{
		std::cout << "File not open!" << std::endl;
		return 0;
	}

	std::string line;
	while(std::getline(dataCsv, line))
	{
		if (isdigit(line[0]))
		{
			std::string newLine = line.substr(11, line.length()); //
			_map[line.substr(0, line.find(',',0))] = atof(newLine.c_str());
		}
	}
	return 1;
}

void BitcoinExchange::operation(std::string date, double amount)
{

	for(std::map<std::string,double>::iterator it = _map.begin(); it != _map.end(); it++)
	{
		if (it->first == date)
		{
			if (amount == 1001)
				std::cout << "Error: bad input => " << date << std::endl;
			else 
				std::cout << date << " => " << amount << " = " << it->second * amount << std::endl;
			break ;
		}
		else if(it->first > date)
		{
			--it;
			if (it->first.empty())
			{
				std::cout << "Error: date not found => " << date << std::endl;
				break;
			}
			if (amount == 1001)
				std::cout << "Error: bad input => " << date  << std::endl;
			else 
				std::cout << date << " => " << amount << " = " << it->second * amount << std::endl;
			break;
		}
		if (++it == _map.end() && date > it->first)
		{
			std::cout << "Error: date not found => " << date << std::endl;
			break;
		}
		else
			--it;
	}
}

bool BitcoinExchange::isLeapYear(int year) {
    return (year % 4 == 0);
}

bool BitcoinExchange::isValidDate(int year, int month, int day) {
    if (year < 2009 || month < 1 || month > 12 || day < 1 || year > 2022)
        return false;
    if (month == 2) {
        if (isLeapYear(year)) {
            return day <= 29;
        } else {
            return day <= 28;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return day <= 30;
    } else {
        return day <= 31;
    }
}

double BitcoinExchange::stringToDouble(std::string str, double &num)
{
	int x = 0;
	for(size_t i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ')
			x++;
	}
	if (x != 1)
		return 0;
	str = str.substr(str.find(' ') + 1, str.length());
	for(size_t i = 0; i < str.size(); i++)
	{
		if (!isdigit(str[i]) && str[i] != '.' && str[i] != '-' && str[i] != '+')
			return 0;
	}
	
	std::istringstream iss(str);
	return iss >> num ? 1 : 0;
}

int BitcoinExchange::stringToInt(std::string str, int &num)
{
    std::istringstream iss(str);
    return iss >> num ? 1 : 0;
}

int BitcoinExchange::checkData(std::string line)
{
	std::string value;
	int flag = 0;
	std::string date = line.substr(0, line.find(' '));
	if(date.size() != 10)
	{
		std::cout << "Error: bad input => " << line.substr(0,line.find("|")) << std::endl;
		return 0;
	}
	for(size_t i = 0; i < date.size(); i++)
	{
		if (date[i] == '-')
			flag++;
		if ((!isdigit(date[i]) && date[i] != '-') || flag > 2)
		{
			std::cout << "Error: bad input => " << date << std::endl;
			return 0;
		}
	}
	size_t found = line.find('-');
	std::string year = line.substr(0, found);
	std::string month = line.substr(found + 1, 2);
	std::string day = line.substr(found + 4, 2);
	int numYear;
	int numMonth;
	int numDay;
	if (stringToInt(year, numYear) && stringToInt(month, numMonth) && stringToInt(day, numDay))
	{
		if (!isValidDate(numYear, numMonth, numDay))
		{
			std::cout << "Error: bad input => " << date << std::endl;
			return (0);
		}
	}
	else
	{
		std::cout << "Error: bad input => " << date << std::endl;
		return (0);
	}
	return (1);
}

void BitcoinExchange::firstLineControl(std::string line)
{
	std::string input = "date | value";
    line = line.substr(0, line.length());
    if(input != line)
    {
        std::cout << "Error: date or value is not true" << std::endl;
        return ;
    }
}
void newLineControl(std::ifstream &input, std::string &line)
{
	while (line.empty())
	{
		std::getline(input,line);
	}
}

int BitcoinExchange::readInput(std::string inputFile, BitcoinExchange &a)
{
	std::ifstream input(inputFile);
	std::string line;
	std::string date;
	double amount;
	int flag = 0;

	if (!input)
	{
		std::cout << "Error: File not open!" << std::endl;
		return(0);
	}
	else if (input.peek() == std::ifstream::traits_type::eof())
	{
		std::cout << "Error: File is empty!" << std::endl;
		return(0);
	}
	newLineControl(input, line);
	firstLineControl(line);
	while(std::getline(input,line))
	{
		size_t found = line.find(' ');
		if (!line.empty())
		{
				if (checkData(line))
				{
					date = line.substr(0, found);					
					if (line.find('|') != std::string::npos)
					{
						if (!stringToDouble(line.substr(line.find('|') + 1, line.length()), amount))
						{
							std::cout << "Error: bad input => " << line.substr(line.find('|') + 1, line.length()) << std::endl;
							flag = 1;
						}
						else if (amount > 1000)
						{
							std::cout << "Error: too large a number." << std::endl;
							flag = 1;
						}
						else if (amount < 0)
						{
							std::cout << "Error: not a positive number." << std::endl;
							flag = 1;
						}
						else
							flag = 0;
					}
					else
					{
						amount = 1001;
						flag = 0;
					}
					if (!flag)
						a.operation(date, amount);
				}
		}
	}
	return 1;
}

void BitcoinExchange::readFiles(std::string inputFile, BitcoinExchange &a)
{
	if (!readCsv())
		return ;
	if (!readInput(inputFile, a))
		return ;
}