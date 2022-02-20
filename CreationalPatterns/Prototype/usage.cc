#include "PrototypeFactory.h"
#include "Prototype.h"

void createSomeThings(AbstractFactory *factory) {
    factory->createPTA();
    // ...
    factory->createPTB();
    // ...
}

void example() {
    AbstractFactory *PTFactory1 =
            new PrototypeFactory(new ConcretePrototypeA1, new ConcretePrototypeB1);
    createSomeThings(PTFactory1);
    AbstractFactory *PTFactory2 =
            new PrototypeFactory(new ConcretePrototypeA2, new ConcretePrototypeB2);
    createSomeThings(PTFactory2);
}
