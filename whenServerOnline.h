//
// Created by Никита on 05.08.2022.
//

#ifndef MYSERVER2_WHENSERVERONLINE_H
#define MYSERVER2_WHENSERVERONLINE_H

#include "myExeptions.h"
#include "MyHttp.h"
#include <iostream>
#include <sstream>
#include <string>
#include <thread>
#include <WinSock2.h>
#include <WS2tcpip.h>
#pragma comment(lib, "Ws2_32.lib")
using std::cerr;

void whenServerOnline(SOCKET clientSocket);
std::string getRequest(SOCKET clientSocket);
std::string getPageResponse(const MyHttp http);
std::string getFileResponse(const MyHttp http);
std::string createResponse(int statusCode, std::string contentType, std::string body);

#endif //MYSERVER2_WHENSERVERONLINE_H
