//
// Created by Никита on 03.09.2022.
//
#define PAGES_PATH "../pages/"

#include "Page.h"
#include "../MyFilePicker.h"


std::string Page::getHtml() {
    std::string path(PAGES_PATH);
    path.append(DoGetPageFileName());
    MyFilePicker picker(path);

    std::string html(picker.fileToStr());
    DoPutDataInHtml(&html);
    return html;
}

//default DoPutDataInHtml makes nothing
void Page::DoPutDataInHtml(std::string* html) {}


Page::Page(const MyHttp &httpRequest) : _httpRequest(httpRequest) {}
