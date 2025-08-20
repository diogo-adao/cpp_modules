#include "phonebook.hpp"

bool isNameValid(const std::string& name)
{
	for (size_t i = 0; i < name.size(); ++i)
	{
		char c = name[i];
		if (!std::isalpha(c) && c != ' ')
			return false;
	}
	return true;
}

bool isNumberValid(const std::string& num)
{
	for (size_t i = 0; i < num.size(); ++i)
	{
		char c = num[i];
		if (!std::isdigit(c) && c != ' ')
			return false;
	}
	return true;
}

std::string getNameInput(const std::string& prompt)
{
	std::string input;

	while (true)
	{
		std::cout << prompt;
		if (!std::getline(std::cin, input))
		{
			std::cout << "\nExiting...\n";
			std::exit(0);
		}
		if (input.empty())
			std::cout << "This field can't be empty." << std::endl;
		else if (!isNameValid(input))
			std::cout << "Name cannot contain numbers.\n";
		else
			break;
	}

	return input;
}

std::string getNumberInput(const std::string& prompt)
{
	std::string input;

	while (true)
	{
		std::cout << prompt;
		if (!std::getline(std::cin, input))
		{
			std::cout << "\nExiting...\n";
			std::exit(0);
		}
		if (input.empty())
			std::cout << "This field can't be empty." << std::endl;
		else if (!isNumberValid(input))
			std::cout << "Number cannot contain letters.\n";
		else
			break;
	}
	return (input);
}

std::string getInput(const std::string& prompt)
{
	std::string input;

	while (input.empty())
	{
		std::cout << prompt;
		if (!std::getline(std::cin, input))
		{
			std::cout << "\nExiting...\n";
			std::exit(0);
		}
		if (input.empty())
			std::cout << "This field can't be empty." << std::endl;
	}
	return (input);
}

void printTableHeader()
{
	std::cout << std::setw(10) << "Index"
			  << "|" << std::setw(10) << "First Name"
			  << "|" << std::setw(10) << "Last Name"
			  << "|" << std::setw(10) << "Nickname"
			  << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
}

void printContactRow(int index, const Contact& c)
{
	std::cout << std::setw(10) << index << "|";

	std::string fn = c.getFirst();
	if (fn.size() > 10) fn = fn.substr(0, 9) + ".";
	std::cout << std::setw(10) << fn << "|";

	std::string ln = c.getLast();
	if (ln.size() > 10) ln = ln.substr(0, 9) + ".";
	std::cout << std::setw(10) << ln << "|";

	std::string nn = c.getNickname();
	if (nn.size() > 10) nn = nn.substr(0, 9) + ".";
	std::cout << std::setw(10) << nn << std::endl;
}
