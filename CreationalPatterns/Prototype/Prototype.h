#ifndef DATA_STRUCTURES_AND_ALGORITHM_PROTOTYPE_H
#define DATA_STRUCTURES_AND_ALGORITHM_PROTOTYPE_H

class PrototypeA {
public:
    virtual PrototypeA *clone() = 0;
    virtual void actionA() = 0;
};

class PrototypeB {
public:
    virtual PrototypeB *clone() = 0;
    virtual void actionB() = 0;
};

class ConcretePrototypeA1 : public PrototypeA {
public:
    ConcretePrototypeA1() = default;
    ConcretePrototypeA1(const ConcretePrototypeA1 &) { /* do something */ }
    PrototypeA *clone() override;

    void actionA() override;
};

class ConcretePrototypeA2 : public PrototypeA {
public:
    ConcretePrototypeA2() = default;
    ConcretePrototypeA2(const ConcretePrototypeA2 &) {}
    PrototypeA *clone() override;

    void actionA() override;
};

class ConcretePrototypeB1 : public PrototypeB {
public:
    ConcretePrototypeB1() = default;
    ConcretePrototypeB1(const ConcretePrototypeB1 &) {}
    PrototypeB *clone() override;

    void actionB() override;
};

class ConcretePrototypeB2 : public PrototypeB {
public:
    ConcretePrototypeB2() = default;
    ConcretePrototypeB2(const ConcretePrototypeB2 &) {}
    PrototypeB *clone() override;

    void actionB() override;
};

#endif //DATA_STRUCTURES_AND_ALGORITHM_PROTOTYPE_H
