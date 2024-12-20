#pragma once

#include <iostream>

using namespace std;

class machinery
{
public:
	void virtual build() { cout << "machinery build" << endl; };
};

class vehicule : public machinery
{
public:
	void build() { cout << "vehicule build" << endl; };
};

class automobile : public vehicule
{
public:
	void build() { cout << "automobile build" << endl; };
};


//prototypes
void example1_inheritance();

