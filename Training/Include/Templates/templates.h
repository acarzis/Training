#pragma once

#include <iostream> 

using namespace std;

// playing with templates
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

