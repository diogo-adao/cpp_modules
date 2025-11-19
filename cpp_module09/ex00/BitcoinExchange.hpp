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


#endif
