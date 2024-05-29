#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>

class BitcoinExchange
{
    private:
        std::map<std::string, double> _map;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &);
        BitcoinExchange &operator=(const BitcoinExchange &);
        ~BitcoinExchange();
        void readFiles(std::string inputFile, BitcoinExchange &a);
        int readCsv();
        int readInput(std::string inputFile, BitcoinExchange &a);
        void operation(std::string date, double amount);
        int checkData(std::string line);
        bool isValidDate(int year, int month, int day);
        bool isLeapYear(int year);
        void firstLineControl(std::string line);
        double stringToDouble(std::string str, double &num);
        int stringToInt(std::string str, int &num);

};
#endif