#include "BitcoinExchange.hpp"

std::string trim(const std::string& s)
{
	size_t start = 0;

	while (start < s.size() && isspace(s[start]))
		start++;

	size_t end = s.size();

	while (end > start && isspace(s[end - 1]))
		end--;

	return s.substr(start, end - start);
}

bool parseDate(const std::string& s, int& year, int& month, int& day)
{
	if (s.size() != 10 || s[4] != '-' || s[7] != '-')
		return false;

	for (int i = 0; i < 4; i++)
		if (!isdigit(s[i])) return false;

	for (int i = 5; i < 7; i++)
		if (!isdigit(s[i])) return false;

	for (int i = 8; i < 10; i++)
		if (!isdigit(s[i])) return false;

	year = atoi(s.substr(0, 4).c_str());
	month = atoi(s.substr(5, 2).c_str());
	day = atoi(s.substr(8, 2).c_str());

	if (year < 2009)
		return false;
	if (month < 1 || month > 12)
		return false;
	if (day < 1 || day > 31)
		return false;

	if (year == 2009 && month == 1 && day < 2)
		return false;

	return true;
}

bool parseValue(const std::string& s, float& value)
{
	if (s.empty())
		return false;

	bool dotFound = false;

	for (size_t i = 0; i < s.size(); ++i)
	{
		char c = s[i];

		if (c == '.')
		{
			if (dotFound) return false;
			dotFound = true;
		}
		else if (i == 0 && c == '-')
		{
			continue;
		}
		else if (!std::isdigit(c))
		{
			return false;
		}
	}

	value = std::atof(s.c_str());

	if (value < 0.0f)
		return false;
	if (value > 1000.0f)
		return false;

	return true;
}

double exchange(float value, const std::string &date, const std::map<std::string, std::string> &db)
{
	std::map<std::string, std::string>::const_iterator it = db.lower_bound(date);

	if (it == db.end() || it->first != date)
		--it;

	std::stringstream ss(it->second);
	double rate;
	ss >> rate;

	return static_cast<double>(value) * rate;
}
