#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <cstdlib>

template<typename T>
class Array {
	private:
		T* arr;
		unsigned int len;
	public:
		Array() : arr(NULL), len(0) {}

		Array(unsigned int n) : arr(new T[n]), len(n) {};

		Array(const Array& src) : arr(new T[src.len]), len(src.len) {
			for (unsigned int i = 0; i < len; ++i)
				arr[i] = src.arr[i];
		}

		Array& operator=(const Array& src) {
			if (this != &src)
			{
				delete[] arr;
				arr = new T[src.len];
				len = src.len;

				for (unsigned int i = 0; i < len; ++i)
					arr[i] = src.arr[i];
			}
			return *this;
		}

		~Array() { delete[] arr; }

		unsigned int size() const { return len; }

		T& operator[](unsigned int i) {
			if (i >= len)
				throw std::out_of_range("Index out of bounds");
			return arr[i];
		}
};

#endif
