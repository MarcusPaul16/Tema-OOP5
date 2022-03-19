#ifndef LAB5_REPO_H
#define LAB5_REPO_H
#include "Entity.h"
class Repo {
private:
    Entity* entities;
    int numberOfEntities, maxCapacity;
public:
    Repo();
    void addEntity(Entity &entity);
    int getSize();
    Entity* getAll();
    void showAll();
    ~Repo();
};
#endif