#include "Console.h"
#include <iostream>
#include "Entity.h"
#include "Test.h"
#include "Service.h"
using namespace std;
Console::Console(Service* service) {
    this->service = service;
}
Console::~Console() {}
void Console::ConsoleOn() {
    Test test;
    test.testAll();
    bool running = true;
    short optiune;
    while (running){
        cout << "1. Adaugarea unei noi entitati:" << '\n';
        cout << "2. Afisare Entitati" << '\n';
        cout << "3. Determinarea celei mai mari entitati" << '\n';
        cout << "4. Determinarea entitatilor din primul cadran" << '\n';
        cout << "5. Determinarea celei mai lungi secvente cu entitati egale" << '\n';
        cout << "6. Exit" << '\n';
        cin >> optiune;
        if (optiune == 1){
            int parteaReala, parteaImaginara;
            cout << "Scrieti partea reala:" << '\n';
            cin >> parteaReala;
            cout << "Scrieti partea imaginara:" << '\n';
            cin >> parteaImaginara;
            Entity entity(parteaReala, parteaImaginara);
            this->service->addEntity(entity);
        }
        else if (optiune == 2){

        }
        else if (optiune == 3){
            short startPosition, endPosition;
            this->service->determinateTheLongestSubsequence(startPosition, endPosition);
        }
        else if (optiune == 6)
            running = false;
    }
}

