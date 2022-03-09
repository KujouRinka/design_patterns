#ifndef DATA_STRUCTURES_AND_ALGORITHM_IMPL_H
#define DATA_STRUCTURES_AND_ALGORITHM_IMPL_H

class Impl {
public:
    virtual void implInterface() = 0;
    // ...
};

class ConcreteImpl : public Impl {
public:
    static Impl *Instance();
    void implInterface() override;

private:
    ConcreteImpl() = default;
};


#endif //DATA_STRUCTURES_AND_ALGORITHM_IMPL_H
