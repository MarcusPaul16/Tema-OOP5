#include "Console.h"
#include <iostream>
#include "Entity.h"
#include "Test.h"
#include "Service.h"
using namespace std;
Console::Console(Service* service) {
    this->service = service;
}
void Console::showSubsequence(short startPosition, short endPosition) {
    Entity* p = this->service->getAll();
    for (int i = startPosition; i <= endPosition; i++){
        cout << "Entity" << i << ": ";
        cout << "Parte reala: " << p[i].getParteReala() << ' ';
        cout << "Parte imaginara: " << p[i].getParteImaginara() << '\n';
    }
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
            if (this->service->getSize() == 0)
                cout << "Nu exista nicio entitate" << '\n';
            else
                this->showSubsequence(0, this->service->getSize() - 1);
        }
        else if (optiune == 3){
            int position;
            this->service->determinateTheBiggestEntity(position);
            Entity *p = this->service->getAll();
            cout << "Cea mai mare entitate este: ";
            cout << "Parte reala: " << p[position].getParteReala() << " ";
            cout << "Parte imaginara: " << p[position].getParteImaginara() << '\n';
        }
        else if (optiune == 4){
            int count, *p;
            p = this->service->allEntitiesUnitCircle(count);
            for (int i = 0; i < count; i++){
                cout << "Entity" << i << ": ";
                cout << "Parte reala: " << this->service->getAll()[*(p+i)].getParteReala() << " ";
                cout << "Parte imaginara: " << this->service->getAll()[*(p+i)].getParteImaginara() << "\n";
            }
        }
        else if (optiune == 5){
            if (this->service->getSize() == 0)
                cout << "Nu exista nicio entitate" << '\n';
            else{
                short startPosition, endPosition;
                this->service->determinateTheLongestSubsequence(startPosition,endPosition);
                this->showSubsequence(startPosition, endPosition);
            }
        }
        else if (optiune == 6)
            running = false;
    }
}

