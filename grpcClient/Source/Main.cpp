#include <grpcpp/grpcpp.h>
#include <iostream>

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
	// build an rpc client to clal the computeSum method from the server
	::Point request;
	request.set_x(1.1);
	request.set_y(2.3);
	request.set_z(3.8);

	std::string server_address{ "localhost:9977" };

	std::shared_ptr<grpc::Channel> channel = grpc::CreateChannel(server_address, grpc::InsecureChannelCredentials());
	std::unique_ptr<ProcessingService::Stub> _stub = ProcessingService::NewStub(channel);
	grpc::ClientContext context;
	::Numeric response;
	grpc::Status status;
	status = _stub->computeSum(&context, request, &response);

	// Handle response
	if (status.ok()) {
		cout << "response: " << response.value() << endl;
	}
	else {
		std::cerr << status.error_code() << ": " << status.error_message() << std::endl;
	}
}
