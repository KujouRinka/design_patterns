#include "Bridge.h"
#include "Impl.h"

void Bridge::interface1() {
    // do something
}
void Bridge::interface2() {
    // do something
}
Impl *Bridge::getImpl() {
    // should use factory to init
    if (_impl == nullptr)
        _impl = ConcreteImpl::Instance();
    return _impl;
}
void ConcreteClass::interface1() {
    getImpl()->implInterface();
    // do other thing
}
void ConcreteClass::mySelfInterface() {
    getImpl()->implInterface();
    getImpl()->implInterface();
    // do other thing
}
