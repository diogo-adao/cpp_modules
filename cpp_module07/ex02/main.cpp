#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
	// CREATES 2 INT ARRAYS
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));

	// INITIALIZES BOTH WITH SAME VALUES
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}

	// TESTS MEMORY LEAKS AND DEEP COPY
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	// COMPARES BOTH ARRAYS
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}

	// TESTS EXCEPTIONS FOR WRONG INDEX
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	// SAFETY TEST FOR DEEP COPY
	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	
	delete [] mirror;
	return 0;
}
