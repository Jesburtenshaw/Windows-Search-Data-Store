// WinSearchStoreServer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

#include <thread>
#include <atomic>
#include <grpcpp/grpcpp.h>
#include "ExplorerService.h"




void ServerThreadProc(std::unique_ptr<grpc::Server>& server) 
{
    
    printf("Press 'Q' to shutdown server....\n");
    char c;
    while (std::cin >> c) {
        if (c == 'Q' || c == 'q') 
        {
            server->Shutdown();
            break;
        }
    }
}

void RunServer()
{
    printf("======== Starting server ========\n");

    std::string strServerAdress = "0.0.0.0:50051";
    ExplorerServiceImpl service;

    grpc::ServerBuilder builder;
    builder.AddListeningPort(strServerAdress, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);

    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());

    std::thread serverThreadHandler(ServerThreadProc, std::ref(server));

    printf("Server is listening to %s\n", strServerAdress.c_str());
    server->Wait();


    serverThreadHandler.join();

    printf("======== Server shutdown ========\n");
}


int main()
{
    RunServer();

    return 0;
}
