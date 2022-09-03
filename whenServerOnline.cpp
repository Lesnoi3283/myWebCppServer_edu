//
// Created by Никита on 06.08.2022.
//
#define URI_FIRST_PAGE "/"

#include "whenServerOnline.h"
#include "pageClasses/FirstPage.h"
#include "MyFilePicker.h"


void whenServerOnline(SOCKET clientSocket) {

    MyHttp http(getRequest(clientSocket));
    std::string response;

    if(http.isTargetPage()){
        response = getPageResponse(http);
    } else if(http.isTargetFile()){
        response = getFileResponse(http);
    }

    int result = send(clientSocket, response.c_str(), response.length(), 0);
    if (result == SOCKET_ERROR) {
        std::string errMessage = "SEND FAILED. WSA last error: ";
        errMessage.append(std::to_string(WSAGetLastError()));
        throw MySocketExeption(errMessage.c_str());
    }

    closesocket(clientSocket);
}

std::string getRequest(SOCKET clientSocket){
    int result = 0;
    const int max_client_buffer_size = 1024;
    char buf[max_client_buffer_size] = { 0 };
    std::string strBuf(buf);
    result = recv(clientSocket, buf, max_client_buffer_size, 0);
    strBuf.append(buf);

    if (result == SOCKET_ERROR) {
        cerr << "recv failed: " << result << "\n";
        closesocket(clientSocket);
    }
    else if (result == 0) {
        cerr << "connection closed...\n";
    }

    return buf;
}

std::string getPageResponse(const MyHttp http){
    std::string uri(http.getUri());
    std::string html;
    int statusCode;
    if(uri == URI_FIRST_PAGE){
        FirstPage page(http);
        html = page.getHtml();
        statusCode = 200;
    } else{
        statusCode = 404;
    }
    return createResponse(statusCode, std::string("text/html"), html);
}

std::string getFileResponse(const MyHttp http){
    std::string fileStr;
    std::string path(http.getUri());
    path.insert(0, "..");

    MyFilePicker picker(path);
    fileStr.append(picker.fileToStr());

    return createResponse(picker.getStatusCode(), picker.getContentType(), fileStr);
}

std::string createResponse(int statusCode, std::string contentType, std::string body) {
    std::stringstream response;
    switch (statusCode) {
        case 200:
            response << "HTTP/1.1 200 OK\r\n";
            break;
        case 404:
            response << "HTTP/1.1 404 Not Found\r\n";
            break;
    }
    response << "Version: HTTP/1.1\r\n"
             << "Content-Type: " << contentType
             <<"; charset=utf-8\r\n"
             << "Content-Length: " << body.length()
             << "\r\n\r\n"
             << body;

    return response.str();
}

