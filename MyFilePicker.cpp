//
// Created by Никита on 03.09.2022.
//

#include <fstream>
#include "MyFilePicker.h"

std::string MyFilePicker::fileToStr() {

    std::ifstream fin(_path.c_str());
    std::string strTMP;
    std::string strFile;
    if(fin.is_open()){
        while(!fin.eof()){
            getline(fin, strTMP);
            strFile += strTMP;
            if (!fin.eof()){
                strFile += '\n';
            }
        }
        fin.close();
        _statusCode = 200;
    }else{
        _statusCode = 404;
    }
    return strFile;

}

int MyFilePicker::getStatusCode() const {
    return _statusCode;
}

const std::string &MyFilePicker::getFileType() const {
    return _fileType;
}

void MyFilePicker::setFileType() {
    _fileType.clear();
    std::string fileType(_path);
    _fileType.append(fileType.erase(0, fileType.find_last_of('.')+1));
}

MyFilePicker::MyFilePicker(const std::string &path) : _path(path) {
    setFileType();
}

//return content type for http response (like "text/html")
std::string MyFilePicker::getContentType() const {

    if(_fileType == "html"){
        return std::string("text/html");
    } else if(_fileType == "js"){
        return std::string("text/javascript");
    }else if(_fileType == "css"){
        return std::string("text/css");
    }
    else if(_fileType == "png"){
        return std::string("image/png");
    }else if(_fileType == "jpeg"){
        return std::string("image/jpeg");
    }else if(_fileType == "ico"){
        return std::string("image/vnd.microsoft.icon");
    }
    return std::string("");
}
