#include <iostream>
#include <cctype>

int main(int argc, char *argv[])
{
	if (argc > 1)
	{
		int i = 1;

		while (i < argc)
		{
			unsigned int j = 0;
			std::string arg = argv[i];
			while (j < arg.length())
			{
				arg[j] = std::toupper(arg[j]);
				j++;
			}
			std::cout << arg;
			i++;
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return 0;
}
