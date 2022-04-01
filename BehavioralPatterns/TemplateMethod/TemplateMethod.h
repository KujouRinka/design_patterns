#ifndef DATA_STRUCTURES_AND_ALGORITHM_TEMPLATEMETHOD_H
#define DATA_STRUCTURES_AND_ALGORITHM_TEMPLATEMETHOD_H

class Parent {
public:
    void templateMethod();

protected:
    virtual void primitiveOperation1() = 0;
    virtual void primitiveOperation2() = 0;

    virtual void hookOperation() {};
};

class Child : public Parent {
public:
    Child() = default;

protected:
    void primitiveOperation1() override;
    void primitiveOperation2() override;

    void hookOperation() override;
};


#endif //DATA_STRUCTURES_AND_ALGORITHM_TEMPLATEMETHOD_H
