#include "FactoryMethod.h"
#include "Product.h"

void example() {
    FactoryMethod *method1 = new ConcreteMethod1;
    Product *product1 = method1->createProduct();
    product1->Operation1();
    product1->Operation2();
    product1->Operation3();
    // ...

    FactoryMethod *method3 = new ConcreteMethod3;
    Product *product3 = method3->createProductByName("Product1");
    product3->Operation1();
    // ...
}