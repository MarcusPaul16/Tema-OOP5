#ifndef LAB5_CONSOLE_H
#define LAB5_CONSOLE_H
#include "Repo.h"
#include "Service.h"
class Console {
private:
    Service* service;
public:
    Console(Service* service);
    ~Console();
    void ConsoleOn();
    void showSubsequence(short, short);
};


#endif //LAB5_CONSOLE_H
