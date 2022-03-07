#ifndef DATA_STRUCTURES_AND_ALGORITHM_TARGET_H
#define DATA_STRUCTURES_AND_ALGORITHM_TARGET_H


class Target {
public:
    virtual void request1() = 0;
    virtual void request2() = 0;
};

class ConcreteTarget : Target {
public:
    void request1() override;
    void request2() override;
};


#endif //DATA_STRUCTURES_AND_ALGORITHM_TARGET_H
