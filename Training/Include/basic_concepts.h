#pragma once

// prototypes
int squared(int x);
void example1_templates();
void example2_lambdas();
void example3_functionpointers();
void example4_copyconstructors();
void example5_removeduplicates();
void example6_reversestring();
void example7_smartpointers();
void example8_strings();


struct retrieveValues
{
public:
	string operator() (const std::pair<int, string> p) { return p.second; };
};

struct machine
{
private:
	vector<string> carList = { "Bugatti Divo", "Lamborghini Veneno" };
	char* machineName = nullptr;

public:
	void AddCar(string car) { carList.push_back(car); };
	void AddName(string name) { machineName = new char[20]; strcpy(machineName, name.c_str()); };	// ignoring length check
	void Print() { cout << "carList: "; for (string i : carList) { cout << i << ", "; }; cout << endl << "machineName: " << (machineName!=nullptr?machineName:"") << endl; }
	void RemoveName() { delete machineName; machineName = nullptr; };
};

struct bettermachine
{
private:
	vector<string> carList = { "Bugatti Divo", "Lamborghini Veneno" };
	char* machineName = nullptr;

public:
	void AddCar(string car) { carList.push_back(car); };
	void AddName(string name) { machineName = new char[20]; strcpy(machineName, name.c_str()); };	// ignoring length check
	void Print() { cout << "carList: "; for (string i : carList) { cout << i << ", "; }; cout << endl << "machineName: " << (machineName != nullptr ? machineName : "") << endl; }
	void RemoveName() { delete machineName; machineName = nullptr; };

	bettermachine() {};

	// copy constructor
	bettermachine(bettermachine& m)
	{
		machineName = new char[20];
		strcpy(machineName, m.machineName);
	}

	bettermachine& operator=(const bettermachine& bm)
	{
		// Check for self-assignment
		if (this != &bm) {
			machineName = bm.machineName;
		}
		return *this;
	}
};
