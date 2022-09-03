#include <iostream>
#include "MyServer.h"
#include "MyWorker.h"
#include <list>
#define IP_ADDRESS "127.0.0.1"
#define PORT "8000"
#define WORKERS_AMOUNT 5




int main() {

    MyServer myServer(IP_ADDRESS, PORT, WORKERS_AMOUNT);
    try {
        myServer.run();
    } catch (const MySocketExeption& e){
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    while (true){

    }
    return 0;
}
