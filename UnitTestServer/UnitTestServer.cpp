// UnitTestServer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <grpcpp/grpcpp.h>

#include "ExplorerService.grpc.pb.h"



int main()
{
    auto channel = grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials());
    std::unique_ptr<WinSearchStore::ExplorerService::Stub> stub = WinSearchStore::ExplorerService::NewStub(channel);

    WinSearchStore::DataRequest request;
    request.set_value(42);

    WinSearchStore::DataResponse response;
    grpc::ClientContext context;

    grpc::Status status = stub->GetResult(&context, request, &response);

    if (status.ok()) {
        std::cout << "Response: " << response.message() << std::endl;
    }
    else {
        std::cout << "RPC failed" << std::endl;
    }

    return getchar();
}

