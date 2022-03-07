#ifndef DATA_STRUCTURES_AND_ALGORITHM_ADAPTEE_H
#define DATA_STRUCTURES_AND_ALGORITHM_ADAPTEE_H

class Adaptee {
public:
    virtual void specialReq() = 0;
};

class ConcreteAdaptee : Adaptee {
public:
    void specialReq() override;
};

#endif //DATA_STRUCTURES_AND_ALGORITHM_ADAPTEE_H
