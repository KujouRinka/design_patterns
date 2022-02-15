#ifndef DATA_STRUCTURES_AND_ALGORITHM_PRODUCT_H
#define DATA_STRUCTURES_AND_ALGORITHM_PRODUCT_H

class AbstractProductA {
public:
    virtual void interfaceA() = 0;
};

class ProductA1 : public AbstractProductA {
public:
    void interfaceA() override;
};

class ProductA2 : public AbstractProductA {
private:
    void interfaceA() override;
};

class AbstractProductB {
public:
    virtual void interfaceB() = 0;
};

class ProductB1 : public AbstractProductB {
public:
    void interfaceB() override;
};

class ProductB2 : public AbstractProductB {
public:
    void interfaceB() override;
};

#endif //DATA_STRUCTURES_AND_ALGORITHM_PRODUCT_H
