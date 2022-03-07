#include "AdapterInher.h"
#include "../Composition/AdapterComp.h"

AdapterInher::AdapterInher() : ConcreteAdaptee() {
    // do something
}
void AdapterInher::request1() {
    ConcreteAdaptee::specialReq();
}
void AdapterComp::request2() {
    // do something
}
