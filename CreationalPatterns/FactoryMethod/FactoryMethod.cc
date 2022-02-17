#include "FactoryMethod.h"

Product *ConcreteMethod1::createProduct() {
    return new ConcreteProduct1;
}
void ConcreteMethod1::doOperation1() {
    // do some operation
}
Product *ConcreteMethod2::createProduct() {
    return new ConcreteProduct2;
}
Product *ConcreteMethod3::createProductByName(const std::string &name) {
    if (name == "Product1")
        return new ConcreteProduct1;
    else if (name == "Product2")
        return new ConcreteProduct2;
    return FactoryMethod::createProduct();
}
void ConcreteMethod3::doOperation1() {

}
void ConcreteMethod3::doOperation2() {

}
