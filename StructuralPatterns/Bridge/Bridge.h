#ifndef DATA_STRUCTURES_AND_ALGORITHM_BRIDGE_H
#define DATA_STRUCTURES_AND_ALGORITHM_BRIDGE_H

class Impl;

class Bridge {
public:
    Bridge() : _impl(nullptr) {};
    virtual void interface1();
    virtual void interface2();

protected:
    Impl *getImpl();

private:
    Impl *_impl;
};

class ConcreteClass : public Bridge {
public:
    void interface1() override;
    void mySelfInterface();
};


#endif //DATA_STRUCTURES_AND_ALGORITHM_BRIDGE_H
