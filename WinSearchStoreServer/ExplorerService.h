#pragma once

#include "ExplorerService.grpc.pb.h"
#include <grpcpp/grpcpp.h>


class ExplorerServiceImpl final : public WinSearchStore::ExplorerService::Service {
    grpc::Status GetResult(grpc::ServerContext* context, const WinSearchStore::DataRequest* request, WinSearchStore::DataResponse* response) override 
    {
        int value = request->value();
        response->set_message("Server received numer: " + std::to_string(value));
        return grpc::Status::OK;
    }
};

