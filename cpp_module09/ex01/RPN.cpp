#include "RPN.hpp"

void rpn(std::string str)
{
	std::stack<int> nums;
	size_t i = 0;
	int n, n1, n2, res;
	bool saw_operator = false;

	while (i < str.size())
	{
		while (i < str.size() && isspace(static_cast<unsigned char>(str[i])))
			i++;
		if (i >= str.size())
			break;

		char c = str[i];

		if (!isdigit(static_cast<unsigned char>(c)) && c != '+' && c != '-' && c != '*' && c != '/')
		{
			std::cout << "Error" << std::endl;
			return;
		}

		if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			saw_operator = true;
			if (nums.size() >= 2)
			{
				n1 = nums.top(); nums.pop();
				n2 = nums.top(); nums.pop();
				if (c == '+') res = n2 + n1;
				else if (c == '-') res = n2 - n1;
				else if (c == '*') res = n2 * n1;
				else
				{
					if (n1 == 0)
					{
						std::cout << "Division by zero: undefined" << std::endl;
						return;
					}
					res = n2 / n1;
				}
				nums.push(res);
			}
			else
			{
				std::cout << "Error" << std::endl;
				return;
			}
		}
		else if (isdigit(static_cast<unsigned char>(c)))
		{
			n = c - '0';
			nums.push(n);
		}

		i++;
	}

	if (nums.size() != 1 || !saw_operator)
	{
		std::cout << "Error" << std::endl;
		return;
	}

	std::cout << nums.top() << std::endl;
}
