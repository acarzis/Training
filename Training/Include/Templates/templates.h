#pragma once

#include <iostream> 

using namespace std;

// this is an example of a class template
template<class T>
class Test {
private:
	T obj;
public:
	Test(T obj) {
		this->obj = obj;
	}
	void print() {
		cout << obj << endl;
	}
};

template<class T>
void print(T n) {
	cout << n << endl;
};


// auto was introduced in C++ 14. 'auto' will try to deduce the return type
// this is an example of a function template
template<typename T1, typename T2>
auto max(T1	a, T2 b)
{
	return	b < a ? a : b;
}

// below method uses a default argument to help in deducing the return type
// std::common_type_t is called a type trait
template<typename T1, typename T2, typename RT = std::common_type_t<T1, T2>>
RT max2(T1	a, T2	b)
{
	return	b < a ? a : b;
}

// prototype for a non-template version of max2.
// the non-template version takes precedence
int max2(int a, int b);

// this is an example of a variable template
template <class Type>
constexpr Type speed_of_light = Type(299'792'458);
