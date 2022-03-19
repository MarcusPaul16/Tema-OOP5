#include "Repo.h"
#include <iostream>
using namespace std;
Repo::Repo() {
    this->numberOfEntities = 0;
    this->maxCapacity = 5;
    this->entities = new Entity[maxCapacity];
}
Repo::~Repo(){
    this->numberOfEntities = 0;
    delete []this->entities;
}
void Repo::addEntity(Entity &entity){
    if (numberOfEntities == maxCapacity){
        Entity* copy;
        copy = new Entity[numberOfEntities];
        for (int i = 0; i < numberOfEntities; i++)
            copy[i] = entities[i];
        delete []this->entities;
        maxCapacity *= 2;
        this->entities = new Entity[maxCapacity];
        for (int i = 0; i < numberOfEntities; i++)
            entities[i] = copy[i];
        delete []copy;
        this->entities[numberOfEntities] = entity;
        numberOfEntities++;
    }
    else{
        entities[numberOfEntities] = entity;
        this->numberOfEntities++;
    }
}
int Repo::getSize() {
    return this->numberOfEntities;
}
Entity* Repo::getAll(){
    return this->entities;
}
void Repo::showAll() {
    Entity* ptr = entities;
    int i = 0;
    while (i < numberOfEntities){
        cout << "Entity " << i << ": ";
        cout << "Partea reala: " << ptr->getParteReala() << " ";
        cout << "Partea imaginara: " << ptr->getParteImaginara();
        cout << '\n';
        i++;
        ptr++;
    }
}

