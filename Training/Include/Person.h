#pragma once
#include <string>
#include <iostream>

using namespace std;

class person
{
	private:
		string _name;
		string _phonenumber;
		string _city;
		string _country;

	public:
		void setname(string name) { _name = name; };
		void setphonenumber(string phonenumber) { _phonenumber = phonenumber; };
		void setcity(string city) { _city = city; };
		void setcountry(string country) { _country = country; };

		person(string name) : _name(name) {};

		friend ostream& operator<< (ostream& os, const person& p);
		friend string& operator>> (string& s, const person& p);

		string operator() () const { return _name; };	// function operator

};
