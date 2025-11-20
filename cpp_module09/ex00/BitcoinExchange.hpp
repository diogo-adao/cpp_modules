#ifndef BTC_EXCHANGE_HPP
#define BTC_EXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <stdlib.h>
#include <cctype>
#include <sstream>

std::map<std::string, std::string> loadDB();
void readInput(std::string input, const std::map<std::string, std::string> &db);
std::string trim(const std::string& s);
bool parseDate(const std::string& s, int& year, int& month, int& day);
bool parseValue(const std::string& s, float& value);
double exchange(float value, const std::string &date, const std::map<std::string, std::string> &db);

#endif
