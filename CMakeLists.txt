cmake_minimum_required(VERSION 3.20)
project(myServer2)

set(CMAKE_CXX_STANDARD 23)

add_executable(myServer2 main.cpp whenServerOnline.h myExeptions.h MyServer.cpp MyServer.h whenServerOnline.cpp MyWorker.cpp MyWorker.h pageClasses/Page.h MyHttp.cpp MyHttp.h pageClasses/FirstPage.cpp pageClasses/FirstPage.h pageClasses/Page.cpp MyFilePicker.cpp MyFilePicker.h)
