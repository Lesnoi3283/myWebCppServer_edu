//
// Created by Никита on 01.09.2022.
//

#ifndef MYSERVER2_PAGE_H
#define MYSERVER2_PAGE_H

#include <string>
#include "../MyHttp.h"

class Page {

protected:
    MyHttp _httpRequest;
    virtual void DoPutDataInHtml(std::string* html);

public:

    virtual std::string DoGetPageFileName()=0;

    //"template method" pattern
    std::string getHtml();

    Page(const MyHttp &httpRequest);

};



#endif //MYSERVER2_PAGE_H
