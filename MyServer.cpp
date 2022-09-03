//
// Created by Никита on 05.08.2022.
//

#include "MyServer.h"

void createNewWorker(const SOCKET clientSocket, int workerNum);


MyServer::MyServer(const char* ip_addr, const char* port, int workers_amount) {
    myWSAStartup();
    cleanHints();
    setHints();
    addrInit(ip_addr, port);
    listenSocketInit();
    connectSocketAndIP();
    socketInit();
    _workers_amount = workers_amount;
}

MyServer::~MyServer() {
    closesocket(_listenSocket);
    freeaddrinfo(_addr);
    WSACleanup();
}

int MyServer::myWSAStartup() {
    int result = WSAStartup(MAKEWORD(2, 2), &_wsaData);
    if (result != 0) {
        std::string errMessage = "WSA START UP FAILED. Result: ";
        errMessage.append(std::to_string(result));
        throw MySocketExeption(errMessage.c_str());
    }
    return 0;
}

void MyServer::cleanHints() {
    ZeroMemory(&_hints, sizeof(_hints));
}

void MyServer::setHints() {
    _hints.ai_family = AF_INET;
    _hints.ai_socktype = SOCK_STREAM;
    _hints.ai_protocol = IPPROTO_TCP;
    _hints.ai_flags = AI_PASSIVE;
}

int MyServer::addrInit(const char *ipAddr, const char *port) {
    int addrInfo = getaddrinfo(ipAddr, port, &_hints, &_addr);
    if (addrInfo != 0) {
        std::string errMessage = "GET ADDR INFO FAILED. WSA last error: ";
        errMessage.append(std::to_string(WSAGetLastError()));
        throw MySocketExeption(errMessage.c_str());
    }
    return 0;
}

int MyServer::listenSocketInit() {
    _listenSocket = socket(_addr->ai_family, _addr->ai_socktype, _addr->ai_protocol);
    if (_listenSocket == INVALID_SOCKET) {
        std::string errMessage = "INVALID SOCKET. WSA last error: ";
        errMessage.append(std::to_string(WSAGetLastError()));
        throw MySocketExeption(errMessage.c_str());
    }
    return 0;
}

int MyServer::connectSocketAndIP() {
    int result = bind(_listenSocket, _addr->ai_addr, (int) _addr->ai_addrlen);
    if (result == SOCKET_ERROR) {
        std::string errMessage = "SOCKET AND IP CONNECTION FAILED. WSA last error: ";
        errMessage.append(std::to_string(WSAGetLastError()));
        throw MySocketExeption(errMessage.c_str());
    }
    return 0;
}

int MyServer::socketInit() {
    if (listen(_listenSocket, SOMAXCONN) == SOCKET_ERROR) {
        throw MySocketExeption(std::to_string(WSAGetLastError()).c_str());
    }
    return 0;
}

int MyServer::genWorkers(int amount){
    for (int i = 0; i < amount; ++i) {
        _jthreads.emplace_back(createNewWorker, _listenSocket, i);
    }
    return 0;
}

void MyServer::run() {
    genWorkers(_workers_amount);
}


void createNewWorker(SOCKET clientSocket, int workerNum){
    MyWorker myWorker(clientSocket);
    myWorker.run(workerNum);
}