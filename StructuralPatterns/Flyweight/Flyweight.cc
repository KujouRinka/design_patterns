#include "Flyweight.h"

Flyweight *FlyweightFactory::getConcrete(KeyType key) {
    if (_flyweights.count(key))
        _flyweights[key] = new ConcreteFlyweight;
    return _flyweights[key];
}

Flyweight *FlyweightFactory::getUnshared(KeyType key) {
    // generate Flyweight according to key
    return new UnsharedConcreteFlyweight;
}

void ConcreteFlyweight::operation() {
    // do something
}

void UnsharedConcreteFlyweight::operation() {
    // do something
}
