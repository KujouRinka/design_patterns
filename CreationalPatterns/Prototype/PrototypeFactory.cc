#include "PrototypeFactory.h"

PrototypeFactory::PrototypeFactory(PrototypeA *pa, PrototypeB *pb)
        : _pa(pa), _pb(pb) {

}
PrototypeA *PrototypeFactory::createPTA() {
    return _pa->clone();
}
PrototypeB *PrototypeFactory::createPTB() {
    return _pb->clone();
}
