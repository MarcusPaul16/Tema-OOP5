#include "Test.h"
#include <cassert>
#include "Service.h"
using namespace std;
void Test::testAdaugare(){
    Repo repo;
    Entity entitate1(2, 3);
    Entity entitate2(4, 5);
    Entity entitate3(10, 10);
    Entity entitate4(20, 20);
    repo.addEntity(entitate1);
    repo.addEntity(entitate2);
    assert(repo.getSize() == 2);
    repo.addEntity(entitate3);
    assert(repo.getSize() == 3);
    repo.addEntity(entitate4);
    assert(repo.getSize() == 4);
    repo.addEntity(entitate1);
    repo.addEntity(entitate2);
    assert(repo.getSize() == 6);
}
void Test::testMaxEntity(){
    int position;
    Repo repo;
    Service service(&repo);
    Entity number1(2, 3);
    Entity number2(3, 4);
    Entity number3(5, 5);
    Entity number4(10, 10);
    Entity number5(20, 20);
    Entity number6(50, 50);
    Entity number7(10, 10);
    repo.addEntity(number1);
    repo.addEntity(number2);
    service.determinateTheBiggestEntity(position);
    assert(position == 1);
    repo.addEntity(number3);
    repo.addEntity(number4);
    repo.addEntity(number5);
    service.determinateTheBiggestEntity(position);
    assert(position == 4);
    repo.addEntity(number6);
    repo.addEntity(number7);
    service.determinateTheBiggestEntity(position);
    assert(position == 5);
}
void Test::testInUnitCircle() {
    Repo repo;
    Service service(&repo);
    Entity entitate1(1, 2);
    Entity entitate2(6, 2);
    Entity entitate3(1, 10);
    repo.addEntity(entitate1);
    assert(service.allEntitiesUnitCircle(&repo) == 0);
    repo.addEntity(entitate2);
    assert(service.allEntitiesUnitCircle(&repo) == 1);
    repo.addEntity(entitate3);
    assert(service.allEntitiesUnitCircle(&repo) == 1);
}

void Test::testAll(){
    testAdaugare();
    testMaxEntity();
    testInUnitCircle();
}
