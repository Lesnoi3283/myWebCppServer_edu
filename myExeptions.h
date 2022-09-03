//
// Created by Никита on 05.08.2022.
//

#ifndef MYSERVER2_MYEXEPTIONS_H
#define MYSERVER2_MYEXEPTIONS_H
#include <stdexcept>

class MySocketExeption : public std::logic_error {
public:
    explicit MySocketExeption(const char* message): std::logic_error(message) {}
};

#endif //MYSERVER2_MYEXEPTIONS_H
