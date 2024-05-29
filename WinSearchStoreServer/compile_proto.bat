@echo off
SET VCPKG_TOOL=%USERPROFILE%\vcpkg\installed\x64-windows\tools
cd ..\Proto
if exist *.h del *.h
if exist *.cc del *.cc
%VCPKG_TOOL%\protobuf\protoc.exe ExplorerService.proto --plugin=protoc-gen-grpc=%VCPKG_TOOL%\grpc\grpc_cpp_plugin.exe --cpp_out=. --grpc_out=.
