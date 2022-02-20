#ifndef DATA_STRUCTURES_AND_ALGORITHM_PROTOTYPEFACTORY_H
#define DATA_STRUCTURES_AND_ALGORITHM_PROTOTYPEFACTORY_H

#include "AbstractFactory.h"
#include "Prototype.h"

// supposing that abstract factory has implemented
// some interface of constructing function.

class PrototypeFactory : public AbstractFactory {
public:
    PrototypeFactory(PrototypeA *pa = new ConcretePrototypeA1,
                     PrototypeB *pb = new ConcretePrototypeB1);
    PrototypeA *createPTA() override;    // interface
    PrototypeB *createPTB() override;    // interface

private:
    PrototypeA *_pa;
    PrototypeB *_pb;
};

#endif //DATA_STRUCTURES_AND_ALGORITHM_PROTOTYPEFACTORY_H
