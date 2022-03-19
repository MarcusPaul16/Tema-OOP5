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
    int allEntitiesUnitCircle(Repo* repo);
    void determinateTheBiggestEntity(int &position);
    void determinateTheLongestSubsequence();
};


#endif //LAB5_SERVICE_H
