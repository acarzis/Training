#pragma once

#include <iostream>

using namespace std;

class engine
{
public:
	engine() { cout << "engine ctor" << endl; };
	~engine() { cout << "engine dtor" << endl; };
};


class machinery
{
public:
	void virtual build() { cout << "machinery build" << endl; };
	machinery() { cout << "machinery ctor" << endl; };
	~machinery() { cout << "machinery dtor" << endl; };
};

class vehicle : public machinery
{
public:
	void build() { cout << "vehicle build" << endl; };
	vehicle() { cout << "vehicle ctor" << endl; };
	~vehicle() { cout << "vehicle dtor" << endl; };
};

class automobile : public vehicle
{
public:
	void build() { cout << "automobile build" << endl; };
	automobile() { cout << "automobile ctor" << endl; };
	~automobile() { cout << "automobile dtor" << endl; };

private:
	engine m_engine;
};



//prototypes
void example1_inheritance();
void example2_inheritance();
void example3_inheritance();

