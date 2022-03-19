#include "Service.h"
#include <cmath>
#include "Repo.h"
using namespace std;
Service::Service(Repo* repo) {
    this->repo = repo;
}
Service::~Service() {}
double Service::module(Entity entity){
    double module = sqrt(entity.getParteImaginara()*entity.getParteImaginara() + entity.getParteReala()*entity.getParteReala());
    return module;
}
bool Service::inUnitCircle(Entity entity){
    double tangent = atan(entity.getParteImaginara() / entity.getParteReala());
    if (tangent <= 0.5)
        return true;
    return false;
}
void Service::determinateTheBiggestEntity(int &position) {
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
int Service::allEntitiesUnitCircle(Repo *repo) {
    Entity *p = this->repo->getAll();
    int count = 0;
    for (int i = 0 ; i < this->repo->getSize(); i++){
        if (inUnitCircle(p[i]))
            count++;
    }
    return count;
}
void Service::determinateTheLongestSubsequence(Repo *repo, short &startPosition, short &endPosition) {
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