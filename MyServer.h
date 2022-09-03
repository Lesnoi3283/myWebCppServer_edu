//
// Created by Никита on 05.08.2022.
//

#ifndef MYSERVER2_MYSERVER_H
#define MYSERVER2_MYSERVER_H

#include "myExeptions.h"
#include "whenServerOnline.h"
#include "MyWorker.h"
#include <thread>
#include <mutex>
#include <iostream>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <list>

#pragma comment(lib, "Ws2_32.lib")
using std::cerr;

//Starts WSA, sets network settings, sets IP and Port. Prepares server to be turned on in its constructor.
//After turning on (in run()) creates workers. The accepts new connections
class MyServer {

private:
    SOCKET _listenSocket;
    WSAData _wsaData;
    struct addrinfo* _addr = NULL;
    struct addrinfo _hints;
    std::vector<std::jthread> _jthreads;
    int _workers_amount;

    int myWSAStartup();

    void cleanHints();

    void setHints();

    int addrInit(const char* ipAddr, const char* port);

    int listenSocketInit();

    int connectSocketAndIP();

    int socketInit();

    int genWorkers(int amount);

public:
    MyServer(const char* ip_addr, const char* port, int workers_amount);

    virtual ~MyServer();

    void run();
};


#endif //MYSERVER2_MYSERVER_H
