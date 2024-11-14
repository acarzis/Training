#pragma once
#include <iostream> 

template<typename T, int size> 
class DynamicArray
{
	private:
		T _array[size] = {0};

	public:
		friend std::ostream& operator<< (std::ostream& os, const DynamicArray& array)
		{
			int sz = sizeof(array) / sizeof(T);
			for (int loop = 0; loop < sz; loop++)
			{
				if (loop != 0)
					os << ", ";
				os << (char) array[loop];	// requires implementation of index operator, below
			}
			return os;
		}
		const T& operator[] (int index) const;

		friend string& operator>> (string& s, const DynamicArray& array)
		{
			int sz = sizeof(array) / sizeof(T);
			for (int loop = 0; loop < sz; loop++)
			{
				if (loop != 0)
					s += ", ";
				s += array[loop];
			}
			return s;
		}
};

template<typename T, int size>
inline const T& DynamicArray<T, size>::operator[](int index) const
{
	if (index >= size) {
		exit(0);
	}
	return _array[index];
}

