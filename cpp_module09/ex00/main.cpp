#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		std::map<std::string, std::string> db;
		db = loadDB();
		readInput(argv[1], db);
	}
	else
	{
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}

	return 0;
}
