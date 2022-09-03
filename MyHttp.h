//
// Created by Никита on 01.09.2022.
//

#ifndef MYSERVER2_MYHTTP_H
#define MYSERVER2_MYHTTP_H

#include <iostream>
#include <cstring>

class MyHttp {

private:
    std::string _request;

public:

    MyHttp(std::string http);

    std::string getRequest();

    std::string getUri() const;

    bool isTargetPage();

    bool isTargetFile();
};

#endif //MYSERVER2_MYHTTP_H
