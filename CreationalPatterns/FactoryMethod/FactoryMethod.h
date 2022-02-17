#ifndef DATA_STRUCTURES_AND_ALGORITHM_FACTORYMETHOD_H
#define DATA_STRUCTURES_AND_ALGORITHM_FACTORYMETHOD_H

#include <string>

#include "Product.h"

class FactoryMethod {
public:
    // we could also do some default
    // operation here but not necessary.
    virtual Product *createProduct() { return nullptr; }
    virtual Product *createProductByName(const std::string &name) { return nullptr; }
    virtual void doOperation1() {}
    virtual void doOperation2() {}
    virtual void doOperation3() {}
};

class ConcreteMethod1 : public FactoryMethod {
public:
    // overwrite method interested
    Product *createProduct() override;
    void doOperation1() override;
};

class ConcreteMethod2 : public FactoryMethod {
public:
    Product *createProduct() override;
};

class ConcreteMethod3 : public FactoryMethod {
public:
    Product * createProductByName(const std::string &name) override;
    void doOperation1() override;
    void doOperation2() override;
};

#endif //DATA_STRUCTURES_AND_ALGORITHM_FACTORYMETHOD_H
