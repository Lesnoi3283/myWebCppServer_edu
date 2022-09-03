//
// Created by Никита on 01.09.2022.
//

#ifndef MYSERVER2_FIRSTPAGE_H
#define MYSERVER2_FIRSTPAGE_H
#define FIRST_PAGE_HTML_FILE_NAME "index.html"

#include <string>
#include "Page.h"

class FirstPage: public Page  {
public:

    std::string DoGetPageFileName() override;

    explicit FirstPage(MyHttp httpRequest) : Page(httpRequest) {}
};


#endif //MYSERVER2_FIRSTPAGE_H
