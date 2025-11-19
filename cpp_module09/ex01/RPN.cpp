#include "RPN.hpp"

static std::string trim(const std::string& s)
{
	size_t start = 0;

	while (start < s.size() && isspace(s[start]))
		start++;

	size_t end = s.size();

	while (end > start && isspace(s[end - 1]))
		end--;

	return s.substr(start, end - start);
}

void rpn(std::string str)
{
	std::stack<int> nums;
	std::string t = trim(str);
	int n1;
	int n2;
	int res;

	size_t i = 0;
	int n;

	while (i < t.size())
	{
		while (isspace(t[i]))
			i++;
		if (!isdigit(t[i]) && (t[i] != '+' && t[i] != '-' && t[i] != '*' && t[i] != '/'))
		{
			std::cout << "Error" << std::endl;
			return;
		}
		if (t[i] == '+' || t[i] == '-' || t[i] == '*' || t[i] == '/')
		{
			if (nums.size() >= 2)
			{
				if (t[i] == '+')
				{
					n1 = nums.top();
					nums.pop();
					n2 = nums.top();
					nums.pop();
					res = n2 + n1;
					nums.push(res);
				}
				else if (t[i] == '-')
				{
					n1 = nums.top();
					nums.pop();
					n2 = nums.top();
					nums.pop();
					res = n2 - n1;
					nums.push(res);
				}
				else if (t[i] == '*')
				{
					n1 = nums.top();
					nums.pop();
					n2 = nums.top();
					nums.pop();
					res = n2 * n1;
					nums.push(res);
				}
				else if (t[i] == '/')
				{
					n1 = nums.top();
					nums.pop();
					n2 = nums.top();
					nums.pop();
					res = n2 / n1;
					nums.push(res);
				}
			}
			else
			{
				std::cout << "Error: Not enough operands" << std::endl;
				return;
			}
		}
		if (isdigit(t[i]))
		{
			n = t[i] - '0';
			nums.push(n);
		}
		i++;
	}
	std::cout << res << std::endl;
}
