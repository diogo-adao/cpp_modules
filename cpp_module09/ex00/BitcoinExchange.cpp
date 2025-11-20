#include "BitcoinExchange.hpp"

std::map<std::string, std::string> loadDB()
{
	std::ifstream data("data.csv");
	std::map<std::string, std::string> db;
	std::string date;
	std::string price;

	getline(data, date);
	while (getline(data, date, ','))
	{
		getline(data, price);
		db.insert(std::make_pair(date, price));
	}

	return db;
}

void readInput(std::string input, const std::map<std::string, std::string> &db)
{
	std::ifstream myFile(input.c_str());
	std::string date;
	std::string value;
	std::string line;
	int y, m, d;
	float val;

	if (!myFile.is_open())
	{
		std::cout << "Error: could not open file." << std::endl;
		return;
	}

	getline(myFile, line);
	while (getline(myFile, line))
	{
		size_t pos = line.find('|');
		if (pos == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		date = trim(line.substr(0, pos));
		value = trim(line.substr(pos + 1));

		if (!parseDate(date, y, m, d))
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		if (!parseValue(value, val))
		{
			if (val < 0)
				std::cout << "Error: not a positive number." << std::endl;
			else if (val > 1000)
				std::cout << "Error: too large a number." << std::endl;
			else
				std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::cout << date << " => " << value << " = " << exchange(val, date, db) << std::endl;
	}
}
