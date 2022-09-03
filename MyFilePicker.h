//
// Created by Никита on 03.09.2022.
//

#ifndef MYSERVER2_MYFILEPICKER_H
#define MYSERVER2_MYFILEPICKER_H


#include <string>

class MyFilePicker {
private:
    std::string _path;
    std::string _fileType;
    int _statusCode;

    //gets file type from path
    void setFileType();
public:
    std::string fileToStr();

    int getStatusCode() const;
    const std::string &getFileType() const;
    std::string getContentType() const;

    explicit MyFilePicker(const std::string &path);
};


#endif //MYSERVER2_MYFILEPICKER_H
