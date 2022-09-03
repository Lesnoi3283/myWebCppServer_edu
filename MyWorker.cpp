//
// Created by Никита on 07.08.2022.
//

#include "MyWorker.h"


MyWorker::MyWorker(const SOCKET clientSocket) : _listenSocket(clientSocket) {}

void MyWorker::run(int workerNum) {
    while (true){

        SOCKET client_socket = accept(_listenSocket, NULL, NULL);
        if (client_socket == INVALID_SOCKET) {
            std::string errMessage = "INCOMING CONNECTION ERROR (invalid socket). WSA last error: ";
            errMessage.append(std::to_string(WSAGetLastError()));
            throw MySocketExeption(errMessage.c_str());
        } else {
            whenServerOnline(client_socket);
        }

    }
}
