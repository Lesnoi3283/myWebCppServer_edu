//
// Created by Никита on 01.09.2022.
//


#include "MyHttp.h"

MyHttp::MyHttp(std::string http) {
    _request = http;
}

std::string MyHttp::getRequest() {
    int last = _request.find_first_of("\n");
    return _request.substr(0, last).c_str();
}

std::string MyHttp::getUri() const {
    std::string uri;
    uri.append(_request);
    uri.erase(0, uri.find_first_of(" ") +1);
    uri.erase(uri.find_first_of(" "), uri.length()-1);
    return uri;
}

bool MyHttp::isTargetPage() {
    std::string uri(getUri());

    if(uri == "/"){
        return true;
    }
    return false;
}

bool MyHttp::isTargetFile() {
    std::string uri(getUri());

    if(
            uri.ends_with("/script.js") ||
            uri.ends_with("/favicon.ico") ||
            uri.ends_with("/scrupt.js") ||
            uri.ends_with("/style.css")){
        return true;
    }
    return false;
}
