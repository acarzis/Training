#include <string>
#include <iostream>
#include <vector>
#include <format>

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

// std::format is a means to replace the use of snprintf or formatting with iostreams. std::format is a variadic template
// std::format combines the type safety of iostreams with the readability of printf
// std::format supports locales for some of the data types via the 'L' specifier 
// custom formatting is provided the std::formatter>T> tempalte and its 2 methods parse & format
void example2_format()
{
	string t1 = "Angelo";
	int t2 = 5;
	double t3 = 6.89;

	cout << std::format("{}, this is a formatted string", t1) << endl;

	// let's define some variables
	string s1 = "Angelo was here";
	double s2 = 34.56;
	double s3 = 4.2;

	// > means right align, :20 occupy 20 positions
	cout << std::format("{:20} {:>8.2f} {:>8.2f}, this is a formatted string ", s1, s2, s3) << endl;

	// std::format returns a string
	string s4 = std::format("{:20} {:>8.2f} {:>8.2f}, this is a formatted string ", s1, s2, s3);
	cout << s4 << endl;
}


// std::cmp_less - arguments must be integer types
void example3_cmp_less(int x, unsigned int y)
{
	cout << std::format("example3_cmpl_less({}, {}) ", x, y) << endl;
	if (std::cmp_less(x, y))
		puts("true");
	else
		puts("false");
}
