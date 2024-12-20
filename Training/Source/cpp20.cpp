#include <string>
#include <iostream>
#include <vector>
#include <format>

//import std;							// import module, c++ 20 only

using namespace std;


void example1_std_erase()
{
	vector<string> stringvec;

	// braced intialization
	string temp = "This is a sample string";
	string temp2{ "This is a 2nd sample string" };
	
	stringvec.push_back(temp);
	stringvec.push_back(temp2);
	std::erase(stringvec, temp2);

	for (vector<string>::const_iterator it = stringvec.begin(); it != stringvec.end(); ++it)
	{
		cout << "String: " << *it << endl;
	}
}

void example2_format()
{
	string t1 = "Angelo";
	int t2 = 5;
	double t3 = 6.89;

	cout << std::format("{}, this is a formatted string", t1);
}

constexpr auto example3_constexpr()
{
	// this is evaluated at compile time
	vector<int> vec{ 1, 2, 3, 4, 5 };
	return vec;
}

void example4_cmpl_less()
{
	int x{ -3 };
	unsigned y{ 7 };
	if (std::cmp_less(x, y))
		puts("true");
	else
		puts("false");

}
