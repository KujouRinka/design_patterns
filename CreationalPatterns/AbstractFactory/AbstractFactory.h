#ifndef DATA_STRUCTURES_AND_ALGORITHM_ABSTRACTFACTORY_H
#define DATA_STRUCTURES_AND_ALGORITHM_ABSTRACTFACTORY_H

#include "Product.h"

class AbstractFactory {
public:
    virtual AbstractProductA *createProductA() = 0;
    virtual AbstractProductB *createProductB() = 0;
};

class ConcreteFactory1 : public AbstractFactory {
public:
    AbstractProductA *createProductA() override;
    AbstractProductB *createProductB() override;
};

class ConcreteFactory2 : public AbstractFactory {
public:
    AbstractProductA *createProductA() override;
    AbstractProductB *createProductB() override;
};

class Client;

#endif //DATA_STRUCTURES_AND_ALGORITHM_ABSTRACTFACTORY_H
