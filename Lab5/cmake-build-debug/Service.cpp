#include "Service.h"
#include <cmath>
#include "Repo.h"
#define PI 3.14
using namespace std;
Service::Service(Repo* repo) {
    this->repo = repo;
}
void Service::addEntity(Entity entity){
    this->repo->addEntity(entity);
}
Entity* Service::getAll(){
    return this->repo->getAll();
}
short Service::getSize(){
    return this->repo->getSize();
}
Service::~Service() {}
double Service::module(Entity entity){
    double module = sqrt(entity.getParteImaginara()*entity.getParteImaginara() + entity.getParteReala()*entity.getParteReala());
    return module;
}
bool Service::inUnitCircle(Entity entity){
    double tangent = atan(entity.getParteImaginara() / entity.getParteReala());
    if (tangent <= PI/2)
        return true;
    return false;
}
void Service::determinateTheBiggestEntity(int& position) {
    double maxim = -1;
    Entity *p = this->repo->getAll();
    for (int i = 0 ; i < this->repo->getSize(); i++){
        Entity entitate1 = p[i];
        double modul = module(p[i]);
        if (modul > maxim){
            maxim = modul;
            position = i;
        }
    }
}

int* Service::allEntitiesUnitCircle(int& count) {
    Entity *p = this->repo->getAll();
    static int pozitii[100];
    count = 0;
    for (int i = 0 ; i < this->repo->getSize(); i++){
        if (inUnitCircle(p[i])){
            pozitii[count] = i;
            count++;
        }
    }
    return pozitii;
}

void Service::determinateTheLongestSubsequence(short &startPosition, short &endPosition) {
    Entity *p = this->repo->getAll();
    short counter = 1, maxim = -1, startMaxim = 0;
    startPosition = endPosition = 0;
    for (short i = 0; i < this->repo->getSize() - 1; i++){
        if (p[i] == p[i+1])
            counter++;
        else{
            if (counter > maxim){
                maxim = counter;
                startMaxim = startPosition;
                counter = 1;
            }
            startPosition = i + 1;
        }
    }
    if (counter > maxim){
        maxim = counter;
        startMaxim = startPosition;
    }
    if (maxim == 1){
        startPosition = 0;
        endPosition = 0;
    }
    else{
        startPosition = startMaxim;
        endPosition = startMaxim + maxim - 1;
    }
}