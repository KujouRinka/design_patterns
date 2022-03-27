#ifndef DATA_STRUCTURES_AND_ALGORITHM_FLYWEIGHT_H
#define DATA_STRUCTURES_AND_ALGORITHM_FLYWEIGHT_H

#include <unordered_map>

class Flyweight;
typedef int KeyType;

class FlyweightFactory {    // could be implemented as singleton
public:
    Flyweight *getConcrete(KeyType key);
    Flyweight *getUnshared(KeyType key);

public:
    std::unordered_map<KeyType, Flyweight *> _flyweights;
};

class Flyweight {
public:
    virtual void operation() = 0;
};

class ConcreteFlyweight : public Flyweight {
public:
    ConcreteFlyweight() = default;

    void operation() override;
};

class UnsharedConcreteFlyweight : public Flyweight {
public:
    UnsharedConcreteFlyweight() = default;

    void operation() override;
};

#endif //DATA_STRUCTURES_AND_ALGORITHM_FLYWEIGHT_H
