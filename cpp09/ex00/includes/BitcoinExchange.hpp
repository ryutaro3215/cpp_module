#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <string>



std::map<std::string, float> read_date_csv();
float strToFloat(std::string str);
void printBitcoinAmount(std::string input_path, std::map<std::string, float>& price_data);
std::string calcBitcoinVal(std::string date, std::string amount, std::map<std::string, float>& price_data);
std::string trimSpace(std::string str);
std::string checkDate(std::string date);
std::string checkAmount(std::string amount);
bool checkYear(std::string year);
bool checkMonth(std::string month);
bool checkDay(std::string day, std::string month, std::string year);
bool isLeapYear(int y);
template<typename T>
T strToT(std::string input);
float getRate(std::string date, std::map<std::string, float>& price_data);



#endif
