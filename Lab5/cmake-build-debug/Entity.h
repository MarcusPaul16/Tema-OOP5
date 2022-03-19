#ifndef LAB5_ENTITY_H
#define LAB5_ENTITY_H


class Entity {
private:
    int parteReala, parteImaginara;
public:
    Entity();
    Entity(int, int);
    Entity(const Entity &s);
    void setParteReala(int);
    void setParteImaginara(int);
    int getParteReala();
    int getParteImaginara();
    ~Entity();
    Entity &operator=(const Entity &number);
    bool operator==(const Entity &number);
};


#endif //LAB5_ENTITY_H
