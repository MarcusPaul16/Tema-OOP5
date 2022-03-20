#ifndef LAB5_SERVICE_H
#define LAB5_SERVICE_H
#include "Entity.h"
#include "Repo.h"
class Service {
private:
    Repo* repo;
public:
    Service(Repo* repo);
    ~Service();
    double module(Entity);
    bool inUnitCircle(Entity entity);
    void addEntity(Entity entity);
    Entity* getAll();
    int allEntitiesUnitCircle();
    void determinateTheBiggestEntity(int &position);
    void determinateTheLongestSubsequence(short &startPosition, short &endPosition);
    void showSubsequence(short, short);
    short getSize();
};


#endif //LAB5_SERVICE_H
