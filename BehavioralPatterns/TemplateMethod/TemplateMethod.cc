#include "TemplateMethod.h"

void Parent::templateMethod() {
    // do something ...
    primitiveOperation1();
    // do something ...
    primitiveOperation2();
    hookOperation();
    // do something ...
}

void Child::primitiveOperation1() {
    // overwrite some operation
}

void Child::primitiveOperation2() {
    // overwrite some operation
}

void Child::hookOperation() {
    // do some hook operation
}
