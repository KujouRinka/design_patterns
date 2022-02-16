//
// Created by kujourinka on 2/16/22.
//

#include "Builder.h"

// do something for _obj
void ConcreteBuilder1::buildComp1() {

}
void ConcreteBuilder1::buildComp2() {

}
ConcreteBuilder1::product1_t *ConcreteBuilder1::getObj() {
    return _obj;
}
void ConcreteBuilder2::buildComp1() {

}
void ConcreteBuilder2::buildComp2() {

}
void ConcreteBuilder2::buildComp3() {

}
ConcreteBuilder2::product2_t *ConcreteBuilder2::getObj() {
    return _obj;
}
