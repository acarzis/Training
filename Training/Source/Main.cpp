#include <grpcpp/grpcpp.h>
#include <future>

#include "../Include/Main.h"
#include "../Include/Person.h"
#include "../Include/Templates/DynamicArray.h"
#include "../Include/Templates/MyVector.h"
#include "../Include/Templates/Stack.h"
#include "../Include/spdlog/spdlog.h"

#include "../proto/service.pb.h"
#include "../gRPC/service.grpc.pb.h"
#include "../Include/Templates/templates.h"
#include "../Include/cpp20.h"
#include "../Include/basic_concepts.h"

#include "amphibian.h"
#include "inheritance.h"

using namespace std;


// this is the grpc method we want to implement
class ProcessingImpl : public ProcessingService::Service
{
	::grpc::Status computeSum(::grpc::ServerContext* context, const ::Point* request, ::Numeric* response)
	{
		std::cout << "Called!" << std::endl;
		response->set_value(request->x() + request->y() + request->z());
		return grpc::Status::OK;
	}
};


int main()
{
	int n = 10;
	cout << n << " factorial is: " << factorial(n) << endl;

	string tempstring;
	person p1("Angelo");
	p1.setcity("Montreal");
	p1.setphonenumber("5145559999");
	p1.setcountry("Canada");

	cout << "person (with outstream overloaded): "  << p1 << endl;

	tempstring >> p1;
	cout << "string class >> overloaded for person: " << tempstring << endl;

	// template use, example 1 - dynamic array
	DynamicArray<int, 30> myarray;
	//	DynamicArray<person, 30> junk;	// illegal, won't compile

	// overload the output stream & string class
	cout << "dynamic array initialized to empty values: " << myarray << endl;
	tempstring.clear();
	tempstring >> myarray;
	spdlog::info(tempstring);

	// template use, example 2 - MyVector, a variation of DynamicArray
	MyVector<string> mystringvector(5);
	MyVector<int> myintvector(5);

	for (string s : mystringvector)
		cout << s << '\n';

	// using the max template function
	cout << "Max(6, 7.2): " << ::max(6, 7.2) << endl;
	cout << "Max2(6, 7.2): " << ::max2(6, 7.2) << endl;
	cout << "Max2(6, 7): " << ::max2(6, 7) << endl;


	// using the template class 'Stack'
	::Stack<int> myIntStack;
	myIntStack.push(7);
	std::cout << "Top element from the Stack: "  << myIntStack.top() << endl;
	std::cout << "Printing the int Stack via an out stream: " << myIntStack << endl;

	::Stack<string> myStringStack;
	myStringStack.push("Angelo");
	std::cout << "Printing the string Stack via an out stream: " << myStringStack << endl;

	// use the variable template
	std::cout << "Speed of light (double): " << speed_of_light<double> << endl;
	std::cout << "Speed of light (long): " << speed_of_light<long> << endl;


	// use the function operator
	cout << endl;
	cout << "person(): " << p1() << endl;

	// example, diamond problem & virtual inheritance
	amphibian kermitFrog;	// inherits from both land_animal & aquatic_animal who both inherit from animal
	kermitFrog.breath();	// this statement will throw an error without virtual inheritance


	// build an rpc server
	/*
	ProcessingImpl myservice;
	grpc::ServerBuilder builder;
	builder.AddListeningPort("0.0.0.0:9977", grpc::InsecureServerCredentials());
	builder.RegisterService(&myservice);
	std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
	server->Wait();
	*/


	// some basic concepts
	example1_templates();
	example2_lambdas();
	cout << endl; example3_functionpointers();
	example4_copyconstructors();
	example5_removeduplicates();
	example6_reversestring();
	example7_smartpointers();
	example8_strings();

	cout << endl; example1_inheritance();
	cout << endl; example2_inheritance();
	cout << endl; example3_inheritance();


	// playing with futures (async operations)
	future<int> fut = async(launch::async, []() {
		return 14;
		});

	future<string> fut2 = async(launch::async, []() {
		return string("Angelo is running a test");
		});

	// in the background, there are promises with put commands for the equivalent get
	cout << endl <<  "Future result: " << fut.get() << " result2: " << fut2.get() << endl;

	// c++ 20 examples
	cout << endl; 
	example1_std_erase();
	example2_format();
	example3_cmp_less(6, 7u);
	example3_cmp_less(-1, 7u);

	return 0;
}

constexpr long factorial(int n)
{
	if (n == 1) return 1;
	return n * factorial(n - 1);
}

