
#include <string>
#include <algorithm>
#include "../Include/Templates/templates.h"
#include <map>
#include <vector>
#include <array>
#include "../Include/basic_concepts.h"


using namespace std;

void example1_templates()
{
	// template 
	Test<string> test1("Hello template class");
	test1.print();
	print<string>("Hello template function");

	Test<int> test2(75);
	test2.print();
	print<int>(75);
}

void example2_lambdas()
{
	map<int, string> names4;
	names4[0] = "Angelo";
	names4[1] = "Peter";
	names4[2] = "John";
	names4[3] = "Bill";
	names4[4] = "George";
	names4[5] = "Louie";

	vector<string> names4Values;
	retrieveValues functor;			// retrieveValues - retuirns the second element of a map
	transform(names4.begin(), names4.end(), back_inserter(names4Values), functor);

	cout << endl << "Extract map values to vector via a transform, output:" << endl;
	for (int x = 0; x < names4Values.size(); x++)
	{
		string sTemp = names4Values.at(x);
		cout << "element: " << x << "   " << sTemp << endl;
	}

	cout << endl << "Print a vector backwards via a reverse iterator, output:" << endl;
	for (vector<string>::reverse_iterator it = names4Values.rbegin(); it != names4Values.rend(); it++)
	{
		int x = 1;
		cout << "element: " << x++ << "   " << (*it) << endl;
	}

	// lambda in C++ - let's sort in reverse
	sort(names4Values.begin(), names4Values.end(),
		[](string i, string j) -> bool {					// [] capture nothing, return bool 
			if (i.compare(j) > 0)
				return true;
			else
				return false;

		});

	cout << endl << "Reverse sort via lambda, output:" << endl;
	for (int x = 0; x < names4Values.size(); x++)
	{
		string sTemp = names4Values.at(x);
		cout << "element: " << x << "   " << sTemp << endl;
	}
}

int squared(int x)
{
	return x * x;
}

void example3_functionpointers()
{
	// playing with function pointers
	int (*myfunc)(int) = NULL;
	myfunc = squared;

	cout << "2 squared = " << myfunc(2) << endl;
}

void example4_copyconstructors()
{
	machine m1;
	m1.AddCar("Pagani Imola");
	m1.AddName("Machine1");
	m1.Print();

	machine m2(m1);
	m2.Print();
	m1.RemoveName();
	m1.Print();
	m2.Print();					// prints garbage

	machine m3;
	m1.AddName("Machine1");
	m1.Print();					// prints Machine1 
	m3 = m1;
	m3.RemoveName();
	m3.Print();					// prints nothing
	m1.Print();					// prints garbage

	cout << "-----------------------" << endl;

	bettermachine m4;
	m4.AddCar("Pagani Imola");
	m4.AddName("Machine1");
	m4.Print();

	bettermachine m5(m4);
	m5.Print();
	m4.RemoveName();
	m4.Print();
	m5.Print();  // prints fine

	bettermachine m6;
	m6.AddName("Machine1");
	m6.Print();					// prints Machine1 
	m6 = m4;
	m6.RemoveName();
	m4.AddName("Machine1");
	m6.Print();					// prints nothing
	m4.Print();					// prints Machine1
}


void example5_removeduplicates()
{
	array<int, 5> arr = { 12, 11, 11, 10, 4 };
	vector<int> nodups;
	
	// approach 1
	for (int x = 0; x < arr.size(); ++x)
	{
		if (std::find(nodups.begin(), nodups.end(), arr[x]) == nodups.end())
			nodups.push_back(arr[x]);
	}

	cout << "Duplicates removed: " << endl;
	for (vector<int>::const_iterator it = nodups.begin(); it < nodups.end(); ++it)
		cout << *it << " ";

	cout << endl << "Sorted: " << endl;
	std::sort(nodups.begin(), nodups.end());
	for (vector<int>::const_iterator it = nodups.begin(); it < nodups.end(); ++it)
		cout << *it << " ";

	cout << endl;

	// approach 2. sort the array traverse it comparing each element to the one after it
	std::sort(arr.begin(), arr.end());
}


void example6_reversestring()
{
	string temp = "Angelo is here";
	std::reverse(temp.begin(), temp.end());
	cout << endl << "Reversed string: " << temp << endl;

	// 2nd approach: reversing one word at a time.
	temp = "Angelo is here" + string(" ");
	bool done = false;
	vector<string> words;
	std::string::iterator begin = temp.begin();
	std::string::iterator end = temp.end();

	while (!done)
	{
		std::string::iterator it2 = std::find(begin, end, ' ');

		if (it2 != temp.end())
		{
			string word(begin, it2);
			words.push_back(word);
			begin = it2+1;
		}
		else
		{
			done = true;
		}
	}

	cout << "Reversed string: ";
	for (vector<string>::const_reverse_iterator it = words.rbegin(); it < words.rend(); ++it)
		cout << *it << " ";

}

void example7_smartpointers()
{
	cout << endl << endl << "example7..." << endl;

	shared_ptr<bettermachine> bm = make_shared<bettermachine>();
	shared_ptr<bettermachine> bm2 = make_shared<bettermachine>();
	bm = bm2;
	bm->Print();

	unique_ptr<bettermachine> bm3 = make_unique<bettermachine>();
	unique_ptr<bettermachine> bm4 = make_unique<bettermachine>();

	bm3->AddName("machine3");
	bm4->AddName("machine4");
	// bm3 = bm4;	// not permitted
	bm3->Print();
	bm3 = std::move(bm4);
	bm3->Print();			// prints machine4
}

void example8_strings()
{
	cout << endl << "example 8...";

	string temp = "This is an example of how to search and tokenize strings";

	// search for 'example'
	if (temp.find("example") != std::string::npos)
	{
		cout << "the string " << temp << " contains 'example'" << endl;
	}

	// tokenize the string
	temp += " ";
	bool done = false;
	vector<string> words;
	std::string::iterator start = temp.begin();
	std::string::iterator end = temp.end();

	while (!done)
	{
		std::string::iterator pos = std::find(start, end, ' ');
		if (pos != end)
		{
			string word(start, pos);
			words.push_back(word);
			start = pos + 1;
		}
		else
		{
			done = true;
		}
	}

	cout << "The string tokenized: " << endl;
	for (vector<string>::iterator it = words.begin(); it < words.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}
