#include "Prototype.h"

PrototypeA *ConcretePrototypeA1::clone() {
    return new ConcretePrototypeA1(*this);
}
void ConcretePrototypeA1::actionA() {

}
PrototypeA *ConcretePrototypeA2::clone() {
    return new ConcretePrototypeA2(*this);
}
void ConcretePrototypeA2::actionA() {

}
PrototypeB *ConcretePrototypeB1::clone() {
    return new ConcretePrototypeB1(*this);
}
void ConcretePrototypeB1::actionB() {

}
PrototypeB *ConcretePrototypeB2::clone() {
    return new ConcretePrototypeB2(*this);
}
void ConcretePrototypeB2::actionB() {

}
