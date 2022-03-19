#include "Entity.h"
Entity::Entity() {
    this->parteImaginara = 0;
    this->parteReala = 0;
}
Entity::Entity(int parteReala, int parteImaginara) {
    this->parteReala = parteReala;
    this->parteImaginara = parteImaginara;
}

Entity::Entity(const Entity &number) {
    this->parteImaginara = number.parteImaginara;
    this->parteReala = number.parteReala;
}

Entity::~Entity() {
    this->parteReala = 0;
    this->parteImaginara = 0;
}

int Entity::getParteImaginara() {
    return this->parteImaginara;
}

int Entity::getParteReala() {
    return this->parteReala;
}

void Entity::setParteImaginara(int parteImaginaraNoua) {
    this->parteImaginara = parteImaginaraNoua;
}

void Entity::setParteReala(int parteRealaNoua) {
    this->parteReala = parteRealaNoua;
}

Entity& Entity::operator=(const Entity &number) {
    this->parteImaginara = number.parteImaginara;
    this->parteReala = number.parteReala;
    return *this;
}

bool Entity::operator==(const Entity &number) {
    return (this->parteReala == number.parteReala and
    this->parteImaginara == number.parteImaginara);
}


