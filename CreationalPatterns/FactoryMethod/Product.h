#ifndef DATA_STRUCTURES_AND_ALGORITHM_PRODUCT_H
#define DATA_STRUCTURES_AND_ALGORITHM_PRODUCT_H

class Product {
public:
    virtual void Operation1() = 0;
    virtual void Operation2() = 0;
    virtual void Operation3() = 0;
};

class ConcreteProduct1 : public Product {
public:
    void Operation1() override;
    void Operation2() override;
    void Operation3() override;
};

class ConcreteProduct2 : public Product {
public:
    void Operation1() override;
    void Operation2() override;
    void Operation3() override;
};

#endif //DATA_STRUCTURES_AND_ALGORITHM_PRODUCT_H
