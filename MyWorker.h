//
// Created by Никита on 07.08.2022.
//

#ifndef MYSERVER2_MYWORKER_H
#define MYSERVER2_MYWORKER_H


#include "whenServerOnline.h"
#include "MyServer.h"
#include <mutex>
#include <WinSock2.h>
#include <iostream>
#include <thread>
#include <list>

//in run() is a while(true) which uses WinSock "accept()" function
class MyWorker {
private:
    const SOCKET _listenSocket;

public:
    MyWorker(const SOCKET clientSocket);

    void run(int workerNum);
};


#endif //MYSERVER2_MYWORKER_H
