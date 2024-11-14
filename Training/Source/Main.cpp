﻿#include <grpcpp/grpcpp.h>

#include "../Include/Main.h"
#include "../Include/Person.h"
#include "../Include/DynamicArray.h"
#include "../Include/spdlog/spdlog.h"

#include "../proto/service.pb.h"
#include "../gRPC/service.grpc.pb.h"

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

	cout << p1 << endl;

	tempstring >> p1;
	cout << tempstring << endl;

	// template use, example 1 - dynamic array
	DynamicArray<int, 30> myarray;

	// overload the output stream & string class
	cout << myarray << endl;
	tempstring.clear();
	tempstring >> myarray;

	spdlog::info(tempstring);


	// build an rpc server
	ProcessingImpl myservice;
	grpc::ServerBuilder builder;
	builder.AddListeningPort("0.0.0.0:9977", grpc::InsecureServerCredentials());
	builder.RegisterService(&myservice);
	std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
	server->Wait();

	return 0;
}

constexpr long factorial(int n)
{
	if (n == 1) return 1;
	return n * factorial(n - 1);
}

